#include "mainwindow.h"
#include <QGraphicsDropShadowEffect>
#include <QFont>
#include <QMessageBox>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    applyStyles();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUI()
{
    // Set window properties
    setWindowTitle("Beautiful UI Dashboard");
    setMinimumSize(1000, 700);
    resize(1200, 800);

    // Create central widget and main layout
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    createSidebar();
    createContentArea();
}

void MainWindow::createSidebar()
{
    sidebarFrame = new QFrame(this);
    sidebarFrame->setObjectName("sidebar");
    sidebarFrame->setFixedWidth(250);
    
    sidebarLayout = new QVBoxLayout(sidebarFrame);
    sidebarLayout->setContentsMargins(20, 30, 20, 30);
    sidebarLayout->setSpacing(10);

    // Logo/Brand area
    logoLabel = new QLabel("✨ Beautiful UI", sidebarFrame);
    logoLabel->setObjectName("logoLabel");
    QFont logoFont;
    logoFont.setPointSize(18);
    logoFont.setBold(true);
    logoLabel->setFont(logoFont);
    logoLabel->setAlignment(Qt::AlignCenter);
    sidebarLayout->addWidget(logoLabel);
    sidebarLayout->addSpacing(40);

    // Navigation buttons
    dashboardBtn = new QPushButton("🏠  Dashboard", sidebarFrame);
    dashboardBtn->setObjectName("navButton");
    dashboardBtn->setProperty("active", true);
    dashboardBtn->setCursor(Qt::PointingHandCursor);
    connect(dashboardBtn, &QPushButton::clicked, this, &MainWindow::onNavigationClicked);
    sidebarLayout->addWidget(dashboardBtn);

    settingsBtn = new QPushButton("⚙️  Settings", sidebarFrame);
    settingsBtn->setObjectName("navButton");
    settingsBtn->setCursor(Qt::PointingHandCursor);
    connect(settingsBtn, &QPushButton::clicked, this, &MainWindow::onNavigationClicked);
    sidebarLayout->addWidget(settingsBtn);

    profileBtn = new QPushButton("👤  Profile", sidebarFrame);
    profileBtn->setObjectName("navButton");
    profileBtn->setCursor(Qt::PointingHandCursor);
    connect(profileBtn, &QPushButton::clicked, this, &MainWindow::onNavigationClicked);
    sidebarLayout->addWidget(profileBtn);

    sidebarLayout->addStretch();

    // Bottom info
    QLabel *versionLabel = new QLabel("Version 1.0.0", sidebarFrame);
    versionLabel->setObjectName("versionLabel");
    versionLabel->setAlignment(Qt::AlignCenter);
    sidebarLayout->addWidget(versionLabel);

    mainLayout->addWidget(sidebarFrame);
}

void MainWindow::createContentArea()
{
    contentStack = new QStackedWidget(this);
    contentStack->setObjectName("contentStack");

    createDashboardPage();
    createSettingsPage();
    createProfilePage();

    contentStack->addWidget(dashboardPage);
    contentStack->addWidget(settingsPage);
    contentStack->addWidget(profilePage);
    contentStack->setCurrentIndex(0);

    mainLayout->addWidget(contentStack);
}

void MainWindow::createDashboardPage()
{
    dashboardPage = new QWidget();
    dashboardPage->setObjectName("contentPage");
    QVBoxLayout *layout = new QVBoxLayout(dashboardPage);
    layout->setContentsMargins(40, 40, 40, 40);
    layout->setSpacing(25);

    // Welcome header
    welcomeLabel = new QLabel("Welcome Back! 👋", dashboardPage);
    welcomeLabel->setObjectName("headerLabel");
    QFont headerFont;
    headerFont.setPointSize(28);
    headerFont.setBold(true);
    welcomeLabel->setFont(headerFont);
    layout->addWidget(welcomeLabel);

    // Stats cards row
    QHBoxLayout *cardsLayout = new QHBoxLayout();
    cardsLayout->setSpacing(20);

    // Card 1 - Projects
    QFrame *card1 = new QFrame(dashboardPage);
    card1->setObjectName("statsCard");
    QVBoxLayout *card1Layout = new QVBoxLayout(card1);
    QLabel *card1Value = new QLabel("12", card1);
    card1Value->setObjectName("cardValue");
    QFont valueFont;
    valueFont.setPointSize(36);
    valueFont.setBold(true);
    card1Value->setFont(valueFont);
    QLabel *card1Label = new QLabel("Active Projects", card1);
    card1Label->setObjectName("cardLabel");
    card1Layout->addWidget(card1Value);
    card1Layout->addWidget(card1Label);
    cardsLayout->addWidget(card1);

    // Card 2 - Tasks
    QFrame *card2 = new QFrame(dashboardPage);
    card2->setObjectName("statsCard");
    card2->setProperty("accent", "green");
    QVBoxLayout *card2Layout = new QVBoxLayout(card2);
    QLabel *card2Value = new QLabel("48", card2);
    card2Value->setObjectName("cardValue");
    card2Value->setFont(valueFont);
    QLabel *card2Label = new QLabel("Completed Tasks", card2);
    card2Label->setObjectName("cardLabel");
    card2Layout->addWidget(card2Value);
    card2Layout->addWidget(card2Label);
    cardsLayout->addWidget(card2);

    // Card 3 - Progress
    QFrame *card3 = new QFrame(dashboardPage);
    card3->setObjectName("statsCard");
    card3->setProperty("accent", "purple");
    QVBoxLayout *card3Layout = new QVBoxLayout(card3);
    QLabel *card3Value = new QLabel("87%", card3);
    card3Value->setObjectName("cardValue");
    card3Value->setFont(valueFont);
    QLabel *card3Label = new QLabel("Overall Progress", card3);
    card3Label->setObjectName("cardLabel");
    card3Layout->addWidget(card3Value);
    card3Layout->addWidget(card3Label);
    cardsLayout->addWidget(card3);

    layout->addLayout(cardsLayout);

    // Progress section
    QLabel *progressTitle = new QLabel("Project Progress", dashboardPage);
    progressTitle->setObjectName("sectionTitle");
    QFont sectionFont;
    sectionFont.setPointSize(16);
    sectionFont.setBold(true);
    progressTitle->setFont(sectionFont);
    layout->addWidget(progressTitle);

    progressBar = new QProgressBar(dashboardPage);
    progressBar->setObjectName("styledProgress");
    progressBar->setValue(72);
    progressBar->setTextVisible(true);
    progressBar->setFixedHeight(25);
    layout->addWidget(progressBar);

    // Buttons row
    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    buttonsLayout->setSpacing(15);

    primaryButton = new QPushButton("✨ Create New Project", dashboardPage);
    primaryButton->setObjectName("primaryButton");
    primaryButton->setCursor(Qt::PointingHandCursor);
    primaryButton->setFixedHeight(50);
    connect(primaryButton, &QPushButton::clicked, this, &MainWindow::onPrimaryButtonClicked);
    buttonsLayout->addWidget(primaryButton);

    secondaryButton = new QPushButton("📋 View All Tasks", dashboardPage);
    secondaryButton->setObjectName("secondaryButton");
    secondaryButton->setCursor(Qt::PointingHandCursor);
    secondaryButton->setFixedHeight(50);
    connect(secondaryButton, &QPushButton::clicked, this, &MainWindow::onSecondaryButtonClicked);
    buttonsLayout->addWidget(secondaryButton);

    buttonsLayout->addStretch();
    layout->addLayout(buttonsLayout);

    // Recent activity
    QLabel *recentTitle = new QLabel("Recent Activity", dashboardPage);
    recentTitle->setObjectName("sectionTitle");
    recentTitle->setFont(sectionFont);
    layout->addWidget(recentTitle);

    recentList = new QListWidget(dashboardPage);
    recentList->setObjectName("recentList");
    recentList->addItem("📁 Project Alpha - Updated 2 hours ago");
    recentList->addItem("✅ Task completed - Design review");
    recentList->addItem("💬 New comment on Feature Request");
    recentList->addItem("🚀 Deployed to production");
    recentList->addItem("📊 Analytics report generated");
    layout->addWidget(recentList);

    layout->addStretch();
}

void MainWindow::createSettingsPage()
{
    settingsPage = new QWidget();
    settingsPage->setObjectName("contentPage");
    QVBoxLayout *layout = new QVBoxLayout(settingsPage);
    layout->setContentsMargins(40, 40, 40, 40);
    layout->setSpacing(25);

    QLabel *headerLabel = new QLabel("⚙️ Settings", settingsPage);
    headerLabel->setObjectName("headerLabel");
    QFont headerFont;
    headerFont.setPointSize(28);
    headerFont.setBold(true);
    headerLabel->setFont(headerFont);
    layout->addWidget(headerLabel);

    // Settings cards
    QFrame *settingsCard = new QFrame(settingsPage);
    settingsCard->setObjectName("settingsCard");
    QVBoxLayout *cardLayout = new QVBoxLayout(settingsCard);
    cardLayout->setSpacing(20);

    QLabel *themeLabel = new QLabel("🎨 Theme Settings", settingsCard);
    themeLabel->setObjectName("settingsLabel");
    QFont labelFont;
    labelFont.setPointSize(14);
    labelFont.setBold(true);
    themeLabel->setFont(labelFont);
    cardLayout->addWidget(themeLabel);

    QLabel *themeDesc = new QLabel("Customize the appearance of your dashboard", settingsCard);
    themeDesc->setObjectName("settingsDesc");
    cardLayout->addWidget(themeDesc);

    QLabel *notifLabel = new QLabel("🔔 Notification Settings", settingsCard);
    notifLabel->setObjectName("settingsLabel");
    notifLabel->setFont(labelFont);
    cardLayout->addWidget(notifLabel);

    QLabel *notifDesc = new QLabel("Configure how you receive notifications", settingsCard);
    notifDesc->setObjectName("settingsDesc");
    cardLayout->addWidget(notifDesc);

    QLabel *privacyLabel = new QLabel("🔒 Privacy Settings", settingsCard);
    privacyLabel->setObjectName("settingsLabel");
    privacyLabel->setFont(labelFont);
    cardLayout->addWidget(privacyLabel);

    QLabel *privacyDesc = new QLabel("Manage your privacy and security options", settingsCard);
    privacyDesc->setObjectName("settingsDesc");
    cardLayout->addWidget(privacyDesc);

    layout->addWidget(settingsCard);
    layout->addStretch();
}

void MainWindow::createProfilePage()
{
    profilePage = new QWidget();
    profilePage->setObjectName("contentPage");
    QVBoxLayout *layout = new QVBoxLayout(profilePage);
    layout->setContentsMargins(40, 40, 40, 40);
    layout->setSpacing(25);

    QLabel *headerLabel = new QLabel("👤 Profile", profilePage);
    headerLabel->setObjectName("headerLabel");
    QFont headerFont;
    headerFont.setPointSize(28);
    headerFont.setBold(true);
    headerLabel->setFont(headerFont);
    layout->addWidget(headerLabel);

    // Profile card
    QFrame *profileCard = new QFrame(profilePage);
    profileCard->setObjectName("profileCard");
    QVBoxLayout *cardLayout = new QVBoxLayout(profileCard);
    cardLayout->setAlignment(Qt::AlignCenter);
    cardLayout->setSpacing(15);

    QLabel *avatarLabel = new QLabel("👤", profileCard);
    avatarLabel->setObjectName("avatarLabel");
    QFont avatarFont;
    avatarFont.setPointSize(72);
    avatarLabel->setFont(avatarFont);
    avatarLabel->setAlignment(Qt::AlignCenter);
    cardLayout->addWidget(avatarLabel);

    QLabel *nameLabel = new QLabel("John Doe", profileCard);
    nameLabel->setObjectName("profileName");
    QFont nameFont;
    nameFont.setPointSize(24);
    nameFont.setBold(true);
    nameLabel->setFont(nameFont);
    nameLabel->setAlignment(Qt::AlignCenter);
    cardLayout->addWidget(nameLabel);

    QLabel *roleLabel = new QLabel("Senior Developer", profileCard);
    roleLabel->setObjectName("profileRole");
    roleLabel->setAlignment(Qt::AlignCenter);
    cardLayout->addWidget(roleLabel);

    QLabel *emailLabel = new QLabel("📧 john.doe@example.com", profileCard);
    emailLabel->setObjectName("profileEmail");
    emailLabel->setAlignment(Qt::AlignCenter);
    cardLayout->addWidget(emailLabel);

    layout->addWidget(profileCard);
    layout->addStretch();
}

void MainWindow::applyStyles()
{
    QFile styleFile(":/style.qss");
    if (styleFile.open(QFile::ReadOnly | QFile::Text)) {
        QString styleSheet = styleFile.readAll();
        styleFile.close();
        setStyleSheet(styleSheet);
    }
}

void MainWindow::refreshButtonStyles()
{
    QList<QPushButton*> navButtons = {dashboardBtn, settingsBtn, profileBtn};
    for (QPushButton *btn : navButtons) {
        btn->style()->unpolish(btn);
        btn->style()->polish(btn);
    }
}

void MainWindow::onNavigationClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (!clickedButton) return;

    // Reset all buttons
    dashboardBtn->setProperty("active", false);
    settingsBtn->setProperty("active", false);
    profileBtn->setProperty("active", false);

    // Set active button and switch page
    clickedButton->setProperty("active", true);
    
    if (clickedButton == dashboardBtn) {
        contentStack->setCurrentIndex(0);
    } else if (clickedButton == settingsBtn) {
        contentStack->setCurrentIndex(1);
    } else if (clickedButton == profileBtn) {
        contentStack->setCurrentIndex(2);
    }

    // Force style refresh
    refreshButtonStyles();
}

void MainWindow::onPrimaryButtonClicked()
{
    QMessageBox::information(this, "Create Project", 
        "🎉 Create New Project clicked!\n\nThis would open a project creation dialog.");
}

void MainWindow::onSecondaryButtonClicked()
{
    QMessageBox::information(this, "View Tasks", 
        "📋 View All Tasks clicked!\n\nThis would show all your tasks.");
}
