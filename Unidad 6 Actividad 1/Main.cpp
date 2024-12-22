#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Par�metros iniciales
    float V0 = 200.0f;  // Velocidad inicial en p�xeles por segundo
    float Vfinal = 600.0f;  // Velocidad final en p�xeles por segundo
    float incrementoVelocidad = 50.0f;  // Incremento de la velocidad cada vez que el c�rculo sale de la pantalla

    // Crear la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "C�rculo en Movimiento");

    // Crear el c�rculo
    sf::CircleShape circle(50.0f);  // Radio de 50 p�xeles
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(0, window.getSize().y / 2 - circle.getRadius());  // Posicionar el c�rculo en el centro vertical

    // Inicializar la velocidad
    float velocidad = V0;

    // Reloj para gestionar el tiempo
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Calcular el tiempo transcurrido
        sf::Time deltaTime = clock.restart();
        float desplazamiento = velocidad * deltaTime.asSeconds();

        // Mover el c�rculo horizontalmente
        circle.move(desplazamiento, 0);

        // Si el c�rculo sale por el lado derecho de la pantalla
        if (circle.getPosition().x - circle.getRadius() > window.getSize().x) {
            // Reposicionar el c�rculo en el lado izquierdo
            circle.setPosition(-circle.getRadius(), window.getSize().y / 2 - circle.getRadius());
            // Incrementar la velocidad
            velocidad += incrementoVelocidad;
        }

        // Limitar la velocidad a la velocidad final
        if (velocidad > Vfinal) {
            velocidad = Vfinal;
        }

        // Dibujar el c�rculo
        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
