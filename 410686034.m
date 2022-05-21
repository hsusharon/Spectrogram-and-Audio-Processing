s1_1 = load('cos_50hz-8k_st1.txt');
s1_2 = load('cos_50hz-8k_st2.txt');
s1_3 = load('cos_50hz-8k_st3.txt');
s1_4 = load('cos_50hz-8k_st4.txt');

s2_1 = load('cos_50hz-16k_st1.txt');
s2_2 = load('cos_50hz-16k_st2.txt');
s2_3 = load('cos_50hz-16k_st3.txt');
s2_4 = load('cos_50hz-16k_st4.txt');

s3_1 = load('cos_55hz-8k_st1.txt');
s3_2 = load('cos_55hz-8k_st2.txt');
s3_3 = load('cos_55hz-8k_st3.txt');
s3_4 = load('cos_55hz-8k_st4.txt');

s4_1 = load('cos_55hz-16k_st1.txt');
s4_2 = load('cos_55hz-16k_st2.txt');
s4_3 = load('cos_55hz-16k_st3.txt');
s4_4 = load('cos_55hz-16k_st4.txt');

s5_1 = load('cos_200hz-8k_st1.txt');
s5_2 = load('cos_200hz-8k_st2.txt');
s5_3 = load('cos_200hz-8k_st3.txt');
s5_4 = load('cos_200hz-8k_st4.txt');

s6_1 = load('cos_200hz-16k_st1.txt');
s6_2 = load('cos_200hz-16k_st2.txt');
s6_3 = load('cos_200hz-16k_st3.txt');
s6_4 = load('cos_200hz-16k_st4.txt');

s7_1 = load('cos_220hz-8k_st1.txt');
s7_2 = load('cos_220hz-8k_st2.txt');
s7_3 = load('cos_220hz-8k_st3.txt')
s7_4 = load('cos_220hz-8k_st4.txt');

s8_1 = load('cos_220hz-16k_st1.txt');
s8_2 = load('cos_220hz-16k_st2.txt');
s8_3 = load('cos_220hz-16k_st3.txt');
s8_4 = load('cos_220hz-16k_st4.txt');

s9_1 = load('vowel-8k_st1.txt');
s9_2 = load('vowel-8k_st2.txt');
s9_3 = load('vowel-8k_st3.txt');
s9_4 = load('vowel-8k_st4.txt');

s10_1 = load('vowel-16k_st1.txt');
s10_2 = load('vowel-16k_st2.txt');
s10_3 = load('vowel-16k_st3.txt');
s10_4 = load('vowel-16k_st4.txt');

figure(1)
subplot(2,2,1)
s1_11 = s1_1';
imagesc(s1_11);
subplot(2,2,2)
s1_12 = s1_2';
imagesc(s1_12);
subplot(2,2,3)
s1_13 = s1_3';
imagesc(s1_13);
subplot(2,2,4)
s1_14 = s1_4';
imagesc(s1_14);

figure(2)
subplot(2,2,1)
s2_11 = s2_1';
imagesc(s2_11);
subplot(2,2,2)
s2_12 = s2_2';
imagesc(s2_12);
subplot(2,2,3)
s2_13 = s2_3';
imagesc(s2_13);
subplot(2,2,4)
s2_14 = s2_4';
imagesc(s2_14);

figure(3)
subplot(2,2,1)
s3_11 = s3_1';
imagesc(s3_11);
subplot(2,2,2)
s3_12 = s3_2';
imagesc(s3_12);
subplot(2,2,3)
s3_13 = s3_3';
imagesc(s3_13);
subplot(2,2,4)
s3_14 = s3_4';
imagesc(s3_14);

figure(4)
subplot(2,2,1)
s4_11 = s4_1';
imagesc(s4_11);
subplot(2,2,2)
s4_12 = s4_2';
imagesc(s4_12);
subplot(2,2,3)
s4_13 = s4_3';
imagesc(s4_13);
subplot(2,2,4)
s4_14 = s4_4';
imagesc(s4_14);

figure(5)
subplot(2,2,1)
s5_11 = s5_1';
imagesc(s5_11);
subplot(2,2,2)
s5_12 = s5_2';
imagesc(s5_12);
subplot(2,2,3)
s5_13 = s5_3';
imagesc(s5_13);
subplot(2,2,4)
s5_14 = s5_4';
imagesc(s5_14);

figure(6)
subplot(2,2,1)
s6_11 = s6_1';
imagesc(s6_11);
subplot(2,2,2)
s6_12 = s6_2';
imagesc(s6_12);
subplot(2,2,3)
s6_13 = s6_3';
imagesc(s6_13);
subplot(2,2,4)
s6_14 = s6_4';
imagesc(s6_14);

figure(7)
subplot(2,2,1)
s7_11 = s7_1';
imagesc(s7_11);
subplot(2,2,2)
s7_12 = s7_2';
imagesc(s7_12);
subplot(2,2,3)
s7_13 = s7_3';
imagesc(s7_13);
subplot(2,2,4)
s7_14 = s7_4';
imagesc(s7_14);

figure(8)
subplot(2,2,1)
s8_11 = s8_1';
imagesc(s8_11);
subplot(2,2,2)
s8_12 = s8_2';
imagesc(s8_12);
subplot(2,2,3)
s8_13 = s8_3';
imagesc(s8_13);
subplot(2,2,4)
s8_14 = s8_4';
imagesc(s8_14);

figure(9)
subplot(2,2,1)
s9_11 = s9_1';
imagesc(s9_11);
subplot(2,2,2)
s9_12 = s9_2';
imagesc(s9_12);
subplot(2,2,3)
s9_13 = s9_3';
imagesc(s9_13);
subplot(2,2,4)
s9_14 = s9_4';
imagesc(s9_14);

figure(10)
subplot(2,2,1)
s10_11 = s10_1';
imagesc(s10_11);
subplot(2,2,2)
s10_12 = s10_2';
imagesc(s10_12);
subplot(2,2,3)
s10_13 = s10_3';
imagesc(s10_13);
subplot(2,2,4)
s10_14 = s10_4';
imagesc(s10_14);
