#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cos_50hz_8k();
void cos_50hz_16k();
void cos_55hz_8k();
void cos_55hz_16k();
void cos_200hz_8k();
void cos_200hz_16k();
void cos_220hz_8k();
void cos_220hz_16k();

int main(){
    cos_50hz_8k();
    cos_50hz_16k();
    cos_55hz_8k();
    cos_55hz_16k();
    cos_200hz_8k();
    cos_200hz_16k();
    cos_220hz_8k();
    cos_220hz_16k();
    return 0;
}

void cos_50hz_8k(){
     FILE *fptr = fopen("cos_50hz-8k.wav", "wb");
    float pi = acos(-1);
    char ChunkID[4] = {'R', 'I', 'F', 'F'};
    int ChunkSize = 16036;   //16000*2-8
    char Format[4] = {'W', 'A', 'V', 'E'};
    char Subchunk1ID[4] = {'f', 'm', 't', ' '};
    int Subchunk1Size = 16;
    short AudioFormat = 1;
    short NumChannels = 1;
    int SampleRate = 8000;
    int ByteRate = 16000;
    short BlockAlign = 2;
    short BitsPerSample = 16;
    char SubChunk2ID[4] = {'d', 'a', 't', 'a'};
    int SubChunk2Size = 16000;
    int i;
    short data[8000];
    for(i=0;i<8000;i++){
        data[i] = (short)10000*cos(2*pi*50*i/8000);
    }

    fwrite(&ChunkID, 4, sizeof(char),fptr);
    fwrite(&ChunkSize, 1, sizeof(int), fptr);
    fwrite(&Format, 4, sizeof(char), fptr);
    fwrite(&Subchunk1ID, 4, sizeof(char), fptr);
    fwrite(&Subchunk1Size, 1, sizeof(int), fptr);
    fwrite(&AudioFormat, 1, sizeof(short), fptr);
    fwrite(&NumChannels, 1, sizeof(short), fptr);
    fwrite(&SampleRate, 1, sizeof(int), fptr);
    fwrite(&ByteRate, 1, sizeof(int), fptr);
    fwrite(&BlockAlign, 1, sizeof(short), fptr);
    fwrite(&BitsPerSample, 1, sizeof(short), fptr);
    fwrite(&SubChunk2ID, 4, sizeof(char), fptr);
    fwrite(&SubChunk2Size, 1, sizeof(int),fptr);
    for(i=0;i<8000;i++){
        fwrite(&(data[i]), 1, sizeof(short), fptr);
    }
    fclose(fptr);
}
void cos_50hz_16k(){
    FILE *fptr = fopen("cos_50hz-16k.wav", "wb");
    float pi = acos(-1);
    char ChunkID[4] = {'R', 'I', 'F', 'F'};
    int ChunkSize = 32036;   //16000*2-8
    char Format[4] = {'W', 'A', 'V', 'E'};
    char Subchunk1ID[4] = {'f', 'm', 't', ' '};
    int Subchunk1Size = 16;
    short AudioFormat = 1;
    short NumChannels = 1;
    int SampleRate = 16000;
    int ByteRate = 32000;
    short BlockAlign = 2;
    short BitsPerSample = 16;
    char SubChunk2ID[4] = {'d', 'a', 't', 'a'};
    int SubChunk2Size = 32000;
    int i;
    short data[16000];
    for(i=0;i<16000;i++){
        data[i] = (short)10000*cos(2*pi*50*i/16000);
    }
    fwrite(&ChunkID, 4, sizeof(char),fptr);
    fwrite(&ChunkSize, 1, sizeof(int), fptr);
    fwrite(&Format, 4, sizeof(char), fptr);
    fwrite(&Subchunk1ID, 4, sizeof(char), fptr);
    fwrite(&Subchunk1Size, 1, sizeof(int), fptr);
    fwrite(&AudioFormat, 1, sizeof(short), fptr);
    fwrite(&NumChannels, 1, sizeof(short), fptr);
    fwrite(&SampleRate, 1, sizeof(int), fptr);
    fwrite(&ByteRate, 1, sizeof(int), fptr);
    fwrite(&BlockAlign, 1, sizeof(short), fptr);
    fwrite(&BitsPerSample, 1, sizeof(short), fptr);
    fwrite(&SubChunk2ID, 4, sizeof(char), fptr);
    fwrite(&SubChunk2Size, 1, sizeof(int),fptr);
    for(i=0;i<16000;i++){
        fwrite(&(data[i]), 1, sizeof(short), fptr);
    }
    fclose(fptr);
}
void cos_55hz_8k(){
    FILE *fptr = fopen("cos_55hz-8k.wav", "wb");
    float pi = acos(-1);
    char ChunkID[4] = {'R', 'I', 'F', 'F'};
    int ChunkSize = 16036;   //16000*2-8
    char Format[4] = {'W', 'A', 'V', 'E'};
    char Subchunk1ID[4] = {'f', 'm', 't', ' '};
    int Subchunk1Size = 16;
    short AudioFormat = 1;
    short NumChannels = 1;
    int SampleRate = 8000;
    int ByteRate = 16000;
    short BlockAlign = 2;
    short BitsPerSample = 16;
    char SubChunk2ID[4] = {'d', 'a', 't', 'a'};
    int SubChunk2Size = 16000;
    int i;
    short data[8000];
    for(i=0;i<8000;i++){
        data[i] = (short)10000*cos(2*pi*55*i/8000);
    }

    fwrite(&ChunkID, 4, sizeof(char),fptr);
    fwrite(&ChunkSize, 1, sizeof(int), fptr);
    fwrite(&Format, 4, sizeof(char), fptr);
    fwrite(&Subchunk1ID, 4, sizeof(char), fptr);
    fwrite(&Subchunk1Size, 1, sizeof(int), fptr);
    fwrite(&AudioFormat, 1, sizeof(short), fptr);
    fwrite(&NumChannels, 1, sizeof(short), fptr);
    fwrite(&SampleRate, 1, sizeof(int), fptr);
    fwrite(&ByteRate, 1, sizeof(int), fptr);
    fwrite(&BlockAlign, 1, sizeof(short), fptr);
    fwrite(&BitsPerSample, 1, sizeof(short), fptr);
    fwrite(&SubChunk2ID, 4, sizeof(char), fptr);
    fwrite(&SubChunk2Size, 1, sizeof(int),fptr);
    for(i=0;i<8000;i++){
        fwrite(&(data[i]), 1, sizeof(short), fptr);
    }
    fclose(fptr);
}
void cos_55hz_16k(){
    FILE *fptr = fopen("cos_55hz-16k.wav", "wb");
    float pi = acos(-1);
    char ChunkID[4] = {'R', 'I', 'F', 'F'};
    int ChunkSize = 32036;   //16000*2-8
    char Format[4] = {'W', 'A', 'V', 'E'};
    char Subchunk1ID[4] = {'f', 'm', 't', ' '};
    int Subchunk1Size = 16;
    short AudioFormat = 1;
    short NumChannels = 1;
    int SampleRate = 16000;
    int ByteRate = 32000;
    short BlockAlign = 2;
    short BitsPerSample = 16;
    char SubChunk2ID[4] = {'d', 'a', 't', 'a'};
    int SubChunk2Size = 32000;
    int i;
    short data[16000];
    for(i=0;i<16000;i++){
        data[i] = (short)10000*cos(2*pi*55*i/16000);
    }
    fwrite(&ChunkID, 4, sizeof(char),fptr);
    fwrite(&ChunkSize, 1, sizeof(int), fptr);
    fwrite(&Format, 4, sizeof(char), fptr);
    fwrite(&Subchunk1ID, 4, sizeof(char), fptr);
    fwrite(&Subchunk1Size, 1, sizeof(int), fptr);
    fwrite(&AudioFormat, 1, sizeof(short), fptr);
    fwrite(&NumChannels, 1, sizeof(short), fptr);
    fwrite(&SampleRate, 1, sizeof(int), fptr);
    fwrite(&ByteRate, 1, sizeof(int), fptr);
    fwrite(&BlockAlign, 1, sizeof(short), fptr);
    fwrite(&BitsPerSample, 1, sizeof(short), fptr);
    fwrite(&SubChunk2ID, 4, sizeof(char), fptr);
    fwrite(&SubChunk2Size, 1, sizeof(int),fptr);
    for(i=0;i<16000;i++){
        fwrite(&(data[i]), 1, sizeof(short), fptr);
    }
    fclose(fptr);
}
void cos_200hz_8k(){
    FILE *fptr = fopen("cos_200hz-8k.wav", "wb");
    float pi = acos(-1);
    char ChunkID[4] = {'R', 'I', 'F', 'F'};
    int ChunkSize = 16036;   
    char Format[4] = {'W', 'A', 'V', 'E'};
    char Subchunk1ID[4] = {'f', 'm', 't', ' '};
    int Subchunk1Size = 16;
    short AudioFormat = 1;
    short NumChannels = 1;
    int SampleRate = 8000;
    int ByteRate = 16000;
    short BlockAlign = 2;
    short BitsPerSample = 16;
    char SubChunk2ID[4] = {'d', 'a', 't', 'a'};
    int SubChunk2Size = 16000;
    int i;
    short data[8000];
    for(i=0;i<8000;i++){
        data[i] = (short)10000*cos(2*pi*200*i/8000);
    }

    fwrite(&ChunkID, 4, sizeof(char),fptr);
    fwrite(&ChunkSize, 1, sizeof(int), fptr);
    fwrite(&Format, 4, sizeof(char), fptr);
    fwrite(&Subchunk1ID, 4, sizeof(char), fptr);
    fwrite(&Subchunk1Size, 1, sizeof(int), fptr);
    fwrite(&AudioFormat, 1, sizeof(short), fptr);
    fwrite(&NumChannels, 1, sizeof(short), fptr);
    fwrite(&SampleRate, 1, sizeof(int), fptr);
    fwrite(&ByteRate, 1, sizeof(int), fptr);
    fwrite(&BlockAlign, 1, sizeof(short), fptr);
    fwrite(&BitsPerSample, 1, sizeof(short), fptr);
    fwrite(&SubChunk2ID, 4, sizeof(char), fptr);
    fwrite(&SubChunk2Size, 1, sizeof(int),fptr);
    for(i=0;i<8000;i++){
        fwrite(&(data[i]), 1, sizeof(short), fptr);
    }
    fclose(fptr);
}
void cos_200hz_16k(){
    FILE *fptr = fopen("cos_200hz-16k.wav", "wb");
    float pi = acos(-1);
    char ChunkID[4] = {'R', 'I', 'F', 'F'};
    int ChunkSize = 32036;   //16000*2-8
    char Format[4] = {'W', 'A', 'V', 'E'};
    char Subchunk1ID[4] = {'f', 'm', 't', ' '};
    int Subchunk1Size = 16;
    short AudioFormat = 1;
    short NumChannels = 1;
    int SampleRate = 16000;
    int ByteRate = 32000;
    short BlockAlign = 2;
    short BitsPerSample = 16;
    char SubChunk2ID[4] = {'d', 'a', 't', 'a'};
    int SubChunk2Size = 32000;
    int i;
    short data[16000];
    for(i=0;i<16000;i++){
        data[i] = (short)10000*cos(2*pi*200*i/16000);
    }
    fwrite(&ChunkID, 4, sizeof(char),fptr);
    fwrite(&ChunkSize, 1, sizeof(int), fptr);
    fwrite(&Format, 4, sizeof(char), fptr);
    fwrite(&Subchunk1ID, 4, sizeof(char), fptr);
    fwrite(&Subchunk1Size, 1, sizeof(int), fptr);
    fwrite(&AudioFormat, 1, sizeof(short), fptr);
    fwrite(&NumChannels, 1, sizeof(short), fptr);
    fwrite(&SampleRate, 1, sizeof(int), fptr);
    fwrite(&ByteRate, 1, sizeof(int), fptr);
    fwrite(&BlockAlign, 1, sizeof(short), fptr);
    fwrite(&BitsPerSample, 1, sizeof(short), fptr);
    fwrite(&SubChunk2ID, 4, sizeof(char), fptr);
    fwrite(&SubChunk2Size, 1, sizeof(int),fptr);
    for(i=0;i<16000;i++){
        fwrite(&(data[i]), 1, sizeof(short), fptr);
    }
    fclose(fptr);
}
void cos_220hz_8k(){
    FILE *fptr = fopen("cos_220hz-8k.wav", "wb");
    float pi = acos(-1);
    char ChunkID[4] = {'R', 'I', 'F', 'F'};
    int ChunkSize = 16036;   //16000*2-8
    char Format[4] = {'W', 'A', 'V', 'E'};
    char Subchunk1ID[4] = {'f', 'm', 't', ' '};
    int Subchunk1Size = 16;
    short AudioFormat = 1;
    short NumChannels = 1;
    int SampleRate = 8000;
    int ByteRate = 16000;
    short BlockAlign = 2;
    short BitsPerSample = 16;
    char SubChunk2ID[4] = {'d', 'a', 't', 'a'};
    int SubChunk2Size = 16000;
    int i;
    short data[8000];
    for(i=0;i<8000;i++){
        data[i] = (short)10000*cos(2*pi*220*i/8000);
    }

    fwrite(&ChunkID, 4, sizeof(char),fptr);
    fwrite(&ChunkSize, 1, sizeof(int), fptr);
    fwrite(&Format, 4, sizeof(char), fptr);
    fwrite(&Subchunk1ID, 4, sizeof(char), fptr);
    fwrite(&Subchunk1Size, 1, sizeof(int), fptr);
    fwrite(&AudioFormat, 1, sizeof(short), fptr);
    fwrite(&NumChannels, 1, sizeof(short), fptr);
    fwrite(&SampleRate, 1, sizeof(int), fptr);
    fwrite(&ByteRate, 1, sizeof(int), fptr);
    fwrite(&BlockAlign, 1, sizeof(short), fptr);
    fwrite(&BitsPerSample, 1, sizeof(short), fptr);
    fwrite(&SubChunk2ID, 4, sizeof(char), fptr);
    fwrite(&SubChunk2Size, 1, sizeof(int),fptr);
    for(i=0;i<8000;i++){
        fwrite(&(data[i]), 1, sizeof(short), fptr);
    }
    fclose(fptr);
}
void cos_220hz_16k(){
    FILE *fptr = fopen("cos_220hz-16k.wav", "wb");
    float pi = acos(-1);
    char ChunkID[4] = {'R', 'I', 'F', 'F'};
    int ChunkSize = 32036;   //16000*2-8
    char Format[4] = {'W', 'A', 'V', 'E'};
    char Subchunk1ID[4] = {'f', 'm', 't', ' '};
    int Subchunk1Size = 16;
    short AudioFormat = 1;
    short NumChannels = 1;
    int SampleRate = 16000;
    int ByteRate = 32000;
    short BlockAlign = 2;
    short BitsPerSample = 16;
    char SubChunk2ID[4] = {'d', 'a', 't', 'a'};
    int SubChunk2Size = 32000;
    int i;
    short data[16000];
    for(i=0;i<16000;i++){
        data[i] = (short)10000*cos(2*pi*220*i/16000);
    }
    fwrite(&ChunkID, 4, sizeof(char),fptr);
    fwrite(&ChunkSize, 1, sizeof(int), fptr);
    fwrite(&Format, 4, sizeof(char), fptr);
    fwrite(&Subchunk1ID, 4, sizeof(char), fptr);
    fwrite(&Subchunk1Size, 1, sizeof(int), fptr);
    fwrite(&AudioFormat, 1, sizeof(short), fptr);
    fwrite(&NumChannels, 1, sizeof(short), fptr);
    fwrite(&SampleRate, 1, sizeof(int), fptr);
    fwrite(&ByteRate, 1, sizeof(int), fptr);
    fwrite(&BlockAlign, 1, sizeof(short), fptr);
    fwrite(&BitsPerSample, 1, sizeof(short), fptr);
    fwrite(&SubChunk2ID, 4, sizeof(char), fptr);
    fwrite(&SubChunk2Size, 1, sizeof(int),fptr);
    for(i=0;i<16000;i++){
        fwrite(&(data[i]), 1, sizeof(short), fptr);
    }
    fclose(fptr);
}