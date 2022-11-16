#include "login.h"
#include "ui_login.h"

#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QCoreApplication>
#include <iostream>
#include <string>
#include <vector>

#include "dashboard.h"
#include "register.h"
#include "user.h"
using json = nlohmann::json;

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login) {
    ui->setupUi(this);
}

Login::~Login() {
    delete ui;
}

void Login::on_pushButton_register_clicked() {
    Register* registerDialog = new Register(this);
    registerDialog->show();

    // std::ifstream ifs("/json/users.json");
//    std::string t;
//    getline(ifs, t);
//    getline(ifs, t);
//    std::cout << t << std::endl;
//    json jf =  json::parse(ifs);
//    ifs.close();
/*
    auto users = jf.get<std::vector<User>>();
    std::cout << users[0].user << std::endl; // data read
    users[0].pwd = "secret";                 // data modification
    users.push_back(User{ "james", "567"});  // data insert
    users.erase(users.begin()+1);            // data removal

    std::ofstream ofs("output.json");
    ofs << std::setw(2) << nlohmann::json(users) << std::endl;
    ofs.close();
*/
}


void Login::on_pushButton_login_clicked() {
    std::string username = ui->lineEdit_username->text().toStdString();
    std::string password = ui->lineEdit_password->text().toStdString();

    QString usersFilePath = QDir::currentPath() + "/../../../../users.json";
    QFile userFile(usersFilePath);

    std::string usersJsonString;

    if (userFile.open(QIODevice::ReadOnly)) {
        usersJsonString = userFile.readAll().toStdString();
        userFile.close();
    } else {
        std::cout << "An unknow error has occurred" << std::endl;
    }
    json js = json::parse(usersJsonString);
    auto users = js.get<std::vector<User>>();

    for (auto user: users) {
        if (username == user.user && password == user.pwd) {
            std::cout << "login successful" << std::endl;
            hide();
            Dashboard* dashboard = new Dashboard();
            dashboard->show();
            dashboard->setUser(user);
            return;
        }
    }

    QMessageBox::critical(this, "User Athentication failed", "Username or Password is incorrect.");
}

