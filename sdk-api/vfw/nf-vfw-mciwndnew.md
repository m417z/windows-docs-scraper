# MCIWndNew macro

## Syntax

```cpp
LONG MCIWndNew(
     hwnd,
     lp
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndNew** macro creates a new file for the current MCI device. You can use this macro or explicitly send the [MCIWNDM_NEW](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-new) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `lp`

Pointer to a buffer containing the name of the MCI device that will use the file.

## See also

[MCIWNDM_NEW](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-new)