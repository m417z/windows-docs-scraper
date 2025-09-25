# CAPYIELDCALLBACK callback function

## Description

The **capYieldCallback** function is the yield callback function used with video capture. The name **capYieldCallback** is a placeholder for the application-supplied function name.

To set the callback, send the [WM_CAP_SET_CALLBACK_YIELD](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-callback-yield) message to the capture window or call the [capSetCallbackOnYield](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonyield) macro.

## Parameters

### `hWnd`

Handle to the capture window associated with the callback function.

## Remarks

The capture window calls the yield callback function at least once for every captured video frame, but the exact rate depends on the frame rate and the overhead of the capture driver and disk.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-functions)