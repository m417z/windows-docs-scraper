# capDriverDisconnect macro

## Syntax

```cpp
BOOL capDriverDisconnect(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if the capture window is not connected to a capture driver.

## Description

The **capDriverDisconnect** macro disconnects a capture driver from a capture window. You can use this macro or explicitly send the [WM_CAP_DRIVER_DISCONNECT](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-driver-disconnect) message.

## Parameters

### `hwnd`

Handle to a capture window.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)