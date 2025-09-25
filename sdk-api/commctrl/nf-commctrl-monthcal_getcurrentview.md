# MonthCal_GetCurrentView macro

## Syntax

```cpp
DWORD MonthCal_GetCurrentView(
   HWND hmc
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Current view. One of the following values.

| Return code | Description |
|---|---|
| MCMV_MONTH | Monthly view. |
| MCMV_YEAR | Annual view. |
| MCMV_DECADE | Decade view. |
| MCMV_CENTURY | Century view. |

## Description

Gets the view for a month calendar control. You can use this macro or send the [MCM_GETCURRENTVIEW](https://learn.microsoft.com/windows/desktop/Controls/mcm-getcurrentview) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.