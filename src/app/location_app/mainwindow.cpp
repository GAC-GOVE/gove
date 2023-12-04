#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "MapEngine.h"
#include <Memory>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    GetTile();
}

std::string MainWindow::GetTile(){
    using namespace gove::location;
    auto map_engine_ptr = std::make_unique<Location>();

    std::string image;
    auto tile = map_engine_ptr->GetTile(1, 1, 1, image);

    std::cout << image << std::endl;
    return image;
}



MainWindow::~MainWindow()
{
    delete ui;
}

