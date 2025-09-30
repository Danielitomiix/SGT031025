#pragma once
#include "Prerequisitos.h"
#include "Ticket.h"


/**
 * @class GestorDeTickets
 * @brief Gestiona una coleccion de tickets, permitiendo agregar, modificar, eliminar y listar tickets.
 *
 * Proporciona funcionalidades para manejar el ciclo de vida completo de los tickets,
 * incluyendo la creacion, actualizacion de estado y visualizacion de detalles.
 */
class
GestorDeTickets {

public:

	/** @brief Constructor por defecto */
	GestorDeTickets() = default;

	/** @brief Destructor por defecto */
	~GestorDeTickets() = default;
	
	/**
	 * @brief Agrega un nuevo ticket a la coleccion.
	 * @param ticket Ticket a agregar.
	 */
	void 
	agregarTicket(const Ticket& ticket) {
		m_tickets.push_back(ticket);
	}

	/**
	 * @brief Muestra todos los tickets en consola.
	 * Si no hay tickets, muestra un mensaje indicando que no hay tickets.
	 */
	void
	mostrarTickets()const {
		if (m_tickets.empty()) {
			std::cout << "No hay tickets disponibles.\n";
			return;
		}
		for (const auto& ticket : m_tickets) {
			ticket.mostrarTicket();
			std::cout << "-----------------------\n";
		}
	}

	/**
	 * @brief Busca un ticket por su ID.
	 * @param id ID del ticket a buscar.
	 * @return Puntero al ticket si se encuentra, null en caso contrario.
	 */
	Ticket* 
	buscarTicketPorId(int id) {
		for (auto& ticket : m_tickets) {
			if (ticket.getId() == id) {
				return &ticket;
			}
		}
		return NULL; 
	}

	/**
	 * @brief Elimina un ticket por su ID.
	 * @param id ID del ticket a eliminar.
	 * @return true si se elimino el ticket, false si no se encontro.
	 */
	bool
	eliminarTicket(int id) {
		for (auto it = m_tickets.begin();
			        it != m_tickets.end(); 
							++it) {
			if (it->getId() == id) {
				m_tickets.erase(it);
				return true;
			}
		}
		return false;
	}


private:
	std::vector<Ticket> m_tickets; /** El vector almacena los tickets gestionados */

};

