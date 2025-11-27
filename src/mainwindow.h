#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QProgressBar>
#include <QListWidget>
#include <QStackedWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNavigationClicked();
    void onPrimaryButtonClicked();
    void onSecondaryButtonClicked();

private:
    void setupUI();
    void applyStyles();
    void createSidebar();
    void createContentArea();
    void createDashboardPage();
    void createSettingsPage();
    void createProfilePage();

    // Sidebar
    QFrame *sidebarFrame;
    QVBoxLayout *sidebarLayout;
    QPushButton *dashboardBtn;
    QPushButton *settingsBtn;
    QPushButton *profileBtn;
    QLabel *logoLabel;

    // Content area
    QStackedWidget *contentStack;
    QWidget *dashboardPage;
    QWidget *settingsPage;
    QWidget *profilePage;

    // Dashboard widgets
    QLabel *welcomeLabel;
    QLabel *statsLabel;
    QProgressBar *progressBar;
    QPushButton *primaryButton;
    QPushButton *secondaryButton;
    QListWidget *recentList;

    // Central widget
    QWidget *centralWidget;
    QHBoxLayout *mainLayout;
};

#endif // MAINWINDOW_H
