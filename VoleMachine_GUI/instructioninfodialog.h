#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class InstructionInfoDialog : public QDialog {
    Q_OBJECT

public:
    explicit InstructionInfoDialog(QWidget *parent = nullptr);

private:
    void setupUi();
};
