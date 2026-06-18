#include <iostream>
#include <memory>

class Resource {
public:
    Resource(int id) : id_(id) {
        std::cout << "Resource " << id_ << " создан" << std::endl;
    }
    ~Resource() {
        std::cout << "Resource " << id_ << " уничтожен" << std::endl;
    }
    void use() { std::cout << "Используем Resource " << id_ << std::endl; }
private:
    int id_;
};

int main() {
    // === Эксперимент 1: unique_ptr ===
    std::cout << "--- unique_ptr ---" << std::endl;
    {
        auto ptr = std::make_unique<Resource>(1);
        ptr->use();
        // здесь ptr выйдет из области видимости — Resource 1 уничтожится
    }
    std::cout << "После блока unique_ptr" << std::endl;
    
    // === Эксперимент 2: move unique_ptr ===
    std::cout << "\n--- move unique_ptr ---" << std::endl;
    {
        auto ptr1 = std::make_unique<Resource>(2);
        auto ptr2 = std::move(ptr1);  // передали владение
        
        if (ptr1 == nullptr) std::cout << "ptr1 теперь пустой" << std::endl;
        ptr2->use();
        // Resource 2 уничтожится при выходе ptr2 из области видимости
    }
    
    // === Эксперимент 3: shared_ptr со счётчиком ===
    std::cout << "\n--- shared_ptr ---" << std::endl;
    {
        auto sp1 = std::make_shared<Resource>(3);
        std::cout << "Счётчик: " << sp1.use_count() << std::endl;
        {
            auto sp2 = sp1;  // копируем — счётчик +1
            std::cout << "Счётчик: " << sp1.use_count() << std::endl;
            auto sp3 = sp1;
            std::cout << "Счётчик: " << sp1.use_count() << std::endl;
        }
        // sp2 и sp3 умерли — счётчик упал
        std::cout << "После внутреннего блока, счётчик: " << sp1.use_count() << std::endl;
    }
    std::cout << "Resource 3 должен быть уничтожен" << std::endl;
    
    return 0;
}