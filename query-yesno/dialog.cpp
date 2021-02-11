#include "dialog.h"
#include <QFileDialog>
#include <QTextStream>

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    setObjectName(QString::fromUtf8("Dialog"));
    setMinimumSize(QSize(270, 120));
    uWidth = 270;
    uHeight = minimumHeight();
    resize(uWidth, uHeight);
    QSizePolicy szPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    szPolicy.setHorizontalStretch(0);
    szPolicy.setVerticalStretch(0);
    szPolicy.setHeightForWidth(sizePolicy().hasHeightForWidth());
    setSizePolicy(szPolicy);
    setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.5, fx:0.5, fy:0.5, stop:0 rgba(190, 200, 210, 255), stop:1 rgba(160, 200, 190, 223));"));

    // Add vertical layout
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

    // Create first horizontal layout (Question Group)
    hlQuestionGr = new QHBoxLayout();
    hlQuestionGr->setObjectName(QString::fromUtf8("hlQuestionGr"));

      // Add Morpheus
      morpheus = new QLabel(this);
      morpheus->setObjectName(QString::fromUtf8("morpheus"));
      morpheus->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
      morpheus->setAlignment(Qt::AlignCenter);
      morpheus->resize(QSize(0, 0));
      hlQuestionGr->addWidget(morpheus);
      // Add spacer
      hsSpacer11 = new QSpacerItem(20, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);
      hlQuestionGr->addItem(hsSpacer11);
      // Add question
      question = new QLabel(this);
      question->setObjectName(QString::fromUtf8("question"));
      question->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
      question->setAlignment(Qt::AlignJustify);
      //question->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
      //question->setWordWrap(true);
      //question->setScaledContents(true);
      hlQuestionGr->addWidget(question);
      // Add spacer
      hsSpacer12 = new QSpacerItem(20, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);
      hlQuestionGr->addItem(hsSpacer12);

    verticalLayout->addLayout(hlQuestionGr);
    // Add spacer
    verticalSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);
    verticalLayout->addItem(verticalSpacer);

    // Create second horizontal layout (Buttons Group)
    hlButtonsGr = new QHBoxLayout();
    hlButtonsGr->setObjectName(QString::fromUtf8("hlButtonsGr"));
      // Add spacer
      horizontalSpacerLeft = new QSpacerItem(20, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);
      hlButtonsGr->addItem(horizontalSpacerLeft);
      // Add "No" button
      btnNo = new QPushButton(this);
      btnNo->setObjectName(QString::fromUtf8("btnNo"));
      btnNo->setMinimumSize(QSize(100, 30));
      btnNo->setAutoFillBackground(false);
      btnNo->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 150, 148);"));
      btnNo->setFocusPolicy(Qt::NoFocus);
      hlButtonsGr->addWidget(btnNo);
      // Add spacer
      hsSpacer21 = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);
      hlButtonsGr->addItem(hsSpacer21);
      // Add "Yes" button
      btnYes = new QPushButton(this);
      btnYes->setObjectName(QString::fromUtf8("btnYes"));
      btnYes->setMinimumSize(QSize(100, 30));
      btnYes->setAutoFillBackground(false);
      btnYes->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 150, 148);"));
      btnYes->setFocusPolicy(Qt::NoFocus);
      hlButtonsGr->addWidget(btnYes);
      // Add spacer
      horizontalSpacerRight = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);
      hlButtonsGr->addItem(horizontalSpacerRight);


    verticalLayout->addLayout(hlButtonsGr);

    SetWindowTitle("Make your choise");
    SetQuestionText("Please select \"Yes\" or \"No\"");
    SetYesButtonText("Yes");
    SetNoButtonText("No");

    connect(btnYes, SIGNAL(clicked()), SLOT(BtnYesClicked()));
    connect(btnNo, SIGNAL(clicked()), SLOT(BtnNoClicked()));
}

Dialog::~Dialog()
{
}

void Dialog::SetQuestionText(const char* msg)
{
    question->setText(QApplication::translate("Dialog", msg, nullptr));
}

void Dialog::SetWindowTitle(const char* title)
{
    setWindowTitle(QApplication::translate("Dialog", title, nullptr));
}

void Dialog::SetYesButtonText(const char* txt)
{
    btnYes->setText(QApplication::translate("Dialog", txt, nullptr));
}

void Dialog::SetNoButtonText(const char* txt)
{
    btnNo->setText(QApplication::translate("Dialog", txt, nullptr));
}

void Dialog::SetMorpheus()
{
    QPixmap pix;
    pix.load(":/morpheus.png");
    //morpheus->setMinimumSize(pix.size());
    int minx, miny, tmpy;
    minx = minimumWidth() + pix.width() + question->width() + hsSpacer11->minimumSize().width() + hsSpacer12->minimumSize().width() + 50;
    miny = minimumHeight();
    tmpy = pix.height() + verticalSpacer->minimumSize().height() + btnYes->height() + 50;
    if (miny < tmpy)
        miny = tmpy;
    tmpy = question->height() + verticalSpacer->minimumSize().height() + btnYes->height() + 50;
    if (miny < tmpy)
        miny = tmpy;

    setMinimumSize(QSize(minx, miny));
    morpheus->resize(pix.size());
    morpheus->setPixmap(pix);
}

void Dialog::SetSizeX(const unsigned int sx)
{
    sx < minimumWidth() ? uWidth = minimumWidth() : uWidth=sx;
    resize(uWidth, uHeight);
}
void Dialog::SetSizeY(const unsigned int sy)
{
    sy < minimumHeight() ? uHeight = minimumHeight() : uHeight=sy;
    resize(uWidth, uHeight);
}

void Dialog::BtnYesClicked()
{
    QTextStream out(stdout);
    out << "Yes" << endl;
    qApp->quit();
}

void Dialog::BtnNoClicked()
{
    QTextStream out(stdout);
    out << "No" << endl;
    qApp->quit();
}
