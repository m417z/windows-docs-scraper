# DateTime_SetMonthCalStyle macro

## Syntax

```cpp
LRESULT DateTime_SetMonthCalStyle(
  [in] HWND  hdp,
  [in] DWORD dwStyle
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the value of the previous style.

## Description

Sets the style for a specified date and time picker (DTP) control. Use this macro or send the [DTM_SETMCSTYLE](https://learn.microsoft.com/windows/desktop/Controls/dtm-setmcstyle) message explicitly.

## Parameters

### `hdp` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the DTP.

### `dwStyle` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[Month Calendar Control Styles](https://learn.microsoft.com/windows/desktop/Controls/month-calendar-control-styles)