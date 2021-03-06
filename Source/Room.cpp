#include "Room.h"

Room::Room(unsigned char id, double maxLife):
	m_id(id),
	m_burnableObjects(),
	m_fireSensors(),

	m_maxLife(maxLife),
	m_currentLife(maxLife)
{}

Room::~Room()
{
	for(int i = 0; i < m_burnableObjects.size();i++)
		delete m_burnableObjects[i];

	for (int i = 0; i < m_fireSensors.size(); i++)
		delete m_fireSensors[i];
}


void Room::addFurniture(BurnableObject * burnableObject)
{
	m_burnableObjects.push_back(burnableObject);
}

void Room::addFireSensor(FireSensor * fireSensor)
{
	m_fireSensors.push_back(fireSensor);
}

std::vector<BurnableObject*>* Room::getBurnableObjects()
{
	return & m_burnableObjects;
}

std::vector<FireSensor*>* Room::getFireSensors()
{
	return & m_fireSensors;
}

void Room::setDamage(const double damage)
{
	m_currentLife -= damage;
}

void Room::stopFire()
{
	for (int i = 0; i<m_burnableObjects.size(); i++)
		m_burnableObjects[i]->stopFire();
}

unsigned char Room::getRoomId() const
{
	return m_id;
}

double Room::getLife() const
{
	return m_currentLife;
}

double Room::getMaxLife() const
{
	return m_maxLife;
}

void Room::draw(sf::RenderWindow * window)
{
	for(int i = 0; i<m_fireSensors.size(); i++)
		m_fireSensors[i]->draw(window);

	for (int i = 0; i<m_burnableObjects.size(); i++)
		m_burnableObjects[i]->draw(window);
}

void Room::update(sf::Clock const & clk)
{
	for (int i = 0; i<m_fireSensors.size(); i++)
		m_fireSensors[i]->update(clk);

	for (int i = 0; i<m_burnableObjects.size(); i++)
		m_burnableObjects[i]->update(clk);
}