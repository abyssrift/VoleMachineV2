#ifndef ANIMATEDBUTTON_H
#define ANIMATEDBUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>

class AnimatedButton : public QPushButton {
    Q_OBJECT
public:
    AnimatedButton(QWidget *parent = nullptr);

protected:
    void enterEvent(QEvent *event) override;
    void leaveEvent(QEvent *event) override;

private:
    QPropertyAnimation *animation;
};

#endif // ANIMATEDBUTTON_H
