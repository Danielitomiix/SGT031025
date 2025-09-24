#pragma once
#include "Prerequisitos.h"
#include "Ticket.h"


class
GestorDeTickets {

public:

	GestorDeTickets() = default;
	~GestorDeTickets() = default;


private:
	std::vector<Ticket> m_tickets;

};

