# MCIWndCanWindow macro

## Syntax

```cpp
BOOL MCIWndCanWindow(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if the device supports window-oriented MCI commands or **FALSE** otherwise.

## Description

The **MCIWndCanWindow** macro determines if an MCI device supports window-oriented MCI commands. You can use this macro or explicitly send the [MCIWNDM_CAN_WINDOW](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-can-window) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_CAN_WINDOW](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-can-window)