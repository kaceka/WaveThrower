#include "Waveplayer.h"
#include "QByteArray"
#include "QtMath"
#include "QBuffer"
#include <QtMultimedia/QAudioOutput>
#include <QtMultimedia/QAudioDeviceInfo>

WavePlayer::WavePlayer()
{

}

void WavePlayer::GenerateWave(std::shared_ptr<SinWave> _sin)
{
#define SAMPLE_RATE 1000
#define FREQ_CONST ((2.0 * M_PI) / SAMPLE_RATE)
#define TG_MAX_VAL 50
int seconds = 3;
int freq = _sin->frequency;

QByteArray* bytebuf = new QByteArray();
bytebuf->resize(seconds * SAMPLE_RATE);

for (int i=0; i<(seconds * SAMPLE_RATE); i++) {
    qreal t = (qreal)(freq * i);
    t = t * FREQ_CONST;
    t = qSin(t);
    // now we normalize t
    t *= TG_MAX_VAL;
    (*bytebuf)[i] = (quint8)t;
}

// Make a QBuffer from our QByteArray
QBuffer* input = new QBuffer(bytebuf);
input->open(QIODevice::ReadOnly);

//// Create an output with our premade QAudioFormat (See example in QAudioOutput)
//QAudioOutput* audio = new QAudioOutput(format, this);
//audio->start(input);

QAudioFormat format;
format.setSampleRate(44100);
format.setChannelCount(1);
format.setSampleSize(16);
format.setCodec("audio/pcm");
format.setByteOrder(QAudioFormat::LittleEndian);
format.setSampleType(QAudioFormat::SignedInt);


const int durationSeconds = 1;
const int toneSampleRateHz = 600;
//m_generator.reset(new Generator(format, durationSeconds * 1000000, toneSampleRateHz));
const QAudioDeviceInfo &defaultDeviceInfo = QAudioDeviceInfo::defaultOutputDevice();
QAudioOutput * audio = new QAudioOutput(defaultDeviceInfo, format);
audio->start(input);
}
