# MCIWndUseTime macro

## Syntax

```cpp
LONG MCIWndUseTime(
     hwnd
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndUseTime** macro sets the time format of an MCI device to milliseconds. You can use this macro or explicitly send the [MCIWNDM_SETTIMEFORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-settimeformat) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.