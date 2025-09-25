# MonthCal_SetCurrentView macro

## Syntax

```cpp
BOOL MonthCal_SetCurrentView(
   HWND  hmc,
   DWORD dwNewView
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if successful, or zero otherwise.

## Description

Sets the view for a month calendar control. You can use this macro or send the [MCM_SETCURRENTVIEW](https://learn.microsoft.com/windows/desktop/Controls/mcm-setcurrentview) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `dwNewView`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

New view. One of the following constants.

| Value | Meaning |
| --- | --- |
| **MCMV_MONTH** | Monthly view. |
| **MCMV_YEAR** | Annual view. |
| **MCMV_DECADE** | Decade view. |
| **MCMV_CENTURY** | Century view. |