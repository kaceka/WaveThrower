#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Sinwave.h"
#include "Waveplayer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_generateWave_clicked()
{
    std::shared_ptr<SinWave> wave (new SinWave(1000));
    WavePlayer * player = new WavePlayer();
    player->GenerateWave(wave);

}
