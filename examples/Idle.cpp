#include "libuv_plus/core/Loop.hpp"
#include <iostream>
#include <memory>

int64_t counter = 0;
void wait_for_a_while(uv_idle_t *handle) {
  counter++;
  std::cout << "Counter: " << counter << std::endl;
  if (counter >= 5)
    uv_idle_stop(handle);
}

void IdleUse() {
  std::unique_ptr<Loop> loop = std::make_unique_for_overwrite<Loop>();
  loop->Init();
  uv_idle_t idler;
  uv_idle_init(loop->GetC(), &idler);
  uv_idle_start(&idler, wait_for_a_while);
  printf("Idling...\n");
  loop->Run();
};

void TimerUse() {
  std::unique_ptr<Loop> loop = std::make_unique_for_overwrite<Loop>();
  loop->Init();
  uv_timer_t timer;
  uv_timer_init(loop->GetC(), &timer);
  uv_timer_start(
      &timer,
      [](uv_timer_t *handle) {
        std::cout << "Timer expired" << std::endl;
        uv_timer_stop(handle);
      },
      5000, 0);
  printf("Waiting...\n");
  loop->Run();
};

int main() {
  IdleUse();
  TimerUse();
  return 0;
}
