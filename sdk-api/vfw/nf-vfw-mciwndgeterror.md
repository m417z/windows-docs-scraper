# MCIWndGetError macro

## Syntax

```cpp
LONG MCIWndGetError(
     hwnd,
     lp,
     len
);
```

## Return value

Type: **LONG**

Returns the integer error value if successful.

## Description

The **MCIWndGetError** macro retrieves the last MCI error encountered. You can use this macro or explicitly send the [MCIWNDM_GETERROR](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-geterror) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `lp`

Pointer to an application-defined buffer used to return the error string.

### `len`

Size, in bytes, of the error buffer.

## Remarks

If *lp* is a valid pointer, a null-terminated string corresponding to the error is returned in its buffer. If the error string is longer than the buffer, MCIWnd truncates it.

## See also

[MCIWNDM_GETERROR](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-geterror)