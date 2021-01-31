#include "dialog.h"
#include <QFileDialog>
//#include <iostream>
#include <QTextStream>

Dialog::Dialog(QWidget *parent) : QDialog(parent/*, Qt::WindowTitleHint | Qt::WindowSystemMenuHint*/)
{

    setObjectName(QString::fromUtf8("Dialog"));
    resize(400, 120);
    QSizePolicy szPolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    szPolicy.setHorizontalStretch(0);
    szPolicy.setVerticalStretch(0);
    szPolicy.setHeightForWidth(sizePolicy().hasHeightForWidth());
    setSizePolicy(szPolicy);
    setMinimumSize(QSize(300, 120));
    setStyleSheet(QString::fromUtf8("background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:1.5, fx:0.5, fy:0.5, stop:0 rgba(190, 200, 210, 255), stop:1 rgba(160, 200, 190, 223));"));

    // Add vertical layout
    verticalLayout = new QVBoxLayout(this);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

    // Add label
    label = new QLabel(this);
    label->setObjectName(QString::fromUtf8("label"));
    label->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
    label->setAlignment(Qt::AlignLeft);
    verticalLayout->addWidget(label);

    // Create first horizontal layout (File Name Group)
    hlFileName = new QHBoxLayout();
    hlFileName->setObjectName(QString::fromUtf8("hlFileName"));
      // Add Line Edit
      leFullFileName = new QLineEdit;
      leFullFileName->setFocus();
      hlFileName->addWidget(leFullFileName);
      // Add spacer
      hsFileNameSpacer1 = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);
      hlFileName->addItem(hsFileNameSpacer1);
      // Add "query file" button
      btnQueryFile = new QPushButton(this);
      btnQueryFile->setObjectName(QString::fromUtf8("btnQueryFile"));
      btnQueryFile->setMinimumSize(QSize(25, 25));
      btnQueryFile->setAutoFillBackground(false);
      btnQueryFile->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 150, 148);"));
      hlFileName->addWidget(btnQueryFile);

    verticalLayout->addLayout(hlFileName);
    // Add spacer
    verticalSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);
    verticalLayout->addItem(verticalSpacer);

    // Create second horizontal layout (Accept button group)
    hlAcceptBtn = new QHBoxLayout();
    hlAcceptBtn->setObjectName(QString::fromUtf8("hlAcceptBtn"));
      // Add spacer
      horizontalSpacerLeft = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
      hlAcceptBtn->addItem(horizontalSpacerLeft);
      // Add "Accept" button
      btnAccept = new QPushButton(this);
      btnAccept->setObjectName(QString::fromUtf8("btnAccept"));
      btnAccept->setMinimumSize(QSize(100, 30));
      btnAccept->setAutoFillBackground(false);
      btnAccept->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 150, 148);"));
      hlAcceptBtn->addWidget(btnAccept);
      // Add spacer
      //horizontalSpacerRight = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
      //hlAcceptBtn->addItem(horizontalSpacerRight);

    verticalLayout->addLayout(hlAcceptBtn);

    SetWindowTitle("Query file name");
    SetMessageText("Please specify a file name");
    SetAcceptButtonText("Accept");

    //connect(btnAccept, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(btnAccept, SIGNAL(clicked()), SLOT(BtnAcceptClicked()));
    //connect(pushButton, SIGNAL(released()), qApp, SLOT(quit()));
    connect(btnQueryFile, SIGNAL(clicked()), SLOT(QueryFileDlg()));
}

Dialog::~Dialog()
{
}

void Dialog::SetMessageText(const char* msg)
{
    label->setText(QApplication::translate("Dialog", msg, nullptr));
}

void Dialog::SetWindowTitle(const char* title)
{
    setWindowTitle(QApplication::translate("Dialog", title, nullptr));
}

void Dialog::SetAcceptButtonText(const char* txt)
{
    btnAccept->setText(QApplication::translate("Dialog", txt, nullptr));
}

void Dialog::SetFileMask(const char* fmask)
{
    sFileMask = fmask;
}

void Dialog::QueryFileDlg()
{
    QString res;
    res = QFileDialog::getOpenFileName(0, "Select a file", "", sFileMask);
    leFullFileName->setText(res);
    //leFullFileName->setText("Test");
}

void Dialog::BtnAcceptClicked()
{
    //std::cout << leFullFileName->text().toStdString() << std::endl;
    QTextStream out(stdout);
    out << leFullFileName->text() << endl;
    qApp->quit();
}
