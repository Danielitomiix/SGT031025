#include "Prerequisitos.h"
#include "Ticket.h"
#include "GestorDeTickets.h"


int main() {

	/**
	* @brief Creo un objeto de tipo GestorDeTickets que va a manejar.
	* la coleccion de tickets que voy agregando.
	*/
	GestorDeTickets gestor;
	int opcion;
	int idCounter = 1; // Contador para asignar IDs unicos a los tickets

	// Bucle principal del menú, se repite hasta que el usuario elige salir (opción 0)
	do {
		// Muestra el menú de opciones
		std::cout << "Menu de Gestion de Tickets:\n"
			<< "1. Crear Ticket\n"
			<< "2. Mostrar Tickets\n"
			<< "3. Modificar titulo\n"
			<< "4. Modificar descripcon\n"
			<< "5. Cambiar estado\n"
			<< "6. Eliminar Ticket\n"
			<< "0. Salir\n"
			<< "Seleccione una opcion: ";

		std::cin >> opcion; // Leer la opcion del usuario
		std::cin.ignore(); // Limpiar el buffer de entrada
	    
		// Crea un nuevo ticket
		if (opcion == 1) {
			std::string titulo, descripcion;
			std::cout << "Ingrese el titulo del ticket: ";
			std::getline(std::cin, titulo); // Leer titulo con espacios
			std::cout << "Ingrese la descripcion del ticket: ";
			std::getline(std::cin, descripcion);

			// Crea el ticket ID unico, titulo, descripcion y estado inicial PENDIENTE
			Ticket nuevoTicket(idCounter++,
				                 titulo, 
				                 descripcion,
				                 PENDIENTE);
			gestor.agregarTicket(nuevoTicket);
			std::cout << "Ticket agregado correctamente: \n";
			}
		// Muestra todos los tickets
		else if (opcion == 2) {
			gestor.mostrarTickets();
		}
		// Modifica el titulo de un ticket existente
		else if (opcion == 3) {
			int id;
			std::string nuevoTitulo;
			std::cout << "Ingrese el ID del ticket a modificar: ";
			std::cin >> id;
			std::cin.ignore(); // Limpiar el buffer

			// Busco el ticket por ID
			Ticket* ticket = gestor.buscarTicketPorId(id);
			if (ticket) {
				std::cout << "Ingrese el nuevo titulo: ";
				std::getline(std::cin, nuevoTitulo);
				ticket->setTitulo(nuevoTitulo);
				std::cout << "Titulo actualizado correctamente.\n";
			}
			else {
				std::cout << "Ticket no encontrado.\n";
			}
		}
		// Modifica la descripcion de un ticket existente
		else if (opcion == 4) {
			int id;
			std::string nuevaDescripcion;
			std::cout << "Ingrese el ID del ticket a modificar: ";
			std::cin >> id;
			std::cin.ignore(); // Limpiar el buffer

			// Busco el ticket por ID
			Ticket* ticket = gestor.buscarTicketPorId(id);
			if (ticket) {
				std::cout << "Ingrese la nueva descripcion: ";
				std::getline(std::cin, nuevaDescripcion);
				ticket->setDescripcion(nuevaDescripcion);
				std::cout << "Descripcion actualizada correctamente.\n";
			}
			else {
				std::cout << "Ticket no encontrado.\n";
			}
		}
		// Cambia el estado de un ticket existente
		else if (opcion == 5) {
			int id, nuevoEstado;
			std::cout << "Ingrese el ID del ticket a cambiar de estado: ";
			std::cin >> id;
			std::cout << "Ingrese el nuevo estado (1: PENDIENTE, 2: En Progreso, 3: COMPLETADO): ";
			std::cin >> nuevoEstado;
			Ticket* ticket = gestor.buscarTicketPorId(id);
			if (ticket) {

				// Uso static_cast para convertir el numero ingresado a EstadoTicket (enum)
				if (ticket->cambiarEstado
				   (static_cast<EstadoTicket>(nuevoEstado))) {
					std::cout << "Estado actualizado correctamente.\n";
				}
				else {
					std::cout << "Cambio de estado no permitido.\n";
				}
			} else {
				std::cout << "Ticket no encontrado.\n";
			}
		}

    // Elimina un ticket existente por su ID
		else if (opcion == 6) {
			int id;
			std::cout << "Ingrese el ID del ticket a eliminar: ";
			std::cin >> id;
			if (gestor.eliminarTicket(id)) {
				std::cout << "Ticket eliminado correctamente.\n";
			}
			else {
				std::cout << "Ticket no encontrado.\n";
			}
		}
	}
	while (opcion != 0); // Repite hasta que el usuario elige salir (opción 0)

	// Mensaje de despedida al salir del sistema
	std::cout << "Saliendo del sistema...\n";

    return 0;
}
