# CAPSTATUS structure

## Description

The **CAPSTATUS** structure defines the current state of the capture window.

## Members

### `uiImageWidth`

Image width, in pixels.

### `uiImageHeight`

Image height, in pixels

### `fLiveWindow`

Live window flag. The value of this member is **TRUE** if the window is displaying video using the preview method.

### `fOverlayWindow`

Overlay window flag. The value of this member is **TRUE** if the window is displaying video using hardware overlay.

### `fScale`

Input scaling flag. The value of this member is **TRUE** if the window is scaling the input video to the client area when displaying video using preview. This parameter has no effect when displaying video using overlay.

### `ptScroll`

The x- and y-offset of the pixel displayed in the upper left corner of the client area of the window.

### `fUsingDefaultPalette`

Default palette flag. The value of this member is **TRUE** if the capture driver is using its default palette.

### `fAudioHardware`

Audio hardware flag. The value of this member is **TRUE** if the system has waveform-audio hardware installed.

### `fCapFileExists`

Capture file flag. The value of this member is **TRUE** if a valid capture file has been generated.

### `dwCurrentVideoFrame`

Number of frames processed during the current (or most recent) streaming capture. This count includes dropped frames.

### `dwCurrentVideoFramesDropped`

Number of frames dropped during the current (or most recent) streaming capture. Dropped frames occur when the capture rate exceeds the rate at which frames can be saved to file. In this case, the capture driver has no buffers available for storing data. Dropping frames does not affect synchronization because the previous frame is displayed in place of the dropped frame.

### `dwCurrentWaveSamples`

Number of waveform-audio samples processed during the current (or most recent) streaming capture.

### `dwCurrentTimeElapsedMS`

Time, in milliseconds, since the start of the current (or most recent) streaming capture.

### `hPalCurrent`

Handle to current palette.

### `fCapturingNow`

Capturing flag. The value of this member is **TRUE** when capturing is in progress.

### `dwReturn`

Error return values. Use this member if your application does not support an error callback function.

### `wNumVideoAllocated`

Number of video buffers allocated. This value might be less than the number specified in the **wNumVideoRequested** member of the [CAPTUREPARMS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-captureparms) structure.

### `wNumAudioAllocated`

Number of audio buffers allocated. This value might be less than the number specified in the **wNumAudioRequested** member of the [CAPTUREPARMS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-captureparms) structure.

## Remarks

Because the state of a capture window changes in response to various messages, an application should update the information in this structure whenever it needs to enable menu items, determine the actual state of the capture window, or call the video format dialog box. If the application yields during streaming capture, this structure returns the progress of the capture in the **dwCurrentVideoFrame**, **dwCurrentVideoFramesDropped**, **dwCurrentWaveSamples**, and **dwCurrentTimeElapsedMS** members. Use the [WM_CAP_GET_STATUS](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-get-status) message or [capGetStatus](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capgetstatus) macro to update the contents of this structure.

## See also

[CAPTUREPARMS](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-captureparms)

Video Capture

[Video Capture Structures](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-structures)

[WM_CAP_GET_STATUS](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-get-status)