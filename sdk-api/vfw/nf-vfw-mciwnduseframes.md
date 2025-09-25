# MCIWndUseFrames macro

## Syntax

```cpp
LONG MCIWndUseFrames(
     hwnd
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndUseFrames** macro sets the time format of an MCI device to frames. You can use this macro or explicitly send the [MCIWNDM_SETTIMEFORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-settimeformat) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.