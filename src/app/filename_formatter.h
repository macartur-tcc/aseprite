// Aseprite
// Copyright (C) 2001-2015  David Capello
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.

#ifndef APP_FILENAME_FORMATTER_H_INCLUDED
#define APP_FILENAME_FORMATTER_H_INCLUDED


#include <string>

namespace app {

  class FilenameInfo {
  public:
    FilenameInfo() : m_frame(-1) { }

    const std::string& filename() const { return m_filename; }
    const std::string& layerName() const { return m_layerName; }
    const std::string& innerTagName() const { return m_innerTagName; }
    const std::string& outerTagName() const { return m_outerTagName; }
    int frame() const { return m_frame; }

    FilenameInfo& filename(const std::string& value) {
      m_filename = value;
      return *this;
    }

    FilenameInfo& layerName(const std::string& value) {
      m_layerName = value;
      return *this;
    }

    FilenameInfo& innerTagName(const std::string& value) {
      m_innerTagName = value;
      return *this;
    }

    FilenameInfo& outerTagName(const std::string& value) {
      m_outerTagName = value;
      return *this;
    }

    FilenameInfo& frame(int value) {
      m_frame = value;
      return *this;
    }

  private:
    std::string m_filename;
    std::string m_layerName;
    std::string m_innerTagName;
    std::string m_outerTagName;
    int m_frame;
  };

  std::string filename_formatter(
    const std::string& format,
    FilenameInfo& info,
    bool replaceFrame = true);

  std::string set_frame_format(
    const std::string& format,
    const std::string& newFrameFormat);

  std::string add_frame_format(
    const std::string& format,
    const std::string& newFrameFormat);

} // namespace app

#endif
