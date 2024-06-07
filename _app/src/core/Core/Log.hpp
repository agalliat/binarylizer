#pragma once

#include <spdlog/fmt/ostr.h>
#include <spdlog/spdlog.h>

#include <memory>

namespace App {

class Log {
 public:
  Log(const Log&) = delete;
  Log(const Log&&) = delete;
  Log& operator=(const Log&) = delete;
  Log& operator=(const Log&&) = delete;
  ~Log() = default;

  static std::shared_ptr<spdlog::logger>& logger() {
    return get().m_logger;
  }

 private:
  // The constructor shall not be deleted but used to bootstrap the logger. Ignoring
  // the lint warning is ignoring doing `Log() = delete`.
  // NOLINTNEXTLINE
  Log();

  static Log& get() {
    static Log instance{};
    return instance;
  }

  std::shared_ptr<spdlog::logger> m_logger;
};

}  // namespace App

#ifndef APP_DEACTIVATE_LOGGING

#if DEBUG
#define LOG_TRACE(...) ::App::Log::logger()->trace(__VA_ARGS__)
#define LOG_DEBUG(...) ::App::Log::logger()->debug(__VA_ARGS__)
#else
#define LOG_TRACE(...)
#define LOG_DEBUG(...)
#endif

#define LOG_INFO(...) ::App::Log::logger()->info(__VA_ARGS__)
#define LOG_WARN(...) ::App::Log::logger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::App::Log::logger()->error(__VA_ARGS__)
#define LOG_FATAL(...) ::App::Log::logger()->fatal(__VA_ARGS__)

#else

#define LOG_TRACE(...)
#define LOG_DEBUG(...)
#define LOG_INFO(...)
#define LOG_WARN(...)
#define LOG_ERROR(...)
#define LOG_FATAL(...)

#endif
