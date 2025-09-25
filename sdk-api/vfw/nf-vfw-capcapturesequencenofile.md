# capCaptureSequenceNoFile macro

## Syntax

```cpp
BOOL capCaptureSequenceNoFile(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capCaptureSequenceNoFile** macro initiates streaming video capture without writing data to a file. You can use this macro or explicitly send the [WM_CAP_SEQUENCE_NOFILE](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-sequence-nofile) message.

## Parameters

### `hwnd`

Handle to a capture window.

## Remarks

This message is useful in conjunction with video stream or waveform-audio stream callback functions that let your application use the video and audio data directly.

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