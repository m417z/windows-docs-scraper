# Button_SetElevationRequiredState macro

## Syntax

```cpp
LRESULT Button_SetElevationRequiredState(
  [in] HWND hwnd,
  [in] BOOL fRequired
);
```

## Return value

Type: **[LRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns 1 if successful, or an error code otherwise.

## Description

Sets the elevation required state for a specified button or command link to display an elevated icon. Use this macro or send the [BCM_SETSHIELD](https://learn.microsoft.com/windows/desktop/Controls/bcm-setshield) message explicitly.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

### `fRequired` [in]

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to draw an elevated icon, or **FALSE** otherwise.

## Remarks

An application must use comctl32.dll version 6 to gain this functionality.