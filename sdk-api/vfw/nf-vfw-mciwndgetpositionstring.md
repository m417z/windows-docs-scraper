# MCIWndGetPositionString macro

## Syntax

```cpp
LONG MCIWndGetPositionString(
     hwnd,
     lp,
     len
);
```

## Return value

Type: **LONG**

Returns an integer corresponding to the current position. The units for the position value depend on the current time format.

## Description

The **MCIWndGetPositionString** macro retrieves the numerical value of the current position within the content of the MCI device. This macro also provides the current position in string form in an application-defined buffer. You can use this macro or explicitly send the [MCIWNDM_GETPOSITION](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getposition) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `lp`

Pointer to an application-defined buffer used to return the position. Use zero to inhibit retrieval of the position as a string. If the device supports tracks, the string position information is returned in the form TT:MM:SS:FF where TT corresponds to tracks, MM and SS correspond to minutes and seconds, and FF corresponds to frames.

### `len`

Size, in bytes, of the buffer. If the null-terminated string is longer than the buffer, it is truncated. Use zero to inhibit retrieval of the position as a string.

## See also

[MCIWNDM_GETPOSITION](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getposition)