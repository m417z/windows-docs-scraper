# CAPWAVECALLBACK callback function

## Description

The **capWaveStreamCallback** function is the callback function used with streaming capture to optionally process buffers of audio data. The name **capWaveStreamCallback** is a placeholder for the application-supplied function name.

To set the callback, send the [WM_CAP_SET_CALLBACK_WAVESTREAM](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-callback-wavestream) message to the capture window or call the [capSetCallbackOnWaveStream](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonwavestream) macro.

## Parameters

### `hWnd`

Handle to the capture window associated with the callback function.

### `lpWHdr`

Pointer to a [WAVEHDR](https://learn.microsoft.com/previous-versions/dd743837(v=vs.85)) structure containing information about the captured audio data.

## Remarks

The capture window calls a wave stream callback function when an audio buffer is marked done by the waveform-audio driver. When capturing to disk, this will precede the disk write operation.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-functions)