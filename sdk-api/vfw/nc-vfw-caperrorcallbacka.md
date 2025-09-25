# CAPERRORCALLBACKA callback function

## Description

The **capErrorCallback** function is the error callback function used with video capture. The name **capErrorCallback** is a placeholder for the application-supplied function name.

To set the callback, send the [WM_CAP_SET_CALLBACK_ERROR](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-callback-error) message to the capture window or call the [capSetCallbackOnError](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonerror) macro.

## Parameters

### `hWnd`

Handle to the capture window associated with the callback function.

### `nID`

Error identification number.

### `lpsz`

Pointer to a textual description of the returned error.

## Remarks

A message identifier of zero indicates a new operation is starting and the callback function should clear the current error.

> [!NOTE]
> The vfw.h header defines CAPERRORCALLBACK as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-functions)