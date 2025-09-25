# MCIWndGetDevice macro

## Syntax

```cpp
LONG MCIWndGetDevice(
     hwnd,
     lp,
     len
);
```

## Return value

Type: **LONG**

Returns zero if successful or a nonzero value otherwise.

## Description

The **MCIWndGetDevice** macro retrieves the name of the current MCI device. You can use this macro or explicitly send the [MCIWNDM_GETDEVICE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getdevice) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `lp`

Pointer to an application-defined buffer to return the device name.

### `len`

Size, in bytes, of the buffer.

## Remarks

If the null-terminated string containing the device name is longer than the buffer, MCIWnd truncates it.

## See also

[MCIWNDM_GETDEVICE](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getdevice)