# MCIWndGetFileName macro

## Syntax

```cpp
LONG MCIWndGetFileName(
     hwnd,
     lp,
     len
);
```

## Return value

Type: **LONG**

Returns zero if successful or 1 otherwise.

## Description

The **MCIWndGetFileName** macro retrieves the filename used by an MCI device. You can use this macro or explicitly send the [MCIWNDM_GETFILENAME](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getfilename) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `lp`

Pointer to an application-defined buffer to return the filename.

### `len`

Size, in bytes, of the buffer.

## Remarks

If the null-terminated string containing the filename is longer than the buffer, MCIWnd truncates the filename.

## See also

[MCIWNDM_GETFILENAME](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getfilename)