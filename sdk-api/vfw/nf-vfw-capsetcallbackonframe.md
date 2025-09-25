# capSetCallbackOnFrame macro

## Syntax

```cpp
BOOL capSetCallbackOnFrame(
     hwnd,
     fpProc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if streaming capture or a single-frame capture session is in progress.

## Description

The **capSetCallbackOnFrame** macro sets a preview callback function in the application. AVICap calls this procedure when the capture window captures preview frames. You can use this macro or explicitly call the [WM_CAP_SET_CALLBACK_FRAME](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-callback-frame) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `fpProc`

Pointer to the preview callback function, of type [capVideoStreamCallback](https://learn.microsoft.com/windows/desktop/api/vfw/nc-vfw-capvideocallback). Specify **NULL** for this parameter to disable a previously installed callback function.

## Remarks

The capture window calls the callback function before displaying preview frames. This allows an application to modify the frame if desired. This callback function is not used during streaming video capture.

## See also

[Creating a Frame Callback Function](https://learn.microsoft.com/windows/desktop/Multimedia/creating-a-frame-callback-function)

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)