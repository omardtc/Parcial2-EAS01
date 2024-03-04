#include <iostream>
#include <string>
#include <cstdlib>  // Función rand().
#include <ctime>    // Función time() para generar una nueva seed aleatoria.
using namespace std;

#define log(x) cout << x << endl;

class Jugador{
    public:
    int vida;
    int ataque;
    string nombre;
    Jugador* enemigo;
    /*
        Agrega propiedades para guardar la vida(número entero), ataque(número entero) y nombre del jugador.
        Agrega una propiedad para guardar el jugador que lo atacó por última vez.
    */
    
    Jugador(); 
    Jugador(int vida, int ataque, string nombre); 
    
    void atacar(Jugador *x); 
};

int main()
{
    srand(time(0));  // Seed para generar valores aleatorios
    
    Jugador p1;
    Jugador p2;
    p1.nombre = "Link";
    p2.nombre = "Ganon";
    p1.ataque = 10;
    p2.ataque = 12;
    p1.vida = 150;
    p2.vida = 130;
    p1.atacar(&p2);

    /*
        Crear al menos 2 jugadores con diferentes nombres, vida y ataque. 
        Los jugadores deben atacarse entre sí, tomando turnos, hasta que uno pierda toda su vida.
        En cuanto la vida del jugador se reduzca a 0 el programa muestra al ganador y se termina. 
        No importa quien ataca primero.
    */

    return 0;
}

Jugador::Jugador(){
    this->vida = 100;
    this->ataque = 5;
    this->nombre = "No definido";
    /*
        Asignar 100 a hp y 5 a attack como valores default.
        Asignar 'No definido' al nombre como default.
    */
}

Jugador::Jugador(int vida, int ataque, string nombre){
    
    if (vida>0&&vida<201)
    {
        this->vida = vida;
    }
    if (ataque>0&&ataque<21)
    {
        this->ataque = ataque;

    }
    this->nombre = nombre;
    /*
        Asignar los parámetros recibidos a las propiedades del objeto.
        No se pueden asignar valores negativos a hp y attack.
        Máximo 200 hp y 20 attack
    */
}

void Jugador::atacar(Jugador *x){
    this->enemigo = x;
    while (x->vida>0&&vida>0)
    {
        if (x->vida>0)
        {
            int a = rand()%100;
            if (a<=20)
            {
                vida = vida - 0;
                cout << x->nombre << " ataco a "<<nombre<<" pero fallo, vida restante de "<<nombre << " = "<< vida<<endl;
            }
            else
            {
                vida = vida - x->ataque;
                cout << x->nombre << " ataco a "<<nombre<<" e hizo "<<x->ataque<<" de danio, vida restante de "<<nombre << " = "<< vida<<endl;

            }
        }

        if(vida > 0)
        {
            int b = rand()%100;
            if(b<=20)
            {
                x->vida = x->vida - 0;
                cout << nombre << " ataco a "<<x->nombre<<" pero fallo, vida restante de "<<x->nombre << " = "<< x->vida<<endl;
            }
            else
            {
                x->vida = x->vida - ataque;
                cout << nombre << " ataco a "<<x->nombre<<" e hizo "<<ataque<<" de danio, vida restante de "<<x->nombre << " = "<< x->vida<<endl;

            }

        }
    }

    if(vida>0)
    {
        cout << "El ganador es " << nombre << endl;
    }
    if(x->vida>0)
    {
        cout << "El ganador es " << x->nombre << endl;
    }
    /*
        El jugador atacado(el que recibes como parámetro) pierde HP igual al ataque del jugador que ataca.
        Existe un 20% de probabilidad de que el ataque falle y no haga daño.
        Se debe mostrar lo que pasó en cada ataque:
        nombre1 atacó a nombre2 e hizo 5 de daño, vida restante de nombre2 = 95
        nombre2 atacó a nombre1 pero fallo, vida restante de nombre1 = 100
        El jugador que atacó debe quedar guardar en la propiedad atacadoPor del jugador atacado.
    */
    /*
    Nota:
        int x = rand() % 1000; asigna un valor aleatorio entre 0 y 999 a x;
        Puedes usar esto para la probabilidad del ataque.
    */
}