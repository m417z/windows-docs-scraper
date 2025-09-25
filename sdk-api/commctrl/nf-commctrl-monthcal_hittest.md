# MonthCal_HitTest macro

## Syntax

```cpp
DWORD MonthCal_HitTest(
   HWND           hmc,
   PMCHITTESTINFO pinfo
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Sets values in members of the **MCHITTESTINFO** structure at *pinfo* and returns a **DWORD** value that contains a set of hit test result flags. See the return value description of **MCM_HITTEST** for a list of the hit test result flags.

## Description

Determines which portion of a month calendar control is at a given point on the screen. You can use this macro or send the [MCM_HITTEST](https://learn.microsoft.com/windows/desktop/Controls/mcm-hittest) message explicitly.

## Parameters

### `hmc`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a month calendar control.

### `pinfo`

Type: **PMCHITTESTINFO**

Pointer to an [MCHITTESTINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-mchittestinfo) structure. Upon calling the macro, the **cbSize** member must be set to the size of the **MCHITTESTINFO** structure, and **pt** must be set to the point you want to hit test.