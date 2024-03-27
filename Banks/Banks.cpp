#include <iostream>
#include <locale>
#include <iomanip>

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    BankAccount(int accountNum, double initialBalance) {
        accountNumber = accountNum;
        balance = initialBalance;
        interestRate = 0.0;
    }

    // Внести средства на счет
    void deposit(double amount) {
        balance += amount;
    }

    // Снять средства со счета
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        }
        else {
            std::cout << "Ошибка. Недостаточно средств на счете" << std::endl;
        }
    }

    // Рассчитать и вернуть текущий баланс
    double getBalance() {
        return balance;
    }

    // Рассчитать и вернуть сумму процентов
    double getInterest() {
        return balance * interestRate * (1.0 / 12.0);
    }

    // Обновить процентную ставку
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    // Получить номер банковского счёта
    int getAccountNumber() {
        return accountNumber;
    }

    // Функция перевода средств между двумя счетами
    friend bool transfer(BankAccount& fromAccount, BankAccount& toAccount, double amount) {
        if (amount <= fromAccount.balance) {
            fromAccount.balance -= amount;
            toAccount.balance += amount;
            return true;
        }
        else {
            std::cout << "Ошибка. Недостаточно средств на счете для перевода" << std::endl;
            return false;
        }
    }
};

int main() {
    setlocale(LC_ALL, "");

    std::cout << "Введите номер счета:";
    int accNumber;
    std::cin >> accNumber;
    std::cout << "Ведите баланс:";
    double accBalance;
    std::cin >> accBalance;
    BankAccount firstAccount(accNumber, accBalance);
    std::cout << "Счет создан";

    BankAccount secondAccount(999999999999999999, 999999999);
    std::cout << "\nВведите сумму перевода:";
    double money1;
    std::cin >> money1;
    transfer(firstAccount, secondAccount, money1);

    std::cout << "\nВведите сумму взноса: ";
    double summaVsnosa;
    std::cin >> summaVsnosa;
    firstAccount.deposit(summaVsnosa);

    std::cout << "\nВведите сумму снятия: ";
    double summaSnyatia;
    std::cin >> summaSnyatia;
    firstAccount.withdraw(summaSnyatia);

    std::cout << "\nПроцент: ";
    firstAccount.getInterest();

    std::cout << "\nОбновить процент: ";
    double newProcent;
    std::cin >> newProcent;
    firstAccount.setInterestRate(newProcent);

    return 0;
}