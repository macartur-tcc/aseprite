// Aseprite UI Library
// Copyright (C) 2001-2013, 2015  David Capello
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#ifndef UI_TOOLTIPS_H_INCLUDED
#define UI_TOOLTIPS_H_INCLUDED


#include "base/unique_ptr.h"
#include "ui/base.h"
#include "ui/popup_window.h"
#include "ui/timer.h"
#include "ui/window.h"

#include <map>

namespace ui {

  class TipWindow;

  class TooltipManager : public Widget
  {
  public:
    TooltipManager();
    ~TooltipManager();

    void addTooltipFor(Widget* widget, const std::string& text, int arrowAlign = 0);
    void removeTooltipFor(Widget* widget);

  protected:
    bool onProcessMessage(Message* msg) override;

  private:
    void onTick();

    struct TipInfo {
      std::string text;
      int arrowAlign;

      TipInfo() { }
      TipInfo(const std::string& text, int arrowAlign)
        : text(text), arrowAlign(arrowAlign) {
      }
    };

    typedef std::map<Widget*, TipInfo> Tips;
    Tips m_tips;                      // All tips.
    base::UniquePtr<TipWindow> m_tipWindow; // Frame to show tooltips.
    base::UniquePtr<Timer> m_timer;         // Timer to control the tooltip delay.
    struct {
      Widget* widget;
      TipInfo tipInfo;
    } m_target;
  };

  class TipWindow : public PopupWindow {
  public:
    TipWindow(const std::string& text, const gfx::Rect& target);
    ~TipWindow();

    int getArrowAlign() const;
    void setArrowAlign(int arrowAlign);

    void setCloseOnKeyDown(bool state);

    const gfx::Rect& target() const { return m_target; }

  protected:
    bool onProcessMessage(Message* msg) override;
    void onPreferredSize(PreferredSizeEvent& ev) override;
    void onInitTheme(InitThemeEvent& ev) override;
    void onPaint(PaintEvent& ev) override;

  private:
    int m_arrowAlign;
    gfx::Rect m_target;
    bool m_closeOnKeyDown;
  };

} // namespace ui

#endif
