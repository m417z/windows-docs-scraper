# MCIWndGetPosition macro

## Syntax

```cpp
LONG MCIWndGetPosition(
     hwnd
);
```

## Return value

Type: **LONG**

Returns an integer corresponding to the current position. The units for the position value depend on the current time format.

## Description

The **MCIWndGetPosition** macro retrieves the numerical value of the current position within the content of the MCI device. You can use this macro or explicitly send the [MCIWNDM_GETPOSITION](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getposition) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_GETPOSITION](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getposition)