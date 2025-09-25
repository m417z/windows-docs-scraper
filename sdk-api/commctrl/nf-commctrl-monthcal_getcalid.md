# MonthCal_GetCALID macro

## Syntax

```cpp
CALID MonthCal_GetCALID(
   HWND hmc
);
```

## Return value

Type: **CALID**

ID of the current calendar. One of the Calendar Identifiers constants.

## Description

Gets the current calendar ID for the given calendar control. You can use this macro or send the [MCM_GETCALID](https://learn.microsoft.com/windows/desktop/Controls/mcm-getcalid) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.