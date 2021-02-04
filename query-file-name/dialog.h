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
    QString  sFileMask;
    QString  sBaseDir;
    unsigned int uWidth;
    unsigned int uHeight;
  public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void SetMessageText(const char* msg);
    void SetWindowTitle(const char* title);
    void SetAcceptButtonText(const char* txt);
    void SetFileMask(const char* fmask);
    void SetBaseDirectory(const char* bdir);
    void SetSizeX(const unsigned int sx);
    void SetSizeY(const unsigned int sy);
  public slots:
    void QueryFileDlg();
    void BtnAcceptClicked();
};
#endif // DIALOG_H
