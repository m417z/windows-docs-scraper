# MCIWndReturnString macro

## Syntax

```cpp
LONG MCIWndReturnString(
     hwnd,
     lp,
     len
);
```

## Return value

Type: **LONG**

Returns an integer corresponding to the MCI string.

## Description

The **MCIWndReturnString** macro retrieves the reply to the most recent MCI string command sent to an MCI device. Information in the reply is supplied as a null-terminated string. You can use this macro or explicitly send the [MCIWNDM_RETURNSTRING](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-returnstring) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `lp`

Pointer to an application-defined buffer to contain the null-terminated string.

### `len`

Size, in bytes, of the buffer.

## Remarks

If the null-terminated string is longer than the buffer, the string is truncated.