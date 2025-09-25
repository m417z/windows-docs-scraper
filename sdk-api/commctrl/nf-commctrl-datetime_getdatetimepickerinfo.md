# DateTime_GetDateTimePickerInfo macro

## Syntax

```cpp
LRESULT DateTime_GetDateTimePickerInfo(
  [in]      HWND               hdp,
  [in, out] DATETIMEPICKERINFO *pdtpi
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Return value is ignored.

## Description

Gets information for a specified date and time picker (DTP) control.

## Parameters

### `hdp` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the DTP control.

### `pdtpi` [in, out]

Type: **[DATETIMEPICKERINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-datetimepickerinfo)***

[DATETIMEPICKERINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-datetimepickerinfo)
**cbSize**