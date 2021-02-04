#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QApplication>

class Dialog : public QDialog
{
  Q_OBJECT

  private:
    QVBoxLayout *verticalLayout;
    QLabel      *label;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacerLeft;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacerRight;
    unsigned int uWidth;
    unsigned int uHeight;

  public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void SetMessageText(const char* msg);
    void SetWindowTitle(const char* title);
    void SetButtonText(const char* txt);
    void SetSizeX(const unsigned int sx);
    void SetSizeY(const unsigned int sy);
};
#endif // DIALOG_H
