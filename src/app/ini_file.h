// Aseprite
// Copyright (C) 2001-2015  David Capello
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.

#ifndef APP_INI_FILE_H_INCLUDED
#define APP_INI_FILE_H_INCLUDED


#include "gfx/rect.h"
#include "app/color.h"

namespace app {

  class ConfigModule {
  public:
    ConfigModule();
    ~ConfigModule();
  };

  void push_config_state();
  void pop_config_state();
  void flush_config_file();
  void set_config_file(const char* filename);

  std::string main_config_filename();

  const char* get_config_string(const char* section, const char* name, const char* value);
  void set_config_string(const char* section, const char* name, const char* value);

  int get_config_int(const char* section, const char* name, int value);
  void set_config_int(const char* section, const char* name, int value);

  float get_config_float(const char* section, const char* name, float value);
  void set_config_float(const char* section, const char* name, float value);

  double get_config_double(const char* section, const char* name, double value);
  void set_config_double(const char* section, const char* name, double value);

  bool get_config_bool(const char* section, const char* name, bool value);
  void set_config_bool(const char* section, const char* name, bool value);

  gfx::Rect get_config_rect(const char* section, const char* name, const gfx::Rect& rect);
  void set_config_rect(const char* section, const char* name, const gfx::Rect& rect);

  app::Color get_config_color(const char* section, const char* name, const app::Color& value);
  void set_config_color(const char* section, const char* name, const app::Color& value);

  void del_config_value(const char* section, const char* name);

  // Generic get/set_config_value functions

  inline const char* get_config_value(const char* section, const char* name, const char* value) {
    return get_config_string(section, name, value);
  }

  inline std::string get_config_value(const char* section, const char* name, const std::string& value) {
    return get_config_string(section, name, value.c_str());
  }

  inline bool get_config_value(const char* section, const char* name, bool value) {
    return get_config_bool(section, name, value);
  }

  template<typename T>
  inline T get_config_value(const char* section, const char* name, const T& value) {
    return static_cast<T>(get_config_int(section, name, static_cast<int>(value)));
  }

  inline float get_config_value(const char* section, const char* name, float value) {
    return get_config_float(section, name, value);
  }

  inline double get_config_value(const char* section, const char* name, double value) {
    return get_config_double(section, name, value);
  }

  inline gfx::Rect get_config_value(const char* section, const char* name, const gfx::Rect& value) {
    return get_config_rect(section, name, value);
  }

  inline app::Color get_config_value(const char* section, const char* name, const app::Color& value) {
    return get_config_color(section, name, value);
  }

  inline void set_config_value(const char* section, const char* name, const char* value) {
    set_config_string(section, name, value);
  }

  inline void set_config_value(const char* section, const char* name, const std::string& value) {
    set_config_string(section, name, value.c_str());
  }

  inline void set_config_value(const char* section, const char* name, bool value) {
    set_config_bool(section, name, value);
  }

  template<typename T>
  inline void set_config_value(const char* section, const char* name, const T& value) {
    set_config_int(section, name, static_cast<int>(value));
  }

  inline void set_config_value(const char* section, const char* name, float value) {
    set_config_float(section, name, value);
  }

  inline void set_config_value(const char* section, const char* name, double value) {
    set_config_double(section, name, value);
  }

  inline void set_config_value(const char* section, const char* name, const gfx::Rect& value) {
    set_config_rect(section, name, value);
  }

  inline void set_config_value(const char* section, const char* name, const app::Color& value) {
    set_config_color(section, name, value);
  }

} // namespace app

#endif
