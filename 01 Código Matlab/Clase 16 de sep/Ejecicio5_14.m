%Ejercicio 5-14 

%Datos:
%       Input: r(t) = 1/2*t^2
%       System: G(s) = 2/s^2+s+2

clear all;
clc;

%--------------------------------------------------------------------------
%SYSTEM:
disp('El sistema en lazo cerrado es: ')
G = tf([2],[1 1 2])
%--------------------------------------------------------------------------

%--------------------------------------------------------------------------
%INPUT & OUTPUT:
t = 0:0.1:10;
r = 0.5*t.^2;
y = lsim(G,r,t);
disp('Simulando el sistema para una entrada parabolica>>> ')
plot(t,r,'-.',t,y,'+');
title('Respuesta del sistema a una entrada aceleración ');
xlabel('Time[s]')
ylabel('Input[-.-.-] & Output[+++]')
%--------------------------------------------------------------------------




