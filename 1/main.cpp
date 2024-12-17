#include "machine.h"
#include <iostream>
#include <string>

int main()
{
   Snack *bounty = new Snack("Bounty");
   bounty->setSnackPrice(50);

   Snack *snickers = new Snack("Snickers");
   snickers->setSnackPrice(60);

   SnackSlot *slot = new SnackSlot(10);

   slot->addSnack(bounty);
   slot->addSnack(snickers);

   VendingMachine *machine = new VendingMachine(5);
   machine->addSnackSlot(slot);

   std::cout << "Current prices:" << std::endl;
   bounty->showInfo();
   snickers->showInfo();

   int newPrice;

   std::cout << "Enter new price for Bounty: ";
   std::cin >> newPrice;
   bounty->setSnackPrice(newPrice);

   std::cout << "Enter new price for Snickers: ";
   std::cin >> newPrice;
   snickers->setSnackPrice(newPrice);

   std::cout << "Updated prices:" << std::endl;
   bounty->showInfo();
   snickers->showInfo();

   std::cout << "Number of empty slots: " << machine->calculateEmptySlots() << std::endl;

   delete machine;
   delete slot;
   delete snickers;
   delete bounty;

   return 0;
}
