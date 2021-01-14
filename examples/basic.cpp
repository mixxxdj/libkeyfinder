#include <cstdint>
#include <cstdio>
#include <cstring>

#include <keyfinder/keyfinder.h>
#include <keyfinder/audiodata.h>

// WAVE header as described here:
// http://soundfile.sapp.org/doc/WaveFormat/
typedef struct WAVE_HEADER {
    /* RIFF Chunk Descriptor */
    uint8_t         ChunkID[4];
    uint32_t        ChunkSize;
    uint8_t         Format[4];
    /* "fmt" sub-chunk */
    uint8_t         SubChunk1ID[4];
    uint32_t        SubChunk1Size;
    uint16_t        AudioFormat;
    uint16_t        NumChannels;
    uint32_t        SampleRate;
    uint32_t        ByteRate;
    uint16_t        BlockAlign;
    uint16_t        BitsPerSample;
    /* "data" sub-chunk */
    uint8_t         Subchunk2ID[4];
    uint32_t        Subchunk2Size;
} wave_header_t;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s WAVE_FILE\n", argv[0]);
        return 1;
    }

    const char* filePath = argv[1];
    FILE* file = fopen(filePath, "r");
    if (file == nullptr) {
        fprintf(stderr, "Failed to open WAVE file: %s\n", filePath);
        return 2;
    }

    wave_header_t waveHeader;
    size_t bytesRead = fread(&waveHeader, 1, sizeof(waveHeader), file);
    if (bytesRead < sizeof(waveHeader)) {
        fprintf(stderr, "Failed to read WAVE header.\n");
        return 3;
    }

    const size_t sampleSize = waveHeader.BitsPerSample / 8;
    const auto numSamples = static_cast<unsigned int>(waveHeader.Subchunk2Size / (waveHeader.NumChannels * sampleSize));

    // Prepare the object for your audio stream
    KeyFinder::AudioData a;
    printf("Sample Rate: %d\n", waveHeader.SampleRate);
    a.setFrameRate(waveHeader.SampleRate);
    printf("Num Channels: %d\n", waveHeader.NumChannels);
    a.setChannels(waveHeader.NumChannels);
    printf("Num Samples: %u\n", numSamples);
    a.addToSampleCount(numSamples);

    // Copy audio into the object
    int8_t* buffer = new int8_t[sampleSize];
    int i = 0;
    while (fread(buffer, sizeof(buffer[0]), sampleSize / (sizeof buffer[0]), file) == sampleSize) {
        uint32_t sample = 0;
        for(int i = 0; i < sampleSize; i++) {
            sample |= buffer[i] << (i * 8);
        }
        a.setSample(i, sample);
        i++;
    }
    delete[] buffer;
    fclose(file);

    // Run the analysis
    KeyFinder::KeyFinder k;
    KeyFinder::key_t key =  k.keyOfAudio(a);
    // And do something with the result
    switch(key) {
        case KeyFinder::A_MAJOR:
            puts("A major\n");
            break;
        case KeyFinder::A_MINOR:
            puts("A minor\n");
            break;
        case KeyFinder::B_FLAT_MAJOR:
            puts("B flat major\n");
            break;
        case KeyFinder::B_FLAT_MINOR:
            puts("B flat minor\n");
            break;
        case KeyFinder::B_MAJOR:
            puts("B major\n");
            break;
        case KeyFinder::B_MINOR:
            puts("B minor\n");
            break;
        case KeyFinder::C_MAJOR:
            puts("C major\n");
            break;
        case KeyFinder::C_MINOR:
            puts("C minor\n");
            break;
        case KeyFinder::D_FLAT_MAJOR:
            puts("D flat major\n");
            break;
        case KeyFinder::D_FLAT_MINOR:
            puts("D flat major\n");
            break;
        case KeyFinder::D_MAJOR:
            puts("D major\n");
            break;
        case KeyFinder::D_MINOR:
            puts("D minor\n");
            break;
        case KeyFinder::E_FLAT_MAJOR:
            puts("E flat major\n");
            break;
        case KeyFinder::E_FLAT_MINOR:
            puts("E flat minor\n");
            break;
        case KeyFinder::E_MAJOR:
            puts("E major\n");
            break;
        case KeyFinder::E_MINOR:
            puts("E minor\n");
            break;
        case KeyFinder::F_MAJOR:
            puts("G major\n");
            break;
        case KeyFinder::F_MINOR:
            puts("G minor\n");
            break;
        case KeyFinder::G_FLAT_MAJOR:
            puts("G flat major\n");
            break;
        case KeyFinder::G_FLAT_MINOR:
            puts("G flat minor\n");
            break;
        case KeyFinder::G_MAJOR:
            puts("G major\n");
            break;
        case KeyFinder::G_MINOR:
            puts("G minor\n");
            break;
        case KeyFinder::A_FLAT_MAJOR:
            puts("A flat major\n");
            break;
        case KeyFinder::A_FLAT_MINOR:
            puts("A flat minor\n");
            break;
        case KeyFinder::SILENCE:
            puts("Silence\n");
            break;
    }

    return 0;
}
