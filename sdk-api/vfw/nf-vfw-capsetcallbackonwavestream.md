# capSetCallbackOnWaveStream macro

## Syntax

```cpp
BOOL capSetCallbackOnWaveStream(
     hwnd,
     fpProc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if streaming capture or a single-frame capture session is in progress.

## Description

The **capSetCallbackOnWaveStream** macro sets a callback function in the application. AVICap calls this procedure during streaming capture when a new audio buffer becomes available. You can use this macro or explicitly call the [WM_CAP_SET_CALLBACK_WAVESTREAM](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-callback-wavestream) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `fpProc`

Pointer to the wave stream callback function, of type [capWaveStreamCallback](https://learn.microsoft.com/windows/desktop/api/vfw/nc-vfw-capwavecallback). Specify **NULL** for this parameter to disable a previously installed wave stream callback function.

## Remarks

The capture window calls the procedure before writing the audio buffer to disk. This allows applications to modify the audio buffer if desired.

If a wave stream callback function is used, it must be installed before starting the capture session and it must remain enabled for the duration of the session. It can be disabled after streaming capture ends.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)