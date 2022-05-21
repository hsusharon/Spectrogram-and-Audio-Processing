#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void setting_1_1(short *data, int sample_rate, int count);
void setting_2_1(short *data, int sample_rate, int count);
void setting_3_1(short *data, int sample_rate, int count);
void setting_4_1(short *data, int sample_rate, int count);

void setting_1_2(short *data, int sample_rate, int count);
void setting_2_2(short *data, int sample_rate, int count);
void setting_3_2(short *data, int sample_rate, int count);
void setting_4_2(short *data, int sample_rate, int count);

void setting_1_3(short *data, int sample_rate, int count);
void setting_2_3(short *data, int sample_rate, int count);
void setting_3_3(short *data, int sample_rate, int count);
void setting_4_3(short *data, int sample_rate, int count);

void setting_1_4(short *data, int sample_rate, int count);
void setting_2_4(short *data, int sample_rate, int count);
void setting_3_4(short *data, int sample_rate, int count);
void setting_4_4(short *data, int sample_rate, int count);

void setting_1_5(short *data, int sample_rate, int count);
void setting_2_5(short *data, int sample_rate, int count);
void setting_3_5(short *data, int sample_rate, int count);
void setting_4_5(short *data, int sample_rate, int count);

void setting_1_6(short *data, int sample_rate, int count);
void setting_2_6(short *data, int sample_rate, int count);
void setting_3_6(short *data, int sample_rate, int count);
void setting_4_6(short *data, int sample_rate, int count);

void setting_1_7(short *data, int sample_rate, int count);
void setting_2_7(short *data, int sample_rate, int count);
void setting_3_7(short *data, int sample_rate, int count);
void setting_4_7(short *data, int sample_rate, int count);

void setting_1_8(short *data, int sample_rate, int count);
void setting_2_8(short *data, int sample_rate, int count);
void setting_3_8(short *data, int sample_rate, int count);
void setting_4_8(short *data, int sample_rate, int count);

void setting_1_9(short *data, int sample_rate, int count);
void setting_2_9(short *data, int sample_rate, int count);
void setting_3_9(short *data, int sample_rate, int count);
void setting_4_9(short *data, int sample_rate, int count);

void setting_1_10(short *data, int sample_rate, int count);
void setting_2_10(short *data, int sample_rate, int count);
void setting_3_10(short *data, int sample_rate, int count);
void setting_4_10(short *data, int sample_rate, int count);


float *DFT(short *data, int count);
float *f_DFT(float *data, int count);
void readfile50_8k();
void readfile50_16k();
void readfile55_8k();
void readfile55_16k();
void readfile200_8k();
void readfile200_16k();
void readfile220_8k();
void readfile220_16k();
void vowel8k();
void vowel16k();

int main(int argc, char** argv){
    printf("\n50-8k\n");
    readfile50_8k();
    printf("\n50-16k\n");
    readfile50_16k();
    printf("\n55-8k\n");
    readfile55_8k();
    printf("\n55-16k\n");
    readfile55_16k();
    printf("\n200-8k\n");
    readfile200_8k();
    printf("\n200-16k\n");
    readfile200_16k();
    printf("\n220-8k\n");
    readfile220_8k();
    printf("\n220-16k\n");
    readfile220_16k();
    printf("\n8k\n");
    vowel8k();
    printf("\n16k\n");
    vowel16k();
    return 0;
}
void readfile50_8k(){
    FILE *input_ptr = fopen("cos_50hz-8k.wav", "rb");
    if(input_ptr == NULL){
        printf("open wav file error");
    }
    char *trash = calloc(24, sizeof(char));
    int SampleRate;
    int ByteRate;
    short bit_per_sample;
    short BitPerSample;
    char SubChunk2ID[4];
    int SubChunk2Size;
    
    fread(trash, 24, sizeof(char), input_ptr);             //read header 
    fread(&SampleRate, 1, sizeof(int), input_ptr);
    fread(&ByteRate, 1, sizeof(int), input_ptr);
    fread(&bit_per_sample, 1, sizeof(short), input_ptr);
    fread(&BitPerSample, 1, sizeof(short), input_ptr);    
    fread(&SubChunk2ID, 4, sizeof(char), input_ptr);
    fread(&SubChunk2Size, 1, sizeof(int), input_ptr);

    printf("bit per sample = %d\n", bit_per_sample);
    printf("sample rate = %d\n", SampleRate);
    printf("chunk size = %d\n", SubChunk2Size);

    int count = SubChunk2Size/bit_per_sample;
    short *data = calloc(count, sizeof(bit_per_sample));
    int i;
    for(i=0;i<count;i++){                    //read data
        fread(data+i, 1, bit_per_sample, input_ptr);
    }
    setting_1_1(data, SampleRate, count);
    setting_2_1(data, SampleRate, count);
    setting_3_1(data, SampleRate, count);
    setting_4_1(data, SampleRate, count);

    free(trash);
    fclose(input_ptr);
}

void readfile50_16k(){
    FILE *input_ptr = fopen("cos_50hz-16k.wav", "rb");
    if(input_ptr == NULL){
        printf("open wav file error");
    }
    char *trash = calloc(24, sizeof(char));
    int SampleRate;
    int ByteRate;
    short bit_per_sample;
    short BitPerSample;
    char SubChunk2ID[4];
    int SubChunk2Size;
    
    fread(trash, 24, sizeof(char), input_ptr);                
    fread(&SampleRate, 1, sizeof(int), input_ptr);
    fread(&ByteRate, 1, sizeof(int), input_ptr);
    fread(&bit_per_sample, 1, sizeof(short), input_ptr);
    fread(&BitPerSample, 1, sizeof(short), input_ptr);    
    fread(&SubChunk2ID, 4, sizeof(char), input_ptr);
    fread(&SubChunk2Size, 1, sizeof(int), input_ptr);

    printf("bit per sample = %d\n", bit_per_sample);
    printf("sample rate = %d\n", SampleRate);
    printf("chunk size = %d\n", SubChunk2Size);

    int count = SubChunk2Size/bit_per_sample;
    short *data = calloc(count, sizeof(bit_per_sample));
    int i;
    for(i=0;i<count;i++){                   
        fread(data+i, 1, bit_per_sample, input_ptr);
    }
    setting_1_2(data, SampleRate, count);
    setting_2_2(data, SampleRate, count);
    setting_3_2(data, SampleRate, count);
    setting_4_2(data, SampleRate, count);

    free(trash);
    fclose(input_ptr);
}

void readfile55_8k(){
    FILE *input_ptr = fopen("cos_55hz-8k.wav", "rb");
    if(input_ptr == NULL){
        printf("open wav file error");
    }
    char *trash = calloc(24, sizeof(char));
    int SampleRate;
    int ByteRate;
    short bit_per_sample;
    short BitPerSample;
    char SubChunk2ID[4];
    int SubChunk2Size;
    
    fread(trash, 24, sizeof(char), input_ptr);                
    fread(&SampleRate, 1, sizeof(int), input_ptr);
    fread(&ByteRate, 1, sizeof(int), input_ptr);
    fread(&bit_per_sample, 1, sizeof(short), input_ptr);
    fread(&BitPerSample, 1, sizeof(short), input_ptr);    
    fread(&SubChunk2ID, 4, sizeof(char), input_ptr);
    fread(&SubChunk2Size, 1, sizeof(int), input_ptr);

    printf("bit per sample = %d\n", bit_per_sample);
    printf("sample rate = %d\n", SampleRate);
    printf("chunk size = %d\n", SubChunk2Size);

    int count = SubChunk2Size/bit_per_sample;
    short *data = calloc(count, sizeof(bit_per_sample));
    int i;
    for(i=0;i<count;i++){                   
        fread(data+i, 1, bit_per_sample, input_ptr);
    }
    setting_1_3(data, SampleRate, count);
    setting_2_3(data, SampleRate, count);
    setting_3_3(data, SampleRate, count);
    setting_4_3(data, SampleRate, count);

    free(trash);
    fclose(input_ptr);
}

void readfile55_16k(){
    FILE *input_ptr = fopen("cos_55hz-16k.wav", "rb");
    if(input_ptr == NULL){
        printf("open wav file error");
    }
    char *trash = calloc(24, sizeof(char));
    int SampleRate;
    int ByteRate;
    short bit_per_sample;
    short BitPerSample;
    char SubChunk2ID[4];
    int SubChunk2Size;
    
    fread(trash, 24, sizeof(char), input_ptr);                
    fread(&SampleRate, 1, sizeof(int), input_ptr);
    fread(&ByteRate, 1, sizeof(int), input_ptr);
    fread(&bit_per_sample, 1, sizeof(short), input_ptr);
    fread(&BitPerSample, 1, sizeof(short), input_ptr);    
    fread(&SubChunk2ID, 4, sizeof(char), input_ptr);
    fread(&SubChunk2Size, 1, sizeof(int), input_ptr);

    printf("bit per sample = %d\n", bit_per_sample);
    printf("sample rate = %d\n", SampleRate);
    printf("chunk size = %d\n", SubChunk2Size);

    int count = SubChunk2Size/bit_per_sample;
    short *data = calloc(count, sizeof(bit_per_sample));
    int i;
    for(i=0;i<count;i++){                   
        fread(data+i, 1, bit_per_sample, input_ptr);
    }
    setting_1_4(data, SampleRate, count);
    setting_2_4(data, SampleRate, count);
    setting_3_4(data, SampleRate, count);
    setting_4_4(data, SampleRate, count);

    free(trash);
    fclose(input_ptr);
}

void readfile200_8k(){
    FILE *input_ptr = fopen("cos_200hz-8k.wav", "rb");
    if(input_ptr == NULL){
        printf("open wav file error");
    }
    char *trash = calloc(24, sizeof(char));
    int SampleRate;
    int ByteRate;
    short bit_per_sample;
    short BitPerSample;
    char SubChunk2ID[4];
    int SubChunk2Size;
    
    fread(trash, 24, sizeof(char), input_ptr);                
    fread(&SampleRate, 1, sizeof(int), input_ptr);
    fread(&ByteRate, 1, sizeof(int), input_ptr);
    fread(&bit_per_sample, 1, sizeof(short), input_ptr);
    fread(&BitPerSample, 1, sizeof(short), input_ptr);    
    fread(&SubChunk2ID, 4, sizeof(char), input_ptr);
    fread(&SubChunk2Size, 1, sizeof(int), input_ptr);

    printf("bit per sample = %d\n", bit_per_sample);
    printf("sample rate = %d\n", SampleRate);
    printf("chunk size = %d\n", SubChunk2Size);

    int count = SubChunk2Size/bit_per_sample;
    short *data = calloc(count, sizeof(bit_per_sample));
    int i;
    for(i=0;i<count;i++){                   
        fread(data+i, 1, bit_per_sample, input_ptr);
    }
    setting_1_5(data, SampleRate, count);
    setting_2_5(data, SampleRate, count);
    setting_3_5(data, SampleRate, count);
    setting_4_5(data, SampleRate, count);

    free(trash);
    fclose(input_ptr);
}

void readfile200_16k(){
    FILE *input_ptr = fopen("cos_200hz-16k.wav", "rb");
    if(input_ptr == NULL){
        printf("open wav file error");
    }
    char *trash = calloc(24, sizeof(char));
    int SampleRate;
    int ByteRate;
    short bit_per_sample;
    short BitPerSample;
    char SubChunk2ID[4];
    int SubChunk2Size;
    
    fread(trash, 24, sizeof(char), input_ptr);                
    fread(&SampleRate, 1, sizeof(int), input_ptr);
    fread(&ByteRate, 1, sizeof(int), input_ptr);
    fread(&bit_per_sample, 1, sizeof(short), input_ptr);
    fread(&BitPerSample, 1, sizeof(short), input_ptr);    
    fread(&SubChunk2ID, 4, sizeof(char), input_ptr);
    fread(&SubChunk2Size, 1, sizeof(int), input_ptr);

    printf("bit per sample = %d\n", bit_per_sample);
    printf("sample rate = %d\n", SampleRate);
    printf("chunk size = %d\n", SubChunk2Size);

    int count = SubChunk2Size/bit_per_sample;
    short *data = calloc(count, sizeof(bit_per_sample));
    int i;
    for(i=0;i<count;i++){                   
        fread(data+i, 1, bit_per_sample, input_ptr);
    }
    setting_1_6(data, SampleRate, count);
    setting_2_6(data, SampleRate, count);
    setting_3_6(data, SampleRate, count);
    setting_4_6(data, SampleRate, count);

    free(trash);
    fclose(input_ptr);
}

void readfile220_8k(){
    FILE *input_ptr = fopen("cos_220hz-8k.wav", "rb");
    if(input_ptr == NULL){
        printf("open wav file error");
    }
    char *trash = calloc(24, sizeof(char));
    int SampleRate;
    int ByteRate;
    short bit_per_sample;
    short BitPerSample;
    char SubChunk2ID[4];
    int SubChunk2Size;
    
    fread(trash, 24, sizeof(char), input_ptr);                
    fread(&SampleRate, 1, sizeof(int), input_ptr);
    fread(&ByteRate, 1, sizeof(int), input_ptr);
    fread(&bit_per_sample, 1, sizeof(short), input_ptr);
    fread(&BitPerSample, 1, sizeof(short), input_ptr);    
    fread(&SubChunk2ID, 4, sizeof(char), input_ptr);
    fread(&SubChunk2Size, 1, sizeof(int), input_ptr);

    printf("bit per sample = %d\n", bit_per_sample);
    printf("sample rate = %d\n", SampleRate);
    printf("chunk size = %d\n", SubChunk2Size);

    int count = SubChunk2Size/bit_per_sample;
    short *data = calloc(count, sizeof(bit_per_sample));
    int i;
    for(i=0;i<count;i++){                   
        fread(data+i, 1, bit_per_sample, input_ptr);
    }
    setting_1_7(data, SampleRate, count);
    setting_2_7(data, SampleRate, count);
    setting_3_7(data, SampleRate, count);
    setting_4_7(data, SampleRate, count);

    free(trash);
    fclose(input_ptr);
}

void readfile220_16k(){
    FILE *input_ptr = fopen("cos_220hz-16k.wav", "rb");
    if(input_ptr == NULL){
        printf("open wav file error");
    }
    char *trash = calloc(24, sizeof(char));
    int SampleRate;
    int ByteRate;
    short bit_per_sample;
    short BitPerSample;
    char SubChunk2ID[4];
    int SubChunk2Size;
    
    fread(trash, 24, sizeof(char), input_ptr);                
    fread(&SampleRate, 1, sizeof(int), input_ptr);
    fread(&ByteRate, 1, sizeof(int), input_ptr);
    fread(&bit_per_sample, 1, sizeof(short), input_ptr);
    fread(&BitPerSample, 1, sizeof(short), input_ptr);    
    fread(&SubChunk2ID, 4, sizeof(char), input_ptr);
    fread(&SubChunk2Size, 1, sizeof(int), input_ptr);

    printf("bit per sample = %d\n", bit_per_sample);
    printf("sample rate = %d\n", SampleRate);
    printf("chunk size = %d\n", SubChunk2Size);

    int count = SubChunk2Size/bit_per_sample;
    short *data = calloc(count, sizeof(bit_per_sample));
    int i;
    for(i=0;i<count;i++){                   
        fread(data+i, 1, bit_per_sample, input_ptr);
    }
    setting_1_8(data, SampleRate, count);
    setting_2_8(data, SampleRate, count);
    setting_3_8(data, SampleRate, count);
    setting_4_8(data, SampleRate, count);

    free(trash);
    fclose(input_ptr);
}

void vowel8k(){
    FILE *input_ptr = fopen("vowel-8k.wav", "rb");
    if(input_ptr == NULL){
        printf("open wav file error");
    }
    printf("vowel8k\n");
    char *trash = calloc(24, sizeof(char));
    int SampleRate;
    int ByteRate;
    short bit_per_sample;
    short BitPerSample;
    char SubChunk2ID[4];
    int SubChunk2Size;
    
    fread(trash, 24, sizeof(char), input_ptr);                
    fread(&SampleRate, 1, sizeof(int), input_ptr);
    fread(&ByteRate, 1, sizeof(int), input_ptr);
    fread(&bit_per_sample, 1, sizeof(short), input_ptr);
    fread(&BitPerSample, 1, sizeof(short), input_ptr);    
    fread(&SubChunk2ID, 4, sizeof(char), input_ptr);
    fread(&SubChunk2Size, 1, sizeof(int), input_ptr);

    printf("bit per sample = %d\n", bit_per_sample);
    printf("sample rate = %d\n", SampleRate);
    printf("chunk size = %d\n", SubChunk2Size);

    int count = SubChunk2Size/bit_per_sample;
    short *data = calloc(count, sizeof(bit_per_sample));
    int i;
    for(i=0;i<count;i++){                   
        fread(data+i, 1, bit_per_sample, input_ptr);
    }
    setting_1_9(data, SampleRate, count);
    setting_2_9(data, SampleRate, count);
    setting_3_9(data, SampleRate, count);
    setting_4_9(data, SampleRate, count);

    free(trash);
    fclose(input_ptr);
}

void vowel16k(){
    FILE *input_ptr = fopen("vowel-16k.wav", "rb");
    if(input_ptr == NULL){
        printf("open wav file error");
    }
    printf("vowel16k\n");
    char *trash = calloc(24, sizeof(char));
    int SampleRate;
    int ByteRate;
    short bit_per_sample;
    short BitPerSample;
    char SubChunk2ID[4];
    int SubChunk2Size;
    
    fread(trash, 24, sizeof(char), input_ptr);                
    fread(&SampleRate, 1, sizeof(int), input_ptr);
    fread(&ByteRate, 1, sizeof(int), input_ptr);
    fread(&bit_per_sample, 1, sizeof(short), input_ptr);
    fread(&BitPerSample, 1, sizeof(short), input_ptr);    
    fread(&SubChunk2ID, 4, sizeof(char), input_ptr);
    fread(&SubChunk2Size, 1, sizeof(int), input_ptr);

    printf("bit per sample = %d\n", bit_per_sample);
    printf("sample rate = %d\n", SampleRate);
    printf("chunk size = %d\n", SubChunk2Size);

    int count = SubChunk2Size/bit_per_sample;
    short *data = calloc(count, sizeof(bit_per_sample));
    int i;
    for(i=0;i<count;i++){                   
        fread(data+i, 1, bit_per_sample, input_ptr);
    }
    setting_1_10(data, SampleRate, count);
    setting_2_10(data, SampleRate, count);
    setting_3_10(data, SampleRate, count);
    setting_4_10(data, SampleRate, count);

    free(trash);
    fclose(input_ptr);
}
//window size = 5ms
//window type = rectangular
//DFT window = 8ms
//frame interval = 5ms
void setting_1_1(short *data, int sample_rate,int count){  
    printf("Setting 1 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_50hz-8k_st1.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk;i++){         // for every chunk  
        for(j=0;j<dft_window;j++){   //zero padding nothing will be done if it is multiplied to a rectangular function
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);   //dft
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));  //write magnitude into text file
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 1\n");
}

//window size = 5ms
//window type = hamming
//DFT window = 8ms
//frame interval = 5ms
void setting_2_1(short *data, int sample_rate, int count){
    printf("Setting 2 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    FILE *fptr = fopen("cos_50hz-8k_st2.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;  
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    short *data2 = calloc(num, sizeof(short));
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk;i++){        
        for(n=0;n<num;n++){         // hamming window
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        }     
        for(j=0;j<dft_window;j++){     //zero padding
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);  //due to the data pass into dft is float there is another function to deal with the data
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));  // write magnitude into text file
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 2\n");

}

//window size = 20ms
//widow type = rectangular
//DFT window size = 32ms
//Frame inteval = 10ms (overlapping)
void setting_3_1(short *data, int sample_rate, int count){
    printf("Setting 3 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_50hz-8k_st3.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk*2;i++){          
        for(j=0;j<dft_window;j++){   //zero padding
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);   //move th flag pointer only half of num to get overlapping
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 3\n");

}

//windoe size = 20ms
//window type = hamming
//DFT window size = 32ms
//frame interval = 10ms (overlapping)
void setting_4_1(short *data, int sample_rate, int count){
    printf("Setting 4 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    float *mag;
    FILE *fptr = fopen("cos_50hz-8k_st4.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *data2 = calloc(num, sizeof(short)); 
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk*2;i++){        //windowing 
        for(n=0;n<num;n++){                      //hamming window
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        } 
        for(j=0;j<dft_window;j++){   //zero padding
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);   //only move the flag half a num to cause overlapping
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 4\n");


}
//different data type of transfering data into dft
// short data->

void setting_1_2(short *data, int sample_rate,int count){  
    printf("Setting 1 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_50hz-16k_st1.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk;i++){        
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 1\n");
}

//window size = 5ms
//window type = hamming
//DFT window = 8ms
//frame interval = 5ms
void setting_2_2(short *data, int sample_rate, int count){
    printf("Setting 2 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    FILE *fptr = fopen("cos_50hz-16k_st2.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;  
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    short *data2 = calloc(num, sizeof(short));
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk;i++){        
        for(n=0;n<num;n++){    
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        }     
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 2\n");

}

//window size = 20ms
//widow type = rectangular
//DFT window size = 32ms
//Frame inteval = 10ms (overlapping)
void setting_3_2(short *data, int sample_rate, int count){
    printf("Setting 3 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_50hz-16k_st3.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk*2;i++){         
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 3\n");

}

//windoe size = 20ms
//window type = hamming
//DFT window size = 32ms
//frame interval = 10ms (overlapping)
void setting_4_2(short *data, int sample_rate, int count){
    printf("Setting 4 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    float *mag;
    FILE *fptr = fopen("cos_50hz-16k_st4.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *data2 = calloc(num, sizeof(short)); 
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk*2;i++){        //windowing 
        for(n=0;n<num;n++){    //hamming window
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        } 
        for(j=0;j<dft_window;j++){   //zero padding
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 4\n");


}

void setting_1_3(short *data, int sample_rate,int count){  
    printf("Setting 1 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_55hz-8k_st1.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk;i++){        
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 1\n");
}

//window size = 5ms
//window type = hamming
//DFT window = 8ms
//frame interval = 5ms
void setting_2_3(short *data, int sample_rate, int count){
    printf("Setting 2 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    FILE *fptr = fopen("cos_55hz-8k_st2.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;  
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    short *data2 = calloc(num, sizeof(short));
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk;i++){        
        for(n=0;n<num;n++){    
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        }     
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 2\n");

}

//window size = 20ms
//widow type = rectangular
//DFT window size = 32ms
//Frame inteval = 10ms (overlapping)
void setting_3_3(short *data, int sample_rate, int count){
    printf("Setting 3 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_55hz-8k_st3.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk*2;i++){         
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 3\n");

}

//windoe size = 20ms
//window type = hamming
//DFT window size = 32ms
//frame interval = 10ms (overlapping)
void setting_4_3(short *data, int sample_rate, int count){
    printf("Setting 4 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    float *mag;
    FILE *fptr = fopen("cos_55hz-8k_st4.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *data2 = calloc(num, sizeof(short)); 
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk*2;i++){        //windowing 
        for(n=0;n<num;n++){    //hamming window
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        } 
        for(j=0;j<dft_window;j++){   //zero padding
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 4\n");


}

void setting_1_4(short *data, int sample_rate,int count){  
    printf("Setting 1 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_55hz-16k_st1.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk;i++){        
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 1\n");
}

//window size = 5ms
//window type = hamming
//DFT window = 8ms
//frame interval = 5ms
void setting_2_4(short *data, int sample_rate, int count){
    printf("Setting 2 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    FILE *fptr = fopen("cos_55hz-16k_st2.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;  
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    short *data2 = calloc(num, sizeof(short));
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk;i++){        
        for(n=0;n<num;n++){    
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        }     
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 2\n");

}

//window size = 20ms
//widow type = rectangular
//DFT window size = 32ms
//Frame inteval = 10ms (overlapping)
void setting_3_4(short *data, int sample_rate, int count){
    printf("Setting 3 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_55hz-16k_st3.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk*2;i++){         
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 3\n");

}

//windoe size = 20ms
//window type = hamming
//DFT window size = 32ms
//frame interval = 10ms (overlapping)
void setting_4_4(short *data, int sample_rate, int count){
    printf("Setting 4 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    float *mag;
    FILE *fptr = fopen("cos_55hz-16k_st4.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *data2 = calloc(num, sizeof(short)); 
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk*2;i++){        //windowing 
        for(n=0;n<num;n++){    //hamming window
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        } 
        for(j=0;j<dft_window;j++){   //zero padding
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 4\n");


}

void setting_1_5(short *data, int sample_rate,int count){  
    printf("Setting 1 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_200hz-8k_st1.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk;i++){        
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 1\n");
}

//window size = 5ms
//window type = hamming
//DFT window = 8ms
//frame interval = 5ms
void setting_2_5(short *data, int sample_rate, int count){
    printf("Setting 2 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    FILE *fptr = fopen("cos_200hz-8k_st2.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;  
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    short *data2 = calloc(num, sizeof(short));
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk;i++){        
        for(n=0;n<num;n++){    
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        }     
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 2\n");

}

//window size = 20ms
//widow type = rectangular
//DFT window size = 32ms
//Frame inteval = 10ms (overlapping)
void setting_3_5(short *data, int sample_rate, int count){
    printf("Setting 3 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_200hz-8k_st3.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk*2;i++){         
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 3\n");

}

//windoe size = 20ms
//window type = hamming
//DFT window size = 32ms
//frame interval = 10ms (overlapping)
void setting_4_5(short *data, int sample_rate, int count){
    printf("Setting 4 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    float *mag;
    FILE *fptr = fopen("cos_200hz-8k_st4.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *data2 = calloc(num, sizeof(short)); 
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk*2;i++){        //windowing 
        for(n=0;n<num;n++){    //hamming window
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        } 
        for(j=0;j<dft_window;j++){   //zero padding
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 4\n");


}

void setting_1_6(short *data, int sample_rate,int count){  
    printf("Setting 1 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_200hz-16k_st1.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk;i++){        
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 1\n");
}

//window size = 5ms
//window type = hamming
//DFT window = 8ms
//frame interval = 5ms
void setting_2_6(short *data, int sample_rate, int count){
    printf("Setting 2 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    FILE *fptr = fopen("cos_200hz-16k_st2.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;  
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    short *data2 = calloc(num, sizeof(short));
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk;i++){        
        for(n=0;n<num;n++){    
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        }     
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 2\n");

}

//window size = 20ms
//widow type = rectangular
//DFT window size = 32ms
//Frame inteval = 10ms (overlapping)
void setting_3_6(short *data, int sample_rate, int count){
    printf("Setting 3 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_200hz-16k_st3.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk*2;i++){         
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 3\n");

}

//windoe size = 20ms
//window type = hamming
//DFT window size = 32ms
//frame interval = 10ms (overlapping)
void setting_4_6(short *data, int sample_rate, int count){
    printf("Setting 4 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    float *mag;
    FILE *fptr = fopen("cos_200hz-16k_st4.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *data2 = calloc(num, sizeof(short)); 
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk*2;i++){        //windowing 
        for(n=0;n<num;n++){    //hamming window
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        } 
        for(j=0;j<dft_window;j++){   //zero padding
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 4\n");


}

void setting_1_7(short *data, int sample_rate,int count){  
    printf("Setting 1 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_220hz-8k_st1.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk;i++){        
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 1\n");
}

//window size = 5ms
//window type = hamming
//DFT window = 8ms
//frame interval = 5ms
void setting_2_7(short *data, int sample_rate, int count){
    printf("Setting 2 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    FILE *fptr = fopen("cos_220hz-8k_st2.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;  
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    short *data2 = calloc(num, sizeof(short));
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk;i++){        
        for(n=0;n<num;n++){    
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        }     
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 2\n");

}

//window size = 20ms
//widow type = rectangular
//DFT window size = 32ms
//Frame inteval = 10ms (overlapping)
void setting_3_7(short *data, int sample_rate, int count){
    printf("Setting 3 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_220hz-8k_st3.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk*2;i++){         
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 3\n");

}

//windoe size = 20ms
//window type = hamming
//DFT window size = 32ms
//frame interval = 10ms (overlapping)
void setting_4_7(short *data, int sample_rate, int count){
    printf("Setting 4 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    float *mag;
    FILE *fptr = fopen("cos_220hz-8k_st4.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *data2 = calloc(num, sizeof(short)); 
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk*2;i++){        //windowing 
        for(n=0;n<num;n++){    //hamming window
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        } 
        for(j=0;j<dft_window;j++){   //zero padding
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 4\n");


}

void setting_1_8(short *data, int sample_rate,int count){  
    printf("Setting 1 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_220hz-16k_st1.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk;i++){        
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 1\n");
}

//window size = 5ms
//window type = hamming
//DFT window = 8ms
//frame interval = 5ms
void setting_2_8(short *data, int sample_rate, int count){
    printf("Setting 2 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    FILE *fptr = fopen("cos_220hz-16k_st2.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;  
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    short *data2 = calloc(num, sizeof(short));
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk;i++){        
        for(n=0;n<num;n++){    
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        }     
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 2\n");

}

//window size = 20ms
//widow type = rectangular
//DFT window size = 32ms
//Frame inteval = 10ms (overlapping)
void setting_3_8(short *data, int sample_rate, int count){
    printf("Setting 3 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("cos_220hz-16k_st3.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk*2;i++){         
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 3\n");

}

//windoe size = 20ms
//window type = hamming
//DFT window size = 32ms
//frame interval = 10ms (overlapping)
void setting_4_8(short *data, int sample_rate, int count){
    printf("Setting 4 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    float *mag;
    FILE *fptr = fopen("cos_220hz-16k_st4.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *data2 = calloc(num, sizeof(short)); 
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk*2;i++){        //windowing 
        for(n=0;n<num;n++){    //hamming window
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        } 
        for(j=0;j<dft_window;j++){   //zero padding
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 4\n");


}

void setting_1_9(short *data, int sample_rate,int count){  
    printf("Setting 1 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("vowel-8k_st1.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk;i++){        
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 1\n");
}

//window size = 5ms
//window type = hamming
//DFT window = 8ms
//frame interval = 5ms
void setting_2_9(short *data, int sample_rate, int count){
    printf("Setting 2 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    FILE *fptr = fopen("vowel-8k_st2.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;  
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    short *data2 = calloc(num, sizeof(short));
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk;i++){        
        for(n=0;n<num;n++){    
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        }     
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 2\n");

}

//window size = 20ms
//widow type = rectangular
//DFT window size = 32ms
//Frame inteval = 10ms (overlapping)
void setting_3_9(short *data, int sample_rate, int count){
    printf("Setting 3 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("vowel-8k_st3.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk*2;i++){         
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 3\n");

}

//windoe size = 20ms
//window type = hamming
//DFT window size = 32ms
//frame interval = 10ms (overlapping)
void setting_4_9(short *data, int sample_rate, int count){
    printf("Setting 4 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    float *mag;
    FILE *fptr = fopen("vowel-8k_st4.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *data2 = calloc(num, sizeof(short)); 
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk*2;i++){        //windowing 
        for(n=0;n<num;n++){    //hamming window
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        } 
        for(j=0;j<dft_window;j++){   //zero padding
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 4\n");


}

void setting_1_10(short *data, int sample_rate,int count){  
    printf("Setting 1 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("vowel-16k_st1.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk;i++){        
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 1\n");
}

//window size = 5ms
//window type = hamming
//DFT window = 8ms
//frame interval = 5ms
void setting_2_10(short *data, int sample_rate, int count){
    printf("Setting 2 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    FILE *fptr = fopen("vowel-16k_st2.txt", "wb");
    int num = sample_rate*0.005;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.008;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;  
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    short *data2 = calloc(num, sizeof(short));
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk;i++){        
        for(n=0;n<num;n++){    
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        }     
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+num;
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 2\n");

}

//window size = 20ms
//widow type = rectangular
//DFT window size = 32ms
//Frame inteval = 10ms (overlapping)
void setting_3_10(short *data, int sample_rate, int count){
    printf("Setting 3 processing ...\n");
    int i,j,k,flag=0;
    FILE *fptr = fopen("vowel-16k_st3.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *mag;
    for(i=0;i<chunk*2;i++){         
        for(j=0;j<dft_window;j++){   
            if(j<num){
                *(dft_data+j) = *(data+j+flag);
            }else{
                *(dft_data+j) = 0;
            }
        }
        mag = DFT(dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    printf("Finish setting 3\n");

}

//windoe size = 20ms
//window type = hamming
//DFT window size = 32ms
//frame interval = 10ms (overlapping)
void setting_4_10(short *data, int sample_rate, int count){
    printf("Setting 4 processing ...\n");
    int i,j,k,n,flag=0;
    float pi = acos(-1);
    float *mag;
    FILE *fptr = fopen("vowel-16k_st4.txt", "wb");
    int num = sample_rate*0.02;   
    printf("num = %d  ", num);
    int dft_window = sample_rate*0.032;  
    printf("dft_window = %d  ", dft_window);
    int chunk = count/num;   
    printf("chunk = %d\n", chunk);
    short *data2 = calloc(num, sizeof(short)); 
    short *dft_data = calloc(dft_window, sizeof(short));  
    float *f_dft_data = calloc(dft_window, sizeof(float));
    for(i=0;i<chunk*2;i++){        //windowing 
        for(n=0;n<num;n++){    //hamming window
            *(data2+n) = *(data+n+flag);
            *(f_dft_data+n) = 0.54 * *(data2+n) + 0.46 * *(data2+n) * cos(2*pi*n/num);
        } 
        for(j=0;j<dft_window;j++){   //zero padding
            if(j<num){
                *(f_dft_data+j) = *(f_dft_data+j);
            }else{
                *(f_dft_data+j) = 0.0;
            }
        }
        mag = f_DFT(f_dft_data, dft_window);
        for(k=0;k<dft_window;k++){
            fprintf(fptr, "%f ", *(mag+k));
        }
        fprintf(fptr, "\n");
        flag = flag+(num/2);
    }
    fclose(fptr);
    free(dft_data);
    free(f_dft_data);
    printf("Finish setting 4\n");


}
//short data type->
float *DFT(short *data, int count){
    int i, j;     
    float pi = acos(-1);                                
    float w;
    float *magnitude = calloc(count,sizeof(float));             
    w = 2*pi/count;         
    float cos_data[count], sin_data[count];         

    for(i=0; i<count; i++){
        cos_data[i] = 0;     //initialize 
        sin_data[i] = 0;     //initialize
        for(j=0; j<count; j++){
            cos_data[i] = cos_data[i] + data[j]*cos(i*j*w);    
            sin_data[i] = sin_data[i] - data[j]*sin(i*j*w);    
        }
        *(magnitude+i) = 20*log10(sqrt(cos_data[i] * cos_data[i] + sin_data[i] * sin_data[i]));  //calculate the magnitde and change it to db
    }
    return(magnitude);
    free(magnitude);
}
//float data type->
float *f_DFT(float *data, int count){
    int i, j;     
    float pi = acos(-1);                                
    float w;
    float *magnitude = calloc(count,sizeof(float));             
    w = 2*pi/count;         
    float cos_data[count], sin_data[count];         

    for(i=0; i<count; i++){
        cos_data[i] = 0;     //initialize 
        sin_data[i] = 0;     //initialize
        for(j=0; j<count; j++){
            cos_data[i] = cos_data[i] + data[j]*cos(i*j*w);    
            sin_data[i] = sin_data[i] - data[j]*sin(i*j*w);    
        }
        *(magnitude+i) = 20*log10(sqrt(cos_data[i] * cos_data[i] + sin_data[i] * sin_data[i]));  //calculate the magnitde and change it to db
    }
    return(magnitude);
    free(magnitude);
}

