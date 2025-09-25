# capDriverConnect macro

## Syntax

```cpp
BOOL capDriverConnect(
     hwnd,
     i
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if the specified capture driver cannot be connected to the capture window.

## Description

The **capDriverConnect** macro connects a capture window to a capture driver. You can use this macro or explicitly send the [WM_CAP_DRIVER_CONNECT](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-driver-connect) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `i`

Index of the capture driver. The index can range from 0 through 9.

## Remarks

Connecting a capture driver to a capture window automatically disconnects any previously connected capture driver.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)