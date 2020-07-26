#ifndef WAVEPLAYER_H
#define WAVEPLAYER_H
#include "Sinwave.h"
#include "mainwindow.h"


class WavePlayer
{
public:
    WavePlayer();

    void GenerateWave(std::shared_ptr<SinWave> _sin);
};

#endif // WAVEPLAYER_H
