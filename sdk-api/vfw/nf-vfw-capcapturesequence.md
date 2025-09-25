# capCaptureSequence macro

## Syntax

```cpp
BOOL capCaptureSequence(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.If an error occurs and an error callback function is set using the **capSetCallbackOnError** macro, the error callback function is called.

## Description

The **capCaptureSequence** macro initiates streaming video and audio capture to a file. You can use this macro or explicitly send the [WM_CAP_SEQUENCE](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-sequence) message.

## Parameters

### `hwnd`

Handle to a capture window.

## Remarks

If you want to alter the parameters controlling streaming capture, use the [capCaptureSetSetup](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capcapturesetsetup) macro prior to starting the capture.

By default, the capture window does not allow other applications to continue running during capture. To override this, either set the **fYield** member of the [CAPTUREPARMS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-captureparms) structure to **TRUE**, or install a yield callback function.

During streaming capture, the capture window can optionally issue notifications to your application of specific types of conditions. To install callback procedures for these notifications, use the following macros:

* [capSetCallbackOnError](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonerror)
* [capSetCallbackOnStatus](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonstatus)
* [capSetCallbackOnVideoStream](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonvideostream)
* [capSetCallbackOnWaveStream](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonwavestream)
* [capSetCallbackOnYield](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capsetcallbackonyield)

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)