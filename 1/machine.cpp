#include "machine.h"

int SnackSlot::_slotCount = 0;

Snack::Snack(std::string snackName) : _snackName(snackName), _snackPrice(0) {}

Snack::Snack() : _snackName("Unknown"), _snackPrice(0) {}

Snack::~Snack() {}

void Snack::setSnackName(std::string snackName)
{
    _snackName = snackName;
}

std::string Snack::getSnackName()
{
    return _snackName;
}

void Snack::setSnackPrice(int price)
{
    _snackPrice = price;
}

int Snack::getSnackPrice()
{
    return _snackPrice;
}

void Snack::showInfo()
{
    std::cout << "Snack: " << _snackName << std::endl <<" Price: " << _snackPrice << " rub." << std::endl;
}

//----------------------------------------
SnackSlot::SnackSlot(int slotCapacity) : _slotCapacity(slotCapacity), _currentSnackCount(0)
{
    ++_slotCount;
}

SnackSlot::SnackSlot() : _slotCapacity(0), _currentSnackCount(0)
{}

SnackSlot::~SnackSlot()
{
    --_slotCount;
}

void SnackSlot::setCapacity(int places)
{
    _slotCapacity = places;
}

int SnackSlot::getCapacity()
{
    return _slotCapacity;
}

void SnackSlot::addSnack(Snack *snack)
{
    if (_currentSnackCount < _slotCapacity)
    {
        _snacks[_currentSnackCount] = snack;
        ++_currentSnackCount;
        std::cout << "Added: "<< std::endl;
        snack->showInfo();
    }
    else
    {
        std::cout << "No free space to add snack." << std::endl;
    }
}

int SnackSlot::getTotalSnacks()
{
    return _currentSnackCount;
}

int SnackSlot::getTotalSlots()
{
    return _slotCount;
}

void SnackSlot::showInfo()
{
    std::cout << "Slot: available spaces " << (_slotCapacity - _currentSnackCount) << std::endl 
            << " Total snacks: " << getTotalSnacks() << std::endl;
}

//----------------------------------------
VendingMachine::VendingMachine(int totalSlots) : _totalSlots(totalSlots), _currentSlotCount(0) {}

VendingMachine::VendingMachine() : _totalSlots(0), _currentSlotCount(0) {}

VendingMachine::~VendingMachine() {}

void VendingMachine::setSlots(int totalSlots)
{
    _totalSlots = totalSlots;
}

int VendingMachine::getSlots()
{
    return _totalSlots;
}

void VendingMachine::addSnackSlot(SnackSlot *snackslot)
{
    // Проверяем, есть ли свободное место для добавления нового слота
    if (_currentSlotCount < _totalSlots)
    {
        // Если место есть, добавляем новый слот в массив слотов
        _snackSlots[_currentSlotCount] = snackslot;
        ++_currentSlotCount;
    }
    else
    {
        std::cout << "No space to add a new slot." << std::endl;
    }
}


int VendingMachine::calculateEmptySlots()
{
    int emptyCount = 0;

    for (int i = 0; i < _currentSlotCount; ++i)
    {
        // (емкость слота минус текущее количество снеков) и добавляем к общему счетчику
        emptyCount += (_snackSlots[i]->getCapacity() - _snackSlots[i]->getTotalSnacks());
    }

    return emptyCount;
}

void VendingMachine::showInfo()
{
    std::cout << "Total slots in the machine: " << _totalSlots << std::endl;
}
