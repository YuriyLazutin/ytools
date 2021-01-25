#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QApplication>

//#include <QtCore/QVariant>
//
//#include <QtWidgets/QDialog>

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

  public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
};
#endif // DIALOG_H
