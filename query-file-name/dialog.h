#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QHBoxLayout *hlFileName;
      QLineEdit   *leFullFileName;
      QSpacerItem *hsFileNameSpacer1;
      QPushButton *btnQueryFile;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *hlAcceptBtn;
      QSpacerItem *horizontalSpacerLeft;
      QPushButton *btnAccept;
      //QSpacerItem *horizontalSpacerRight;

  public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void SetMessageText(const char* msg);
    void SetWindowTitle(const char* title);
    void SetAcceptButtonText(const char* txt);
    void SetFileMask(const char* fmask);
};
#endif // DIALOG_H
