# MCIWndGetActiveTimer macro

## Syntax

```cpp
UINT MCIWndGetActiveTimer(
     hwnd
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the update period in milliseconds. The default is 500 milliseconds.

## Description

The **MCIWndGetActiveTimer** macro retrieves the update period used when the MCIWnd window is the active window. You can use this macro or explicitly send the [MCIWNDM_GETACTIVETIMER](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getactivetimer) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_GETACTIVETIMER](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getactivetimer)