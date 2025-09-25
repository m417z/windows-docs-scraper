# MCIWndSetSpeed macro

## Syntax

```cpp
LONG MCIWndSetSpeed(
     hwnd,
     iSpeed
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndSetSpeed** macro sets the playback speed of an MCI device. You can use this macro or explicitly send the [MCIWNDM_SETSPEED](https://learn.microsoft.com/windows/desktop/Multimedia/mciwndm-setspeed) message.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

### `iSpeed`

Playback speed. Specify 1000 for normal speed, larger values for faster speeds, and smaller values for slower speeds.