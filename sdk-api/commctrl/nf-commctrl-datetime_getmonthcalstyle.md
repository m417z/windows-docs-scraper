# DateTime_GetMonthCalStyle macro

## Syntax

```cpp
LRESULT DateTime_GetMonthCalStyle(
  [in] HWND hdp
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the style value of the control. For more information see Month Calendar Control Styles.

## Description

Gets the style of a specified date and time picker (DTP) control. Use this macro or send the [DTM_GETMCSTYLE](https://learn.microsoft.com/windows/desktop/Controls/dtm-getmcstyle) message explicitly.

## Parameters

### `hdp` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the DTP control.