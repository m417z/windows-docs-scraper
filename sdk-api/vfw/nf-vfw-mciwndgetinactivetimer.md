# MCIWndGetInactiveTimer macro

## Syntax

```cpp
UINT MCIWndGetInactiveTimer(
     hwnd
);
```

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the update period, in milliseconds. The default value is 2000 milliseconds.

## Description

The **MCIWndGetInactiveTimer** macro retrieves the update period used when the MCIWnd window is the inactive window. You can use this macro or explicitly send the [MCIWNDM_GETINACTIVETIMER](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getinactivetimer) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_GETINACTIVETIMER](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getinactivetimer)