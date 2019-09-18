%Ejercicio 5-15

%Datos:
%       G(s) = 1/s^2+2*cita*s+1
%       Input= 1/s
%       Gráficar output para cita = [0, 0.2, 0.4, 0.6, 0.8, 1]

clear all;
clc;

%--------------------------------------------------------------------------
%SYSTEM:
    for n = 1:1:6
        cita = (n-1)*0.2;
        text = "Calculando para {zita}" + "= " + cita ;
        disp(text)
        G = tf([1],[1 2*cita 1]);
        step(G,50);
        hold all
    end
%--------------------------------------------------------------------------
%DATA SET output
title('Respuesta al paso para diferentes valores de \zeta')
xlabel('Time')
ylabel('OUTPUT')
legend('\zeta = 0','\zeta = 0.2','\zeta = 0.4','\zeta = 0.6','\zeta = 0.8','\zeta = 1')
gtext('\zeta = 0'),
gtext('\zeta = 0.2')
gtext('\zeta = 0.4')
gtext('\zeta = 0.6')
gtext('\zeta = 0.8')
gtext('\zeta = 1.0')
%--------------------------------------------------------------------------



