#include <mainwindow.h>
#include <QTextCursor>
#include <QTextBlockFormat>
#include <QRegularExpression>


MainWindow::MainWindow(Machine& machine,CPU& cpu2, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), initialisedMachine(machine),cpu(cpu2){
    ui->setupUi(this);
    ui->Instructions_Result->setVisible(false);
    ui->Running_Errors->setVisible(false);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::callonecycle);
    RefreshUI();
    QMenu *helpMenu = menuBar()->addMenu("Help");
    QMenu *fileMenu = menuBar()->addMenu("Files");

    // Actions for importing and exporting files
    QAction *txtFileActionImport = new QAction("Import", this);
    QAction *txtFileActionExport = new QAction("Export", this);

    // Action for the instruction help
    QAction *InstructionsHelpAction = new QAction("Instruction Help", this);

    // Add actions to the appropriate menus
    fileMenu->addAction(txtFileActionImport);
    fileMenu->addAction(txtFileActionExport);
    helpMenu->addAction(InstructionsHelpAction);

    // Connect the actions to their respective slots
    connect(txtFileActionImport, &QAction::triggered, this, &MainWindow::importFile);
    connect(txtFileActionExport, &QAction::triggered, this, &MainWindow::createFileWithUserName);
    connect(InstructionsHelpAction, &QAction::triggered, this, &MainWindow::DisplayHelp);


    QTextEdit* textEdit = findChild<QTextEdit*>("Screen"); // Replace with the object name of your QTextEdit
    if (textEdit) {
        qDebug() << "Text Found";
        QTextCursor cursor = textEdit->textCursor();
        cursor.select(QTextCursor::Document); // Select all text
        QTextBlockFormat format;
        format.setAlignment(Qt::AlignCenter); // Center alignment
        cursor.mergeBlockFormat(format); // Apply the format
        textEdit->setTextCursor(cursor); // Update QTextEdit
    }
}


int speed = 1;

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::importFile() {
    vector<string> instructions;
    vector<string> instructionscleaned;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Text File"), "", tr("Text Files (*.txt);;All Files (*)"));

    if (!fileName.isEmpty()) {
        std::ifstream file(fileName.toStdString());
        if (!file.is_open()) {
            QMessageBox::warning(this, tr("Error"), tr("Could not open file for reading."));
            return;
        }

        std::stringstream buffer;
        buffer << file.rdbuf();
        file.close();

        QString fileContent = QString::fromStdString(buffer.str());

        if(fileContent != ""){
            QString cleanedText;
            for (const QChar &ch : fileContent) {
                if (ch != '\n') {
                    cleanedText += ch;
                }
            }
            if(!(cleanedText.size()%4 == 0)){
                InstructionError("Incorrect Syntax, try again");
                return;
            }
            for (int i = 0; i < cleanedText.size(); i+=4) {
                QString Segment = cleanedText.mid(i,4);
                std::string Segments = Segment.toStdString();
                instructions.push_back(Segments);
            }

            for (int i = 0; i < instructions.size(); ++i) {
                instructionscleaned.push_back(instructions[i].substr(0,2));
                instructionscleaned.push_back(instructions[i].substr(2,4));
            }
            for (int i = 0; i < instructionscleaned.size(); i += 2) {
                int targetAddress = i + 2;  // Start writing from memory address 1 instead of 0

                initialisedMachine.SetMainMemoryValue(targetAddress, instructionscleaned[i]);
                initialisedMachine.SetMainMemoryValue(targetAddress + 1, instructionscleaned[i + 1]);

                qDebug() << targetAddress << " " << targetAddress + 1;
            }

            ui->Instructions_Result->setStyleSheet("QLabel { color : green;}");
            ui->Instructions_Result->setText("Instrutions Saved Successfully");
            ui->Instructions_Result->setVisible(true);
            ui->ManualInstruBox->setText("");
            RefreshUI();
        }
    }
}

void MainWindow::createFileWithUserName() {
    // Ask the user for a filename using a file dialog
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt);;All Files (*)");

    // Check if the user provided a filename
    if (fileName.isEmpty()) {
        QMessageBox::warning(this, "Warning", "No filename provided. File creation canceled.");
        return;
    }

    // Create an fstream object
    std::fstream file;
    // Open the file for writing
    file.open(fileName.toStdString(), std::ios::out);
    for (int i = 0; i < 255; i+=2) {
        file << cpu.GetMemoryValue(i) << cpu.GetMemoryValue(i+1) << endl;
    }
    file << "This File Was Created By The James Volt Machine" << endl;
    // Close the file
    file.close();

    // Inform the user that the file was created successfully
    QMessageBox::information(this, "Success", "File created successfully: " + fileName);
}


void MainWindow::RefreshUI(){
    ui->Register16_output->setText(initialisedMachine.Getregister_16());
    ui->Memory_output->setText(initialisedMachine.Getmemory_16());
}

void MainWindow::on_pushButton_3_clicked()
{
    initialisedMachine.ResetRegisters();
    ui->Register16_output->setText(initialisedMachine.Getregister_16());
    cpu.ResetCounter();
    timer->stop();
}

void MainWindow::InstructionError(QString message){

    ui->Instructions_Result->setStyleSheet("QLabel {color: red;}");
    ui->Instructions_Result->setText(message);
    ui->Instructions_Result->setVisible(true);
}

void MainWindow::on_Enter_btn_clicked()
{
    vector<string> instructions;
    vector<string> instructionscleaned;
    QString inputText = ui->ManualInstruBox->toPlainText();
    qDebug() << inputText;
    if(inputText != ""){
        QString cleanedText;
        for (const QChar &ch : inputText) {
            if (ch != '\n') {
                cleanedText += ch;
            }
        }
        if(!(cleanedText.size()%4 == 0)){
            InstructionError("Incorrect Syntax, try again");
            return;
        }
        for (int i = 0; i < cleanedText.size(); i+=4) {
            QString Segment = cleanedText.mid(i,4);
            std::string Segments = Segment.toStdString();
            instructions.push_back(Segments);
        }

        for (int i = 0; i < instructions.size(); ++i) {
            instructionscleaned.push_back(instructions[i].substr(0,2));
            instructionscleaned.push_back(instructions[i].substr(2,4));
        }
        for (int i = 0; i < instructionscleaned.size(); i += 2) {
            int targetAddress = i + 2;  // Start writing from memory address 1 instead of 0

            initialisedMachine.SetMainMemoryValue(targetAddress, instructionscleaned[i]);
            initialisedMachine.SetMainMemoryValue(targetAddress + 1, instructionscleaned[i + 1]);
        }

        ui->Instructions_Result->setStyleSheet("QLabel { color : green;}");
        ui->Instructions_Result->setText("Instrutions Saved Successfully");
        ui->Instructions_Result->setVisible(true);
        ui->ManualInstruBox->setText("");
    }
    else{
    InstructionError("You Need to input Instrutions");
    }
}


void highlightText(QTextEdit *textEdit, const QString &text, const QString &highlightedSubstring) {
    textEdit->setPlainText(text);
    QTextCursor cursor = textEdit->textCursor();
    cursor.setPosition(0, QTextCursor::MoveAnchor);
    QTextCharFormat fmt;
    fmt.setBackground(Qt::yellow);

    while (!cursor.isNull() && !cursor.atEnd()) {
        cursor = textEdit->document()->find(highlightedSubstring, cursor);
        if (!cursor.isNull()) {
            cursor.mergeCharFormat(fmt);
        }
    }
}


void MainWindow::DisplayRegisterComparison(const QString& highlightedSubstring) {
highlightText(ui->Register16_output, ui->Register16_output->toPlainText(), highlightedSubstring);
}
void MainWindow::DisplayMemory(const QString& message){
    ui->Memory_output->setText(message);
    qDebug() << "Displayed Memory On UI";
}
void MainWindow::DisplayRegister_16(const QString& message){
    ui->Register16_output->setText(message);
    qDebug() << "Displayed Registers On UI";
}

void MainWindow::DisplayInstruReg(const QString& message) {
    ui->InstructionRegister_Label->setText("InstructionReg<br>" + message);
}

void MainWindow::DisplayProgramCounter(const QString& message){
    ui->Program_Counter_Label->setText("Counter<br>" + message);
}

void MainWindow::on_pushButton_2_clicked()
{
    initialisedMachine.ResetMemory();
    ui->Memory_output->setText(initialisedMachine.Getmemory_16());
    ui->Running_Errors->setVisible(false);
    ui->Program_Counter_Label->setText("Counter<br>00");
    ui->InstructionRegister_Label->setText("InstructionReg<br>0000");
    CanRun = true;
}

void MainWindow::callonecycle(){
    if(CanRun){
    initialisedMachine.OneCycle();
        if(initialisedMachine.GetScreenMemory() != "00"){
        ui->Screen->setText(QString::fromStdString(initialisedMachine.GetScreenMemory()));
        }
    }
    else{
        ui->Running_Errors->setText("Memory limit Reached, Reset Memory");
        ui->Running_Errors->setStyleSheet("QLabel{color:red;}");
        ui->Running_Errors->setVisible(true);
    }
}

void MainWindow::on_OneStep_btn_clicked()
{
    callonecycle();
}


void MainWindow::on_pushButton_clicked()
{
    speed = 500;
    if(Running){
        timer->stop();
        timer->start(speed);
    }
    ui->Current_Speed->setText("Current Speed : 0.1x");
}


void MainWindow::on_pushButton_4_clicked()
{
    speed = 200;
    if(Running){
        timer->stop();
        timer->start(speed);
    }
    ui->Current_Speed->setText("Current Speed : 0.25x");
}


void MainWindow::on_point5speedbutton_clicked()
{
    speed = 100;
    if(Running){
        timer->stop();
        timer->start(speed);
    }
    ui->Current_Speed->setText("Current Speed : 0.5x");
}


void MainWindow::on_pushButton_6_clicked()
{
    speed = 1;
    if(Running){
        timer->stop();
        timer->start(speed);
    }
    ui->Current_Speed->setText("Current Speed : 1x");
}

void MainWindow::StopTimer(){
    timer->stop();
    CanRun = false;
}
void MainWindow::on_run_btn_clicked()
{
    ui->Instructions_Result->setVisible(false);
    if (!Running) {
        // Start the timer
        if(CanRun){        timer->start(speed);
            Running = true;

            // Change button text and style to indicate running state
            ui->run_btn->setText("Stop");
            ui->run_btn->setStyleSheet(
                "QPushButton {"
                "    background-color: red;"
                "    color: wheat;"
                "    border-radius: 10px;"
                "    width: 100px;"
                "    height: 50px;"
                "}"
                "QPushButton:hover {"
                "    opacity: 0.4;"
                "}"
                "QPushButton:pressed {"
                "    background-color: rgb(32, 32, 168);"
                "}"
                );}
        else{
            ui->Running_Errors->setText("Memory limit Reached, Reset Memory");
            ui->Running_Errors->setStyleSheet("QLabel{color:red;}");
            ui->Running_Errors->setVisible(true);
        }
    } else {
        // Stop the timer
        timer->stop();
        Running = false;
        // Change button text and style to indicate stopped state
        ui->run_btn->setText("Run");
        ui->run_btn->setStyleSheet(
            "QPushButton {"
            "    background-color: rgb(100, 100, 247);"
            "    color: wheat;"
            "    border-radius: 10px;"
            "    width: 100px;"
            "    height: 50px;"
            "}"
            "QPushButton:hover {"
            "    opacity: 0.4;"
            "}"
            "QPushButton:pressed {"
            "    background-color: rgb(32, 32, 168);"
            "}"
            );
    }
}

void MainWindow::ProcessAndDisplayUnusedInstructions(std::vector<std::string> unusedinstructions) {
    for (int i = 0; i < unusedinstructions.size(); ++i) {
        if (unusedinstructions[i] == "0000") {
            continue;
        }

        // Check if unusedinstructions[i] is already in UsedInstructionForCompiler
        auto it = std::find(UsedInstructionForCompiler.begin(), UsedInstructionForCompiler.end(), unusedinstructions[i]);
        if (it == UsedInstructionForCompiler.end()) {
            // If instruction is not found in UsedInstructionForCompiler, process it
            QString errorText = ui->Console->toHtml() + "<span style='color:red;'>ERROR! in Instruction: " +
                                QString::fromStdString(unusedinstructions[i]) +
                                ", Unassociated with a function, refer to the help tab!</span><br><br>";
            ui->Console->setHtml(errorText);

            // Add the instruction to UsedInstructionForCompiler to avoid future duplicates
            UsedInstructionForCompiler.push_back(unusedinstructions[i]);
        }
    }
}


void MainWindow::DisplayHelp(){
    InstructionInfoDialog dialog(this);
    dialog.exec();
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->Screen->setText("");
    ui->Console->setText("");

}


void MainWindow::on_pushButton_7_clicked()
{
    cpu.ResetCounter();
}

