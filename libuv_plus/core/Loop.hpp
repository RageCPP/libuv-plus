#pragma once
#include <cassert>
#include <iostream>
#include <stdlib.h>
#include <uv.h>
#ifndef UVPLUS_CORE_LOOP_HPP
#define UVPLUS_CORE_LOOP_HPP
class Loop {
public:
  explicit Loop() = default;

  void Init() {
    assert(loop == nullptr);
    loop = static_cast<uv_loop_t *>(malloc(sizeof(uv_loop_t)));
    uv_loop_init(loop);
  }

  void Run() {
    assert(loop != nullptr);
    uv_run(loop, UV_RUN_DEFAULT);
  }

  uv_loop_t *GetC() const {
    assert(loop != nullptr);
    return loop;
  }

  ~Loop() {
    if (loop == nullptr)
      return;
    uv_loop_close(loop);
    free(loop);
    std::cout << "Loop deleted" << std::endl;
  }

private:
  uv_loop_t *loop = nullptr;
};
#endif
