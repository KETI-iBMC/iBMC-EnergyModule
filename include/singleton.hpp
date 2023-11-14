#ifndef __SINGLETON__
#define __SINGLETON__

template <typename T>
class Singleton {
     protected:
          static T* instance;
          Singleton(){}
          Singleton(const T& ref){}
          T& operator=(const T& ref){}
          ~Singleton(){}
     public:
          static T* getInstance(){
               if(instance == nullptr){
                    instance = new T;
               }
               return instance;
          }
};

template <typename T>
T* Singleton<T>::instance = nullptr;


class IEnergyThread {
protected:
     std::thread* energy_thread_handler;
     virtual void energyLoop() = 0;

public:
     std::thread* get_thread(){
          return this->energy_thread_handler;
     }

     void stopThread(){
          (*energy_thread_handler).join();
          delete energy_thread_handler;
     }

     void startThread(){
          this->energy_thread_handler = new std::thread([&](){this->energyLoop();});
     }
};

template <typename T>
class Monostate : public IEnergyThread {
protected:
     static T& instance(){
          static T theinstance;
          return theinstance;
     }
};

#endif