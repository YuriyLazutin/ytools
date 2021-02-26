#include "dialog.h"
#include <QTextStream>

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    setObjectName(QString::fromUtf8("Dialog"));
    setMinimumSize(QSize(300, 120));
    uWidth = minimumWidth();
    uHeight = minimumHeight();
    resize(uWidth, uHeight);
    //setMaximumSize(QSize(10000, 120)); // It work
    QSizePolicy szPolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    szPolicy.setHorizontalStretch(0);
    szPolicy.setVerticalStretch(0);
    szPolicy.setHeightForWidth(sizePolicy().hasHeightForWidth());
    setSizePolicy(szPolicy);
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

    // Add Line Edit
    leKey = new QLineEdit;
    leKey->setObjectName(QString::fromUtf8("Line Edit"));
    leKey->setFocus();
    leKey->setEchoMode(QLineEdit::Password);
    verticalLayout->addWidget(leKey);
    //leKey->setMinimumHeight(32);

    // Add spacer
    verticalSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);
    verticalLayout->addItem(verticalSpacer);

    // Create horizontal layout (Accept button group)
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

    SetWindowTitle("Password required");
    SetMessageText("Please enter your password");
    SetAcceptButtonText("Accept");

    connect(btnAccept, SIGNAL(clicked()), SLOT(BtnAcceptClicked()));
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

void Dialog::SetSizeX(const int sx)
{
    sx < minimumWidth() ? uWidth = minimumWidth() : uWidth=sx;
    resize(uWidth, uHeight);
}
void Dialog::SetSizeY(const int sy)
{
    sy < minimumHeight() ? uHeight = minimumHeight() : uHeight=sy;
    resize(uWidth, uHeight);
}

void Dialog::BtnAcceptClicked()
{
    QTextStream out(stdout);
    out << leKey->text() << endl;
    qApp->quit();
}
