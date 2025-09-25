# MCIWndGetStyles macro

## Syntax

```cpp
UINT MCIWndGetStyles(
     hwnd
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a value representing the current styles of the MCIWnd window. The return value is the bitwise OR operator of the MCIWnd window styles (MCIWNDF flags).

## Description

The **MCIWndGetStyles** macro retrieves the flags specifying the current MCIWnd window styles used by a window. You can use this macro or explicitly send the [MCIWNDM_GETSTYLES](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getstyles) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_GETSTYLES](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getstyles)