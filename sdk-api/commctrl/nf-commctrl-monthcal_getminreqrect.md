# MonthCal_GetMinReqRect macro

## Syntax

```cpp
BOOL MonthCal_GetMinReqRect(
   HWND   hmc,
   LPRECT prc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero and **MonthCal_GetMinReqRect** receives the applicable bounding information if successful. Otherwise, the return is zero.

## Description

Retrieves the minimum size required to display a full month in a month calendar control. Size information is presented in the form of a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure. You can use this macro or send the [MCM_GETMINREQRECT](https://learn.microsoft.com/windows/desktop/Controls/mcm-getminreqrect) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `prc`

Type: **LPRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that will receive bounding rectangle information. This parameter must be a valid address and cannot be **NULL**.

## Remarks

The minimum required window size for a month calendar control depends on the currently selected font, control styles, system metrics, and regional settings. When an application changes anything that affects the minimum window size, or processes a [WM_SETTINGCHANGE](https://learn.microsoft.com/windows/desktop/winmsg/wm-settingchange) message, it should call **MonthCal_GetMinReqRect** to determine the new minimum size.

**Note** The rectangle returned by **MonthCal_GetMinReqRect** does not include the width of the "Today" string, if it is present. If the [MCS_NOTODAY](https://learn.microsoft.com/windows/desktop/Controls/month-calendar-control-styles) style is not set, your application should also retrieve the rectangle that defines the "Today" string width by calling the [MonthCal_GetMaxTodayWidth](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-monthcal_getmaxtodaywidth) macro. Use the larger of the two rectangles to ensure that the "Today" string is not clipped.

The **top** and **left** members of *prc* will always be zero. The **right** and **bottom** members represent the minimum *cx* and *cy* required for the control.