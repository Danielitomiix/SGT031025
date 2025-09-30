#pragma once
#include "Prerequisitos.h"

/**
 * @class Ticket
 * @brief Representa un ticket de tarea con ID, titulo, descripcion, estado y fecha/hora.
 *
 * Permite crear, modificar y mostrar tickets, ademas de consultar su estado.
 */

class 
Ticket {

public:
	/**
	* @brief Constructor de Ticket con parametros.
	* @param id Identificador unico del ticket.
	* @param titulo Titulo breve del ticket.
	* @param descripcion Descripcion detallada del ticket.
	* @param estado Estado inicial del ticket (Pendiente, En Progreso o Completado).
	*/
	
	Ticket(int id, const std::string& titulo,
		   const std::string& descripcion,
		   EstadoTicket estado) :
		   m_id(id), m_titulo(titulo),
		   m_descripcion(descripcion),
		   m_estado(estado) {
		   m_fechaHora.getFechaHora();
	}

	/** @brief Destructor por defecto */
	~Ticket() = default;

	/** @brief Objeto FechaHora que almacena la fecha y hora del ticket */
	FechaHora m_fechaHora;

	/** @brief Obtiene el ID del ticket */
	int 
	getId() 
	const { return m_id; }
	
	/** @brief Obtiene el titulo del ticket */
	std::string 
	getTitulo()
		const {
		return m_titulo;
	}

	/** @brief Obtiene la descripcion del ticket */
	std::string 
	getDescripcion() 
		const {
		return m_descripcion;
	}

	/** @brief Obtiene el estado actual del ticket */
	EstadoTicket 
	getEstado() 
		const {
		return m_estado;
	}

	/** @brief Modifica el titulo del ticket */
	void 
	setTitulo(const std::string& Titulo) {
		m_titulo = Titulo;
	}

	/** @brief Modifica la descripcion del ticket */
	void 
	setDescripcion(const std::string& Descripcion) {
		m_descripcion = Descripcion;
	}

	/**
	* @brief Valida que el cambio de estado sea permitido y lo realiza.
	*/
	bool 
	cambiarEstado(EstadoTicket nuevoEstado) {
		switch (m_estado) {
			case PENDIENTE:
				if (nuevoEstado == EnProgreso) {
					m_estado = nuevoEstado;
					return true;
				}
				break;
			case EnProgreso:
				if (nuevoEstado == PENDIENTE || nuevoEstado == COMPLETADO) {
					m_estado = nuevoEstado;
					return true;
				}
				break;
			case COMPLETADO:
				// No se puede cambiar el estado si ya esta completado
				return false;
		}
		return false; // Cambio de estado no permitido
	}

	/**
	* @brief Muestra toda la informacion del ticket en consola.
	*/
	void 
	mostrarTicket() const {
		std::cout << "ID: " << m_id << "\n"   
				  << "Titulo: " << m_titulo << "\n"
				  << "Descripcion: " << m_descripcion << "\n"
				  << "Estado: " << estadoToString(m_estado) << "\n"
		          << "Fecha y Hora: " << m_fechaHora.toString() << "\n";
	}

	
private:
	int m_id;                      /**< ID unico del ticket */
	std::string m_titulo;          /**< Titulo del ticket */
	std::string m_descripcion;     /**< Descripcion del ticket */
	EstadoTicket m_estado;         /**< Estado actual del ticket */

	/**
	 * @brief Convierte un EstadoTicket a su representacion en cadena.
	 * @param estado Estado a convertir.
	 * @return Cadena representando el estado.
	 */
	std::string estadoToString(EstadoTicket estado) const {
		switch (estado) {
			case PENDIENTE:
				return "PENDIENTE";
			case EnProgreso:
				return "En Progreso";
			case COMPLETADO:
				return "COMPLETADO";
			default:
				return "DESCONOCIDO";
		}
	}

};
