# CAPCONTROLCALLBACK callback function

## Description

The **capControlCallback** function is the callback function used for precision control to begin and end streaming capture. The name **capControlCallback** is a placeholder for the application-supplied function name.

To set the callback, send the [WM_CAP_SET_CALLBACK_CAPCONTROL](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-callback-capcontrol) message to the capture window or call the [capSetCallbackOnCapControl](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackoncapcontrol) macro.

## Parameters

### `hWnd`

Handle to the capture window associated with the callback function.

### `nState`

Current state of the capture operation. The CONTROLCALLBACK_PREROLL value is sent initially to enable prerolling of the video sources and to return control to the capture application at the exact moment recording is to begin. The CONTROLCALLBACK_CAPTURING value is sent once per captured frame to indicate that streaming capture is in progress and to enable the application to end capture.

## Return value

When *nState* is set to CONTROLCALLBACK_PREROLL, this callback function must return **TRUE** to start capture or **FALSE** to abort it. When *nState* is set to CONTROLCALLBACK_CAPTURING, this callback function must return **TRUE** to continue capture or **FALSE** to end it.

## Remarks

The first message sent to the callback procedure sets the *nState* parameter to CONTROLCALLBACK_PREROLL after allocating all buffers and all other capture preparations are complete.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-functions)