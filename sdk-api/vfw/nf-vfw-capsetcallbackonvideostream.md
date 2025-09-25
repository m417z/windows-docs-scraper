# capSetCallbackOnVideoStream macro

## Syntax

```cpp
BOOL capSetCallbackOnVideoStream(
     hwnd,
     fpProc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if streaming capture or a single-frame capture session is in progress.

## Description

The **capSetCallbackOnVideoStream** macro sets a callback function in the application. AVICap calls this procedure during streaming capture when a video buffer is filled. You can use this macro or explicitly call the [WM_CAP_SET_CALLBACK_VIDEOSTREAM](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-callback-videostream) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `fpProc`

Pointer to the video-stream callback function, of type [capVideoStreamCallback](https://learn.microsoft.com/windows/desktop/api/vfw/nc-vfw-capvideocallback). Specify **NULL** for this parameter to disable a previously installed video-stream callback function.

## Remarks

The capture window calls the callback function before writing the captured frame to disk. This allows applications to modify the frame if desired.

If a video stream callback function is used for streaming capture, the procedure must be installed before starting the capture session and it must remain enabled for the duration of the session. It can be disabled after streaming capture ends.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)