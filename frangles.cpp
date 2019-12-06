#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <bits/stdc++.h>
#define PI 3.14159265
#define largurax 900
#define alturay 600


sf::RectangleShape enemy1(sf::Vector2f(18, 18));

sf::RectangleShape shopa(sf::Vector2f(18, 18));

sf::RectangleShape enemy2(sf::Vector2f(18, 18));

sf::RectangleShape enemy3(sf::Vector2f(18, 18));

/*
g++ -c frangles.cpp && g++ frangles.cpp -o executa -lsfml-system -lsfml-graphics -lsfml-window && ./executa
*/


//usar o produto interno

long double get_dist(long double x,long double y,long double x2,long double y2){
    std ::cout << "x: "<< x << "y "<< y << "x2 " << x2 << "y2 " <<y2 << "\n";
    long double result;
    result = (x-x2)*(x-x2) + (y-y2)*(y-y2);
    std :: cout << "result " << result<< "\n";
    result = sqrt(result);
    std :: cout << "result " << result<< "\n";
    return result;
}

void CalculaReta(int indi, long double *pontos){
    long double xzao, m, m1,Z,Z2, xzao2, m2,yzao,yzao2;
    float nove = 9.0;
    if(indi == 1){
        if(enemy1.getPosition().x > shopa.getPosition().x && enemy1.getPosition().y > shopa.getPosition().y){
            long double var1;
            m1 = ((enemy1.getPosition().y+9-shopa.getPosition().y));

            var1 = alturay - (shopa.getPosition().y+9);
            m1 = m1/var1;

            var1 = (enemy1.getPosition().x - (shopa.getPosition().x+9));

            xzao2 = var1/m1 + shopa.getPosition().x+9;

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao2;
            pontos[3] = 600.f;

            m1 = (enemy1.getPosition().y-(shopa.getPosition().y+9));

            var1 = alturay - (shopa.getPosition().y+9);
            m1 = m1/var1;
            
            var1 = ((enemy1.getPosition().x+9) - (shopa.getPosition().x));

            xzao = var1/m1 + shopa.getPosition().x+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 600.f;

        }else if(enemy1.getPosition().x > shopa.getPosition().x && enemy1.getPosition().y < shopa.getPosition().y){
            long double var1;
            m1 = ((shopa.getPosition().y+9)-enemy1.getPosition().y)/(shopa.getPosition().y+9);

            var1 = (enemy1.getPosition().x - (shopa.getPosition().x+9));

            xzao2 = var1/m1 + shopa.getPosition().x+9;

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao2;
            pontos[3] = 0.f;

            m1 = ((shopa.getPosition().y)-(enemy1.getPosition().y+9))/(shopa.getPosition().y+9);

            var1 = ((enemy1.getPosition().x+9) - (shopa.getPosition().x));

            xzao = var1/m1 + shopa.getPosition().x+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 0.f;
        }else if(enemy1.getPosition().x < shopa.getPosition().x && enemy1.getPosition().y > shopa.getPosition().y){
            long double var1,var2;


            var2 = (enemy1.getPosition().y) - (shopa.getPosition().y+9);
            m1 = (shopa.getPosition().x+9) - (enemy1.getPosition().x);

            var1 = var2/m1; 
            var2 = shopa.getPosition().y-9;
            xzao = (shopa.getPosition().x+9) - (var2/var1) ; 

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao;
            pontos[3] = 600.f;

            var2 = (enemy1.getPosition().y+18)-(shopa.getPosition().y+9);
            m1 = (shopa.getPosition().x+9) - (enemy1.getPosition().x+18);

            var1 = var2/m1; 
            var2 = shopa.getPosition().y-9;
            xzao = (shopa.getPosition().x+9) - (var2/var1);

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 600.f;


        }else if(enemy1.getPosition().x < shopa.getPosition().x && enemy1.getPosition().y < shopa.getPosition().y){
            long double var1,var2;

            var2 = (shopa.getPosition().y+9) - enemy1.getPosition().y;
            m1 = (shopa.getPosition().x+9) - (enemy1.getPosition().x+18);

            var1 = var2/m1; 
            var2 = shopa.getPosition().y+9;
            xzao = shopa.getPosition().x+9 - (var2/var1) ; 

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao;
            pontos[3] = 0.f;

            var2 = (shopa.getPosition().y+9) - (enemy1.getPosition().y+18);
            m1 = (shopa.getPosition().x+9) - (enemy1.getPosition().x);

            var1 = var2/m1; 
            var2 = shopa.getPosition().y+9;
            xzao = shopa.getPosition().x+9 - (var2/var1);

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 0.f;

        }else if(enemy1.getPosition().x > shopa.getPosition().x && enemy1.getPosition().y == shopa.getPosition().y){
            Z = get_dist(shopa.getPosition().x+9,shopa.getPosition().y,enemy1.getPosition().x,enemy1.getPosition().y);    
            //m =variação de y / variação de x
            m1 = atan2 (9,Z);
            m1 = sin(m1);
            yzao = (m1 * (shopa.getPosition().x))+9;
            yzao2 = (shopa.getPosition().y+9)-yzao; 

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = 900.f;
            pontos[3] = yzao2;

            yzao = yzao + shopa.getPosition().y+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = 900.f;
            pontos[7] = yzao;
        }else if(enemy1.getPosition().x < shopa.getPosition().x && enemy1.getPosition().y == shopa.getPosition().y){
            Z = get_dist(shopa.getPosition().x,shopa.getPosition().y,enemy1.getPosition().x+18,enemy1.getPosition().y);        
            //m =variação de y / variação de x
            m1 = atan2 (nove,Z);
            m1 = sin(m1);
            yzao = (m1 * (shopa.getPosition().x+9));
            yzao2 = (shopa.getPosition().y+9)-yzao; 

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = 0.f;
            pontos[3] = yzao2;

            yzao = yzao + shopa.getPosition().y+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = 0.f;
            pontos[7] = yzao;
        }else if(enemy1.getPosition().x == shopa.getPosition().x && enemy1.getPosition().y < shopa.getPosition().y){
            Z = get_dist(shopa.getPosition().x+9,shopa.getPosition().y+9,enemy1.getPosition().x,enemy1.getPosition().y+18);        
            m1 = atan2 (nove,Z);
            m1 = sin(m1);
            xzao = (m1 * (shopa.getPosition().y+9));
            xzao2 = (shopa.getPosition().x+9)-xzao; 


            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao2;
            pontos[3] = 0.f;

            xzao = xzao + shopa.getPosition().x+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 0.f;

        }else if(enemy1.getPosition().x == shopa.getPosition().x && enemy1.getPosition().y > shopa.getPosition().y){
            Z = get_dist(shopa.getPosition().x+9,shopa.getPosition().y+9,enemy1.getPosition().x,enemy1.getPosition().y);        
            m1 = atan2 (nove,Z);
            m1 = sin(m1);
            xzao = (m1 * (shopa.getPosition().y+9));
            xzao2 = (shopa.getPosition().x+9)-xzao; 


            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao2;
            pontos[3] = 600.f;

            xzao = xzao + shopa.getPosition().x+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 600.f;
        }
    }else if(indi == 2){
        if(enemy2.getPosition().x > shopa.getPosition().x && enemy2.getPosition().y > shopa.getPosition().y){
            long double var1;
            m1 = ((enemy2.getPosition().y+9-shopa.getPosition().y));

            var1 = alturay - (shopa.getPosition().y+9);
            m1 = m1/var1;

            var1 = (enemy2.getPosition().x - (shopa.getPosition().x+9));

            xzao2 = var1/m1 + shopa.getPosition().x+9;
            yzao = 10000;

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao2;
            pontos[3] = 600.f;

            m1 = (enemy2.getPosition().y-(shopa.getPosition().y+9));

            var1 = alturay - (shopa.getPosition().y+9);
            m1 = m1/var1;
            
            var1 = ((enemy2.getPosition().x+9) - (shopa.getPosition().x));

            xzao = var1/m1 + shopa.getPosition().x+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 600.f;

        }else if(enemy2.getPosition().x > shopa.getPosition().x && enemy2.getPosition().y < shopa.getPosition().y){
            long double var1;
            m1 = ((shopa.getPosition().y+9)-enemy2.getPosition().y)/(shopa.getPosition().y+9);

            var1 = (enemy2.getPosition().x - (shopa.getPosition().x+9));

            xzao2 = var1/m1 + shopa.getPosition().x+9;
            yzao = 10000;

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao2;
            pontos[3] = 0.f;

            m1 = ((shopa.getPosition().y)-(enemy2.getPosition().y+9))/(shopa.getPosition().y+9);

            var1 = ((enemy2.getPosition().x+9) - (shopa.getPosition().x));

            xzao = var1/m1 + shopa.getPosition().x+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 0.f;
        }else if(enemy2.getPosition().x < shopa.getPosition().x && enemy2.getPosition().y > shopa.getPosition().y){
            long double var1,var2;


            var2 = (enemy2.getPosition().y) - (shopa.getPosition().y+9);
            m1 = (shopa.getPosition().x+9) - (enemy2.getPosition().x);

            var1 = var2/m1; 
            var2 = shopa.getPosition().y-9;
            xzao = (shopa.getPosition().x+9) - (var2/var1) ; 

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao;
            pontos[3] = 600.f;

            var2 = (enemy2.getPosition().y+18)-(shopa.getPosition().y+9);
            m1 = (shopa.getPosition().x+9) - (enemy2.getPosition().x+18);

            var1 = var2/m1; 
            var2 = shopa.getPosition().y-9;
            xzao = (shopa.getPosition().x+9) - (var2/var1);

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 600.f;


        }else if(enemy2.getPosition().x < shopa.getPosition().x && enemy2.getPosition().y < shopa.getPosition().y){
            long double var1,var2;

            var2 = (shopa.getPosition().y+9) - enemy2.getPosition().y;
            m1 = (shopa.getPosition().x+9) - (enemy2.getPosition().x+18);

            var1 = var2/m1; 
            var2 = shopa.getPosition().y+9;
            xzao = shopa.getPosition().x+9 - (var2/var1) ; 

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao;
            pontos[3] = 0.f;

            var2 = (shopa.getPosition().y+9) - (enemy2.getPosition().y+18);
            m1 = (shopa.getPosition().x+9) - (enemy2.getPosition().x);

            var1 = var2/m1; 
            var2 = shopa.getPosition().y+9;
            xzao = shopa.getPosition().x+9 - (var2/var1);

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 0.f;

        }else if(enemy2.getPosition().x > shopa.getPosition().x && enemy2.getPosition().y == shopa.getPosition().y){
            Z = get_dist(shopa.getPosition().x+9,shopa.getPosition().y,enemy2.getPosition().x,enemy2.getPosition().y);        
            //m =variação de y / variação de x
            m1 = atan2 (9,Z);
            m1 = sin(m1);
            yzao = (m1 * (shopa.getPosition().x))+9;
            yzao2 = (shopa.getPosition().y+9)-yzao; 

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = 900.f;
            pontos[3] = yzao2;

            yzao = yzao + shopa.getPosition().y+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = 900.f;
            pontos[7] = yzao;
        }else if(enemy2.getPosition().x < shopa.getPosition().x && enemy2.getPosition().y == shopa.getPosition().y){
            Z = get_dist(shopa.getPosition().x,shopa.getPosition().y,enemy2.getPosition().x+18,enemy2.getPosition().y);        
            //m =variação de y / variação de x
            m1 = atan2 (nove,Z);
            m1 = sin(m1);
            yzao = (m1 * (shopa.getPosition().x+9));
            yzao2 = (shopa.getPosition().y+9)-yzao; 

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = 0.f;
            pontos[3] = yzao2;

            yzao = yzao + shopa.getPosition().y+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = 0.f;
            pontos[7] = yzao;
        }else if(enemy2.getPosition().x == shopa.getPosition().x && enemy2.getPosition().y < shopa.getPosition().y){
            Z = get_dist(shopa.getPosition().x+9,shopa.getPosition().y+9,enemy2.getPosition().x,enemy2.getPosition().y+18);        
            m1 = atan2 (nove,Z);
            m1 = sin(m1);
            xzao = (m1 * (shopa.getPosition().y+9));
            xzao2 = (shopa.getPosition().x+9)-xzao; 


            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao2;
            pontos[3] = 0.f;

            xzao = xzao + shopa.getPosition().x+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 0.f;

        }else if(enemy2.getPosition().x == shopa.getPosition().x && enemy2.getPosition().y > shopa.getPosition().y){
            Z = get_dist(shopa.getPosition().x+9,shopa.getPosition().y+9,enemy2.getPosition().x,enemy2.getPosition().y);        
            m1 = atan2 (nove,Z);
            m1 = sin(m1);
            xzao = (m1 * (shopa.getPosition().y+9));
            xzao2 = (shopa.getPosition().x+9)-xzao; 


            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao2;
            pontos[3] = 600.f;

            xzao = xzao + shopa.getPosition().x+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 600.f;
        }
    }else if(indi== 3){
        if(enemy3.getPosition().x > shopa.getPosition().x && enemy3.getPosition().y > shopa.getPosition().y){
            long double var1;
            m1 = ((enemy3.getPosition().y+9-shopa.getPosition().y));

            var1 = alturay - (shopa.getPosition().y+9);
            m1 = m1/var1;

            var1 = (enemy3.getPosition().x - (shopa.getPosition().x+9));

            xzao2 = var1/m1 + shopa.getPosition().x+9;

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao2;
            pontos[3] = 600.f;

            m1 = (enemy3.getPosition().y-(shopa.getPosition().y+9));

            var1 = alturay - (shopa.getPosition().y+9);
            m1 = m1/var1;
            
            var1 = ((enemy3.getPosition().x+9) - (shopa.getPosition().x));

            xzao = var1/m1 + shopa.getPosition().x+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 600.f;

        }else if(enemy3.getPosition().x > shopa.getPosition().x && enemy3.getPosition().y < shopa.getPosition().y){
            long double var1;
            m1 = ((shopa.getPosition().y+9)-enemy3.getPosition().y)/(shopa.getPosition().y+9);

            var1 = (enemy3.getPosition().x - (shopa.getPosition().x+9));

            xzao2 = var1/m1 + shopa.getPosition().x+9;

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao2;
            pontos[3] = 0.f;

            m1 = ((shopa.getPosition().y)-(enemy3.getPosition().y+9))/(shopa.getPosition().y+9);

            var1 = ((enemy3.getPosition().x+9) - (shopa.getPosition().x));

            xzao = var1/m1 + shopa.getPosition().x+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 0.f;
        }else if(enemy3.getPosition().x < shopa.getPosition().x && enemy3.getPosition().y > shopa.getPosition().y){
            long double var1,var2;


            var2 = (enemy3.getPosition().y) - (shopa.getPosition().y+9);
            m1 = (shopa.getPosition().x+9) - (enemy3.getPosition().x);

            var1 = var2/m1; 
            var2 = shopa.getPosition().y-9;
            xzao = (shopa.getPosition().x+9) - (var2/var1) ; 

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao;
            pontos[3] = 600.f;

            var2 = (enemy3.getPosition().y+18)-(shopa.getPosition().y+9);
            m1 = (shopa.getPosition().x+9) - (enemy3.getPosition().x+18);

            var1 = var2/m1; 
            var2 = shopa.getPosition().y-9;
            xzao = (shopa.getPosition().x+9) - (var2/var1);

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 600.f;


        }else if(enemy3.getPosition().x < shopa.getPosition().x && enemy3.getPosition().y < shopa.getPosition().y){
            long double var1,var2;

            var2 = (shopa.getPosition().y+9) - enemy3.getPosition().y;
            m1 = (shopa.getPosition().x+9) - (enemy3.getPosition().x+18);

            var1 = var2/m1; 
            var2 = shopa.getPosition().y+9;
            xzao = shopa.getPosition().x+9 - (var2/var1) ; 

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao;
            pontos[3] = 0.f;

            var2 = (shopa.getPosition().y+9) - (enemy3.getPosition().y+18);
            m1 = (shopa.getPosition().x+9) - (enemy3.getPosition().x);

            var1 = var2/m1; 
            var2 = shopa.getPosition().y+9;
            xzao = shopa.getPosition().x+9 - (var2/var1);

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 0.f;

        }else if(enemy3.getPosition().x > shopa.getPosition().x && enemy3.getPosition().y == shopa.getPosition().y){
            Z = get_dist(shopa.getPosition().x+9,shopa.getPosition().y,enemy3.getPosition().x,enemy3.getPosition().y);        
            //m =variação de y / variação de x
            m1 = atan2 (9,Z);
            m1 = sin(m1);
            yzao = (m1 * (shopa.getPosition().x))+9;
            yzao2 = (shopa.getPosition().y+9)-yzao; 

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = 900.f;
            pontos[3] = yzao2;

            yzao = yzao + shopa.getPosition().y+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = 900.f;
            pontos[7] = yzao;
        }else if(enemy3.getPosition().x < shopa.getPosition().x && enemy3.getPosition().y == shopa.getPosition().y){
            Z = get_dist(shopa.getPosition().x,shopa.getPosition().y,enemy3.getPosition().x+18,enemy3.getPosition().y);        
            //m =variação de y / variação de x
            m1 = atan2 (nove,Z);
            m1 = sin(m1);
            yzao = (m1 * (shopa.getPosition().x+9));
            yzao2 = (shopa.getPosition().y+9)-yzao; 

            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = 0.f;
            pontos[3] = yzao2;

            yzao = yzao + shopa.getPosition().y+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = 0.f;
            pontos[7] = yzao;
        }else if(enemy3.getPosition().x == shopa.getPosition().x && enemy3.getPosition().y < shopa.getPosition().y){
            Z = get_dist(shopa.getPosition().x+9,shopa.getPosition().y+9,enemy3.getPosition().x,enemy3.getPosition().y+18);        
            m1 = atan2 (nove,Z);
            m1 = sin(m1);
            xzao = (m1 * (shopa.getPosition().y+9));
            xzao2 = (shopa.getPosition().x+9)-xzao; 


            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao2;
            pontos[3] = 0.f;

            xzao = xzao + shopa.getPosition().x+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 0.f;

        }else if(enemy3.getPosition().x == shopa.getPosition().x && enemy3.getPosition().y > shopa.getPosition().y){
            Z = get_dist(shopa.getPosition().x+9,shopa.getPosition().y+9,enemy3.getPosition().x,enemy3.getPosition().y);        
            m1 = atan2 (nove,Z);
            m1 = sin(m1);
            xzao = (m1 * (shopa.getPosition().y+9));
            xzao2 = (shopa.getPosition().x+9)-xzao; 


            pontos[0] = shopa.getPosition().x+9;
            pontos[1] = shopa.getPosition().y+9; 
            pontos[2] = xzao2;
            pontos[3] = 600.f;

            xzao = xzao + shopa.getPosition().x+9;

            pontos[4] = shopa.getPosition().x+9;
            pontos[5] = shopa.getPosition().y+9; 
            pontos[6] = xzao;
            pontos[7] = 600.f;
        }
    }
    
}

using namespace std;
int main(){

    double raio;
    float jogx,jogy;
    float ob1x,ob1y;
    float ob2x,ob2y;
    float ob3x,ob3y;

    std:: cout << "Por favor insira o raio de busca por obstáculos :\n";
    std::cin >> raio;

    std:: cout << "Por favor insira a posição X de seu robô:\n";
    std::cin >> jogx;
    
    std:: cout << "Por favor insira a posição Y de seu robô:\n";
    std::cin >> jogy;

    std:: cout << "Por favor insira a posição X do obstáculo 1 (1/3) :\n";
    std::cin >> ob1x;
    
    std:: cout << "Por favor insira a posição Y do obstáculo 1 (1/3):\n";
    std::cin >> ob1y;

    std:: cout << "Por favor insira a posição X do obstáculo 2 (2/3) :\n";
    std::cin >> ob2x;
    
    std:: cout << "Por favor insira a posição Y do obstáculo 2 (2/3):\n";
    std::cin >> ob2y;

    std:: cout << "Por favor insira a posição X do obstáculo 3 (3/3) :\n";
    std::cin >> ob3x;
    
    std:: cout << "Por favor insira a posição Y do obstáculo 3 (3/3):\n";
    std::cin >> ob3y;


    
    long double reta1enemy1ix,reta1enemy1iy,reta1enemy1fx,reta1enemy1fy;
    long double reta2enemy1ix,reta2enemy1iy,reta2enemy1fx,reta2enemy1fy;
    long double reta1enemy2ix,reta1enemy2iy,reta1enemy2fx,reta1enemy2fy;
    long double reta2enemy2ix,reta2enemy2iy,reta2enemy2fx,reta2enemy2fy;
    long double reta1enemy3ix,reta1enemy3iy,reta1enemy3fx,reta1enemy3fy;
    long double reta2enemy3ix,reta2enemy3iy,reta2enemy3fx,reta2enemy3fy;

    long double retas1[8];
    long double retas2[8];
    long double retas3[8];

    float dist[10];
    sf::RenderWindow window(sf::VideoMode(900, 600), "Armorial Samico", sf::Style::Default);
    shopa.setPosition(jogx, jogy);
    shopa.setFillColor(sf::Color(255,0,0));
    enemy1.setPosition(ob1x, ob1y);
    enemy1.setFillColor(sf::Color(255,0,0));
    enemy2.setPosition(ob2x, ob2y);
    enemy2.setFillColor(sf::Color(255,0,0));
    enemy3.setPosition(ob3x, ob3y);
    enemy3.setFillColor(sf::Color(255,0,0));
    
    dist[0] = get_dist(enemy1.getPosition().x, enemy1.getPosition().y,shopa.getPosition().x,shopa.getPosition().y);
    dist[1] = get_dist(enemy2.getPosition().x,enemy2.getPosition().y,shopa.getPosition().x,shopa.getPosition().y);
    dist[2] = get_dist(enemy3.getPosition().x,enemy3.getPosition().y,shopa.getPosition().x,shopa.getPosition().y);
    
    int i = 0;

    if(dist[0]<= raio){
        i = 1;
        CalculaReta(i,&retas1[0]);
        i=0;
        reta1enemy1ix = retas1[0];
        reta1enemy1iy = retas1[1];
        reta1enemy1fx = retas1[2];
        reta1enemy1fy = retas1[3];
        reta2enemy1ix = retas1[4];
        reta2enemy1iy = retas1[5];
        reta2enemy1fx = retas1[6];
        reta2enemy1fy = retas1[7];
    }
    if(dist[1]<=raio){
        i = 2;
        CalculaReta(i,&retas2[0]);
        i=0;
        reta1enemy2ix = retas2[0];
        reta1enemy2iy = retas2[1];
        reta1enemy2fx = retas2[2];
        reta1enemy2fy = retas2[3];
        reta2enemy2ix = retas2[4];
        reta2enemy2iy = retas2[5];
        reta2enemy2fx = retas2[6];
        reta2enemy2fy = retas2[7];
    }
    if(dist[2]<=raio){
        i = 3;
        CalculaReta(i,&retas3[0]);
        i=0;
        reta1enemy3ix = retas3[0];
        reta1enemy3iy = retas3[1];
        reta1enemy3fx = retas3[2];
        reta1enemy3fy = retas3[3];
        reta2enemy3ix = retas3[4];
        reta2enemy3iy = retas3[5];
        reta2enemy3fx = retas3[6];
        reta2enemy3fy = retas3[7];
    }


    sf::Vertex linenemy11[] =
    {
        sf::Vertex(sf::Vector2f(reta1enemy1ix, reta1enemy1iy)),
        sf::Vertex(sf::Vector2f(reta1enemy1fx, reta1enemy1fy))
    };
    sf::Vertex linenemy12[] =
    {
        sf::Vertex(sf::Vector2f(reta2enemy1ix, reta2enemy1iy)),
        sf::Vertex(sf::Vector2f(reta2enemy1fx, reta2enemy1fy))
    };
    
    sf::Vertex linenemy21[] =
    {
        sf::Vertex(sf::Vector2f(reta1enemy2ix, reta1enemy2iy)),
        sf::Vertex(sf::Vector2f(reta1enemy2fx, reta1enemy2fy))
    };
sf::Vertex linenemy22[] =
    {
        sf::Vertex(sf::Vector2f(reta2enemy2ix, reta2enemy2iy)),
        sf::Vertex(sf::Vector2f(reta2enemy2fx, reta2enemy2fy))
    };
sf::Vertex linenemy31[] =
    {
        sf::Vertex(sf::Vector2f(reta1enemy3ix, reta1enemy3iy)),
        sf::Vertex(sf::Vector2f(reta1enemy3fx, reta1enemy3fy))
    };
sf::Vertex linenemy32[] =
    {
        sf::Vertex(sf::Vector2f(reta2enemy3ix, reta2enemy3iy)),
        sf::Vertex(sf::Vector2f(reta2enemy3fx, reta2enemy3fy))
    };
    
    for(int k = 0;k<8;k++){
       std :: cout << "Pontos = " << retas1[k] << "\n";
    }
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();

            }
        }

        //window.draw(rectangle);
        //window.draw(line, 2, sf::Lines);
        //window.draw(line1, 2, sf::Lines);
        //window.draw(line2, 2, sf::Lines);
        ///window.draw(line3, 2, sf::Lines);
        //window.draw(line4, 2, sf::Lines);
        //window.draw(line5, 2, sf::Lines);
        //window.draw(line6, 2, sf::Lines);
        //window.draw(line7, 2, sf::Lines);
        //window.draw(line8, 2, sf::Lines);
        //window.draw(line9, 2, sf::Lines);
        //window.draw(line10, 2, sf::Lines);
        //window.draw(line11, 2, sf::Lines);
        //window.draw(linha, 2, sf::Lines);
        window.draw(enemy1);
        window.draw(enemy2);
        window.draw(enemy3);
        window.draw(shopa);
        window.draw(linenemy11, 2, sf::Lines);
        window.draw(linenemy12, 2, sf::Lines);
        window.draw(linenemy21, 2, sf::Lines);
        window.draw(linenemy22, 2, sf::Lines);
        window.draw(linenemy31, 2, sf::Lines);
        window.draw(linenemy32, 2, sf::Lines);
        //window.draw(shape);
        window.display();
    }
return 0;
}