#pragma once

// Librer�as est�ndar necesarias
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

/**
 * @struct FechaHora
 * @brief Representa la fecha y hora completa (dia, mes, a�o, hora, minuto, segundo).
 *
 * Permite obtener la fecha y hora actual del sistema y convertirla a cadena para mostrarla.
 */
struct  FechaHora {
	int dia;      /**< D�a del mes */
	int mes;      /**< Mes del a�o */
	int anio;     /**< A�o */
	int hora;     /**< Hora (24h) */
	int minuto;   /**< Minuto */
	int segundo;  /**< Segundo */

	/**
	 * @brief Obtiene la fecha y hora actual del sistema.
	 */
	void
	getFechaHora() {
		time_t now = time(0);
		tm *ltm = localtime(&now);
		dia = ltm->tm_mday;
		mes = 1 + ltm->tm_mon;
		anio = 1900 + ltm->tm_year;
		hora = ltm->tm_hour;
		minuto = ltm->tm_min;
		segundo = ltm->tm_sec;
	}

	/**
	* @brief Convierte la fecha y hora a una cadena legible.
	* @return Cadena con formato "dd/mm/yyyy hh:mm:ss".
	*/
	std::string toString() const {
		return std::to_string(dia) + "/" +
			   std::to_string(mes) + "/" +
			   std::to_string(anio) + " " +
			   std::to_string(hora) + ":" +
			   std::to_string(minuto) + ":" +
			   std::to_string(segundo);
	}
};

/**
 * @enum EstadoTicket
 * @brief Representa los posibles estados de un ticket.
 */
enum
EstadoTicket {
	PENDIENTE =  1,   /**< El ticket aun no ha sido iniciado */
	EnProgreso  = 2,  /**< El ticket esta siendo trabajado */
	COMPLETADO = 3    /**< El ticket ha sido completado */
};