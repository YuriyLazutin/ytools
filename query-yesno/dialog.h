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
    QHBoxLayout *hlQuestionGr;
      QLabel      *morpheus;
      QSpacerItem *hsSpacer11;
      QLabel      *question;
      QSpacerItem *hsSpacer12;
    QSpacerItem *verticalSpacer;

    QHBoxLayout *hlButtonsGr;
      QSpacerItem *horizontalSpacerLeft;
      QPushButton *btnNo;
      QSpacerItem *hsSpacer21;
      QPushButton *btnYes;
      QSpacerItem *horizontalSpacerRight;

    unsigned int uWidth;
    unsigned int uHeight;
  public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void SetQuestionText(const char* msg);
    void SetWindowTitle(const char* title);
    void SetYesButtonText(const char* txt);
    void SetNoButtonText(const char* txt);
    void SetMorpheus();
    void SetSizeX(const unsigned int sx);
    void SetSizeY(const unsigned int sy);
  public slots:
    void BtnYesClicked();
    void BtnNoClicked();
};
#endif // DIALOG_H
