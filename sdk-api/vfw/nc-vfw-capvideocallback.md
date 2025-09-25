# CAPVIDEOCALLBACK callback function

## Description

The **capVideoStreamCallback** function is the callback function used with streaming capture to optionally process a frame of captured video. The name **capVideoStreamCallback** is a placeholder for the application-supplied function name.

To set this callback for streaming capture, send the [WM_CAP_SET_CALLBACK_VIDEOSTREAM](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-callback-videostream) message to the capture window or call the [capSetCallbackOnVideoStream](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonvideostream) macro.

To set this callback for preview frame capture, send the [WM_CAP_SET_CALLBACK_FRAME](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-callback-frame) message to the capture window or call the [capSetCallbackOnFrame](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonframe) macro.

## Parameters

### `hWnd`

Handle to the capture window associated with the callback function.

### `lpVHdr`

Pointer to a [VIDEOHDR](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-videohdr) structure containing information about the captured frame.

## Remarks

The capture window calls a video stream callback function when a video buffer is marked done by the capture driver. When capturing to disk, this will precede the disk write operation.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-functions)