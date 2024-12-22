#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Parámetros iniciales
    float V0 = 200.0f;  // Velocidad inicial en píxeles por segundo
    float Vfinal = 600.0f;  // Velocidad final en píxeles por segundo
    float incrementoVelocidad = 50.0f;  // Incremento de la velocidad cada vez que el círculo sale de la pantalla

    // Crear la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Círculo en Movimiento");

    // Crear el círculo
    sf::CircleShape circle(50.0f);  // Radio de 50 píxeles
    circle.setFillColor(sf::Color::Green);
    circle.setPosition(0, window.getSize().y / 2 - circle.getRadius());  // Posicionar el círculo en el centro vertical

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

        // Mover el círculo horizontalmente
        circle.move(desplazamiento, 0);

        // Si el círculo sale por el lado derecho de la pantalla
        if (circle.getPosition().x - circle.getRadius() > window.getSize().x) {
            // Reposicionar el círculo en el lado izquierdo
            circle.setPosition(-circle.getRadius(), window.getSize().y / 2 - circle.getRadius());
            // Incrementar la velocidad
            velocidad += incrementoVelocidad;
        }

        // Limitar la velocidad a la velocidad final
        if (velocidad > Vfinal) {
            velocidad = Vfinal;
        }

        // Dibujar el círculo
        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
