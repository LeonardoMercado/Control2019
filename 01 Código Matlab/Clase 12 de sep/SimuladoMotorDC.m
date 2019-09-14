%%MOTORES DC
%Script para la simulación y visualización del comportamiento de un motor 
%dc con escobillas y de imanes permanentes

clear all;
clc

%--------------------------------------------------------------------------
%PARÁMETROS:
%Momento de inercia del rotor
J = 0.01; %Kg.m^2
%Constante de fricción viscosa
b = 0.1;  %N.m.s
%Constante de fuerza electromotriz 
Ke = 0.01; %V/rad/s
%Constante de torque del motor
Kt = 0.01; %N.m/A
%Resistencia de la armadura
R = 1;     %Ohm
%Inductancia de la armadura
L = 0.5;   %H
%Como Kt = Ke se designa una unica variable para los dos parámetros:
K = 0.01;
%--------------------------------------------------------------------------

%--------------------------------------------------------------------------
%FUNCIÓN DE TRANSFERENCIA: 
s = tf('s');
disp('La función de transferencua del motor es: ')
G = K/((J*s+b)*(L*s+R)+K^2)
num = K;                        %Numerador de la tf para el GB en simulink
dem = [L*J R*J+b*L K^2+b*R];    %Denominador de la tf para el GB en simulink
%--------------------------------------------------------------------------


%--------------------------------------------------------------------------
%VARIABLES DE ESTADO: 
disp('En variables de estado el motor es: ')
A = [-b/J   K/J;
    -K/L   -R/L];
B = [0;
    1/L];
C = [1   0];
D = 0;
G_ss = ss(A,B,C,D)
%--------------------------------------------------------------------------

%--------------------------------------------------------------------------
%SIMULACION A ENTRADAS DEL SISTEMA
disp('Visualicemos la respuesta al paso del sistema')
step(G,G_ss)
%--------------------------------------------------------------------------
