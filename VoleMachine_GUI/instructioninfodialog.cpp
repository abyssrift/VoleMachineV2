#include "InstructionInfoDialog.h"

InstructionInfoDialog::InstructionInfoDialog(QWidget *parent) : QDialog(parent) {
    setupUi();
}

void InstructionInfoDialog::setupUi() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Customize color and style
    this->setStyleSheet(
        "background-color:white;"
        "color: black;"
        "font-size: 14px;"
        "font-family: Consolas, monospace;"
        "width: 500px;"
        "height: 700px;"
        "border: 1px solid #a5d6a7;"
        "border-radius: 8px;"
        );

    // Instruction information
    QLabel *instructionLabel = new QLabel(this);
    instructionLabel->setText("<h2 style='text-align:center; color:#333;'>Operations Set</h2>"
                              "<table style='border-collapse:collapse; width:100%; font-size:12px;'>"
                              "<tr><th style='padding:4px; border:1px solid #666;'>Opc.</th>"
                              "<th style='padding:4px; border:1px solid #666;'>Opr.</th>"
                              "<th style='padding:4px; border:1px solid #666;'>Effect</th></tr>"
                              "<tr><td style='padding:4px; border:1px solid #666;'>1</td><td>RXY</td><td>Copy the content of RAM cell XY to register R.</td></tr>"
                              "-----------------------------------------------------"
                              "<tr><td style='padding:4px; border:1px solid #666;'>2</td><td>RXY</td><td>Copy the bit-string XY to register R.</td></tr>"
                                "-----------------------------------------------------"
                              "<tr><td style='padding:4px; border:1px solid #666;'>3</td><td>RXY</td><td>Copy the content of register R to RAM cell XY.</td></tr>"
                              "-----------------------------------------------------"
                              "<tr><td style='padding:4px; border:1px solid #666;'>4</td><td>xRS</td><td>Copy the content of register R to register S.</td></tr>"
                              "-----------------------------------------------------"
                              "<tr><td style='padding:4px; border:1px solid #666;'>5</td><td>RST</td><td>Add the content of register S and register T, and put the result in register R. Data is interpreted as integers in two's-complement notation.</td></tr>"
                              "-----------------------------------------------------"
                              "<tr><td style='padding:4px; border:1px solid #666;'>6</td><td>RST</td><td>Add the content of register S and register T, and put the result in register R. Data is interpreted as floats in floating-point notation.</td></tr>"
                              "-----------------------------------------------------"
                              "<tr><td style='padding:4px; border:1px solid #666;'>7</td><td>RST</td><td>Bitwise OR (∨) the content of register S and T, and put the result in register R.</td></tr>"
                              "-----------------------------------------------------"
                              "<tr><td style='padding:4px; border:1px solid #666;'>8</td><td>RST</td><td>Bitwise AND (∧) the content of register S and T, and put the result in register R.</td></tr>"
                              "-----------------------------------------------------"
                              "<tr><td style='padding:4px; border:1px solid #666;'>9</td><td>RST</td><td>Bitwise XOR (⊕) the content of register S and T, and put the result in register R.</td></tr>"
                              "-----------------------------------------------------"
                              "<tr><td style='padding:4px; border:1px solid #666;'>A</td><td>RxX</td><td>Rotate the content of register R cyclically right X steps.</td></tr>"
                              "-----------------------------------------------------"
                              "<tr><td style='padding:4px; border:1px solid #666;'>B</td><td>RXY</td><td>Jump to instruction in RAM cell XY if the content of register R equals the content of register 0.</td></tr>"
                              "-----------------------------------------------------"
                              "<tr><td style='padding:4px; border:1px solid #666;'>C</td><td>xxx</td><td>Halt execution.</td></tr>"
                              "-----------------------------------------------------"
                              "<tr><td style='padding:4px; border:1px solid #666;'>D</td><td>RXY</td><td>Jump to instruction in RAM cell XY if the content of register R is greater than (>) the content of register 0. Data is interpreted as integers in two's-complement notation.</td></tr>"
                              "-----------------------------------------------------"
                              "</table>");
    instructionLabel->setStyleSheet("font-size: 14px; padding: 5px;"
                                    "background-color:#e8f5e9;"
                                    "color: #2e7d32;"
                                    "font-size: 14px;"
                                    "font-family: Consolas, monospace;"
                                    "border: 1px solid #a5d6a7;"
                                    "border-radius: 8px;");
    instructionLabel->setWordWrap(true);

    layout->addWidget(instructionLabel);

    // Close button
    QPushButton *closeButton = new QPushButton("Close", this);
    closeButton->setStyleSheet(
        "background-color: rgb(100, 100, 247);"
        "color: wheat;"
        "border-radius: 5px;"
        "height: 30px;"
        "width: 80px;"
        );
    connect(closeButton, &QPushButton::clicked, this, &InstructionInfoDialog::close);

    layout->addWidget(closeButton);
    layout->setAlignment(closeButton, Qt::AlignCenter);
}
