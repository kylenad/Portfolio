clear;
load DataELE313Filter3;
whos; 
load Handel.mat; 
%sound(zt,fs);

prompt = "Choose frequency 1 through 5";
et = input(prompt);

ws = 2*pi*fs;

N = length(zt)*16;
zw = fftshift(fft(zt, N))*0.01;

s
w = linspace(-fs*pi, fs*pi, length(zw));

plot(w, abs(zw), 'LineWidth', 3, 'Color', [1,1,0]);


xlim([-(ws/2),(ws/2)]);

ylim([-5,10]);

grid on;

title('title');

xlabel('xlabel');

ylabel('ylabel');


%make if statements for fc values (don't include 2*pi)
if et == 1
    fc1 = 1;
    fc2 = 250;
elseif et == 2 
        fc1 = 250;
        fc2 = 500;
elseif et == 3
        fc1 = 500;
        fc2 = 2000;
elseif et == 4
        fc1 = 2000;
        fc2 = 4000;
elseif et == 5 
        fc1 = 4000;
        fc2 = 5000;
end


myfilter = designfilt('bandpassiir','halfpowerfrequency1',fc1, 'halfpowerfrequency2',fc2, 'FilterOrder',50,'SampleRate',fs);

%yt = filter(myfilter, zt);

yt = filter(myfilter,zt);

yw = fftshift(fft(zt, N))*0.01;


plot(w, abs(yw), 'LineWidth', 3, 'Color', [0,1,1]);

sound(yt,fs);
