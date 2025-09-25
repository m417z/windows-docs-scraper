# capGrabFrame macro

## Syntax

```cpp
BOOL capGrabFrame(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capGrabFrame** macro retrieves and displays a single frame from the capture driver. After capture, overlay and preview are disabled. You can use this macro or explicitly call the [WM_CAP_GRAB_FRAME](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-grab-frame) message.

## Parameters

### `hwnd`

Handle to a capture window.

## Remarks

For information about installing callback functions, see the [capSetCallbackOnError](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonerror) and [capSetCallbackOnFrame](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonframe) macros.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)