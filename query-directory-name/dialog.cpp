#include "dialog.h"
#include <QFileDialog>
#include <QTextStream>

Dialog::Dialog(QWidget *parent) : QDialog(parent)
{
    setObjectName(QString::fromUtf8("Dialog"));
    setMinimumSize(QSize(300, 120));
    uWidth = 500;
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

    // Add label
    label = new QLabel(this);
    label->setObjectName(QString::fromUtf8("label"));
    label->setStyleSheet(QString::fromUtf8("background-color: rgba(0, 0, 0, 0);"));
    label->setAlignment(Qt::AlignLeft);
    verticalLayout->addWidget(label);

    // Create first horizontal layout (Directory Name Group)
    hlDirectoryName = new QHBoxLayout();
    hlDirectoryName->setObjectName(QString::fromUtf8("hlDirectoryName"));
      // Add Line Edit
      leDirectoryName = new QLineEdit;
      leDirectoryName->setFocus();
      hlDirectoryName->addWidget(leDirectoryName);
      leDirectoryName->setMinimumHeight(32);
      // Add spacer
      hsDirectoryNameSpacer1 = new QSpacerItem(10, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);
      hlDirectoryName->addItem(hsDirectoryNameSpacer1);
      // Add "query directory" button
      btnQueryDirectory = new QPushButton(this);
      btnQueryDirectory->setObjectName(QString::fromUtf8("btnQueryDirectory"));
      btnQueryDirectory->setMinimumSize(QSize(leDirectoryName->minimumHeight(), leDirectoryName->minimumHeight()));
      btnQueryDirectory->setFlat(true);
      btnQueryDirectory->setIcon(QPixmap(":/document-open-folder.png"));
      btnQueryDirectory->setIconSize(QSize(leDirectoryName->minimumHeight(), leDirectoryName->minimumHeight()));
      btnQueryDirectory->setAutoFillBackground(false);
      btnQueryDirectory->setStyleSheet(QString::fromUtf8("background-color: rgb(148, 150, 148);"));
      hlDirectoryName->addWidget(btnQueryDirectory);

    verticalLayout->addLayout(hlDirectoryName);
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

    verticalLayout->addLayout(hlAcceptBtn);

    SetWindowTitle("Query directory");
    SetMessageText("Please select a directory");
    SetAcceptButtonText("Accept");

    connect(btnAccept, SIGNAL(clicked()), SLOT(BtnAcceptClicked()));
    connect(btnQueryDirectory, SIGNAL(clicked()), SLOT(QueryDirectoryDlg()));
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

void Dialog::SetBaseDirectory(const char* bdir)
{
    sBaseDir = bdir;
    leDirectoryName->setText(sBaseDir);
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

void Dialog::QueryDirectoryDlg()
{
    QString res;
    res = QFileDialog::getExistingDirectory(0, "Select a directory", sBaseDir);
    leDirectoryName->setText(res);
}

void Dialog::BtnAcceptClicked()
{
    QTextStream out(stdout);
    out << leDirectoryName->text() << endl;
    qApp->quit();
}
