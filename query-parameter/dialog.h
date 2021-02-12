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
    QLineEdit   *leParamValue;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *hlAcceptBtn;
      QSpacerItem *horizontalSpacerLeft;
      QPushButton *btnAccept;
      //QSpacerItem *horizontalSpacerRight;
    QString  sDataType;
    QString  sDataMask;
    unsigned int uWidth;
    unsigned int uHeight;
  public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void SetMessageText(const char* msg);
    void SetWindowTitle(const char* title);
    void SetAcceptButtonText(const char* txt);
    void SetDataType(const char* dtype);
    void SetDataMask(const char* dmask);
    void SwitchOnValidator();
    void SetSizeX(const int sx);
    void SetSizeY(const int sy);
  public slots:
    void BtnAcceptClicked();
};
#endif // DIALOG_H
