# capSetCallbackOnError macro

## Syntax

```cpp
BOOL capSetCallbackOnError(
     hwnd,
     fpProc
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** if streaming capture or a single-frame capture session is in progress.

## Description

The **capSetCallbackOnError** macro sets an error callback function in the client application. AVICap calls this procedure when errors occur. You can use this macro or explicitly call the [WM_CAP_SET_CALLBACK_ERROR](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-callback-error) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `fpProc`

Pointer to the error callback function, of type [capErrorCallback](https://learn.microsoft.com/windows/desktop/api/vfw/nc-vfw-caperrorcallbacka). Specify **NULL** for this parameter to disable a previously installed error callback function.

## Remarks

Applications can optionally set an error callback function. If set, AVICap calls the error procedure in the following situations:

* The disk is full.
* A capture window cannot be connected with a capture driver.
* A waveform-audio device cannot be opened.
* The number of frames dropped during capture exceeds the specified percentage.
* The frames cannot be captured due to vertical synchronization interrupt problems.

## See also

[Creating an Error Callback Function](https://learn.microsoft.com/windows/desktop/Multimedia/creating-an-error-callback-function)

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)

[WM_CAP_SET_CALLBACK_ERROR](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-callback-error)

[capErrorCallback](https://learn.microsoft.com/windows/desktop/api/vfw/nc-vfw-caperrorcallbacka)