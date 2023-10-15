#pragma once
#include <future>
#include <optional>
#include <thread>

template <class T> class threadStruct {
private:
protected:
  std::promise<T> promise;
  std::future<T> future;
  bool doFutureGet = false;
  T returnVal;

public:
  std::optional<std::thread> thread;

  threadStruct() : future(promise.get_future()) {}

  std::promise<T> &&getReturnPoint() { return std::move(promise); }

  T getValue() {
    if (!doFutureGet) {
      returnVal = future.get();
      doFutureGet = true;
    }

    return returnVal;
  }
};