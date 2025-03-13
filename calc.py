def add(x, y):
    return x + y

def subtract(x, y):
    return x - y

def multiply(x, y):
    return x * y

def divide(x, y):
    if y == 0:
        return "Ошибка! Деление на ноль."
    return x / y

def calculator():
    print("Выберите операцию:")
    print("1. Сложение")
    print("2. Вычитание")
    print("3. Умножение")
    print("4. Деление")

    while True:
        try:
            choice = input("Введите номер операции (1/2/3/4): ")

            if choice in ['1', '2', '3', '4']:
                num1 = float(input("Введите первое число: "))
                num2 = float(input("Введите второе число: "))

                if choice == '1':
                    print(f"{num1} + {num2} = {add(num1, num2)}")
                elif choice == '2':
                    print(f"{num1} - {num2} = {subtract(num1, num2)}")
                elif choice == '3':
                    print(f"{num1} * {num2} = {multiply(num1, num2)}")
                elif choice == '4':
                    print(f"{num1} / {num2} = {divide(num1, num2)}")

                next_calculation = input("Хотите выполнить еще одну операцию? (да/нет): ").lower()
                if next_calculation != 'да':
                    break
            else:
                print("Некорректный ввод. Пожалуйста, выберите номер операции из списка.")
        except ValueError:
            print("Ошибка! Пожалуйста, введите числовое значение.")

if __name__ == "__main__":
    calculator()
