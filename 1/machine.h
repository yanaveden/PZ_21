#include <iostream>
#include <string>

class Snack {

public:
    Snack(std::string snackName);
    Snack();
    ~Snack();

    void setSnackName(std::string snackName);
    std::string getSnackName();
    
    void setSnackPrice(int price);
    int getSnackPrice();
    
    void showInfo();
private:
    std::string _snackName;
    int _snackPrice;
};
//----------------------------------------

class SnackSlot {
public:
    static int _slotCount;

    SnackSlot(int slotCapacity);
    SnackSlot();
    ~SnackSlot();

    void setCapacity(int places);
    int getCapacity();

    void addSnack(Snack* snack);
    int getTotalSnacks();  // Возвращает общее количество снеков в слоте

    static int getTotalSlots();
    
    void showInfo();
private:
    int _slotCapacity;
    Snack* _snacks[10]; // Максимум 10 снека в слоте
    int _currentSnackCount;
};
//----------------------------------------

class VendingMachine {
public:
    VendingMachine(int totalSlots);
    VendingMachine();
    ~VendingMachine();

    void setSlots(int totalSlots);
    int getSlots();

    void addSnackSlot(SnackSlot* snackslot);
    
    int calculateEmptySlots();
    
    void showInfo();
private:
    int _totalSlots;
    SnackSlot* _snackSlots[5]; // Максимум 5 слотов
    int _currentSlotCount;
};
