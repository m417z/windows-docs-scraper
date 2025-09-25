# MCIWndGetSpeed macro

## Syntax

```cpp
LONG MCIWndGetSpeed(
     hwnd
);
```

## Return value

Type: **LONG**

Returns the playback speed if successful. The value for normal speed is 1000. Larger values indicate faster speeds; smaller values indicate slower speeds.

## Description

The **MCIWndGetSpeed** macro retrieves the playback speed of an MCI device. You can use this macro or explicitly send the [MCIWNDM_GETSPEED](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getspeed) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## See also

[MCIWNDM_GETSPEED](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-getspeed)