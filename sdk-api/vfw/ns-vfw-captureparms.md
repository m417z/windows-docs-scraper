# CAPTUREPARMS structure

## Description

The **CAPTUREPARMS** structure contains parameters that control the streaming video capture process. This structure is used to get and set parameters that affect the capture rate, the number of buffers to use while capturing, and how capture is terminated.

## Members

### `dwRequestMicroSecPerFrame`

Requested frame rate, in microseconds. The default value is 66667, which corresponds to 15 frames per second.

### `fMakeUserHitOKToCapture`

User-initiated capture flag. If this member is **TRUE**, AVICap displays a dialog box prompting the user to initiate capture. The default value is **FALSE**.

### `wPercentDropForError`

Maximum allowable percentage of dropped frames during capture. Values range from 0 to 100. The default value is 10.

### `fYield`

Yield flag. If this member is **TRUE**, the capture window spawns a separate background thread to perform step and streaming capture. The default value is **FALSE**.

Applications that set this flag must handle potential reentry issues because the controls in the application are not disabled while capture is in progress.

### `dwIndexSize`

Maximum number of index entries in an AVI file. Values range from 1800 to 324,000. If set to 0, a default value of 34,952 (32K frames plus a proportional number of audio buffers) is used.

Each video frame or buffer of waveform-audio data uses one index entry. The value of this entry establishes a limit for the number of frames or audio buffers that can be captured.

### `wChunkGranularity`

Logical block size, in bytes, of an AVI file. The value 0 indicates the current sector size is used as the granularity.

### `fUsingDOSMemory`

Not used in Win32 applications.

### `wNumVideoRequested`

Maximum number of video buffers to allocate. The memory area to place the buffers is specified with **fUsingDOSMemory**. The actual number of buffers allocated might be lower if memory is unavailable.

### `fCaptureAudio`

Capture audio flag. If this member is **TRUE**, audio is captured during streaming capture. This is the default value if audio hardware is installed.

### `wNumAudioRequested`

Maximum number of audio buffers to allocate. The maximum number of buffers is 10.

### `vKeyAbort`

Virtual keycode used to terminate streaming capture. The default value is VK_ESCAPE. You must call the [RegisterHotKey](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerhotkey) function before specifying a keystroke that can abort a capture session.

You can combine keycodes that include CTRL and SHIFT keystrokes by using the logical OR operator with the keycodes for CTRL (0x8000) and SHIFT (0x4000).

### `fAbortLeftMouse`

Abort flag for left mouse button. If this member is **TRUE**, streaming capture stops if the left mouse button is pressed. The default value is **TRUE**.

### `fAbortRightMouse`

Abort flag for right mouse button. If this member is **TRUE**, streaming capture stops if the right mouse button is pressed. The default value is **TRUE**.

### `fLimitEnabled`

Time limit enabled flag. If this member is **TRUE**, streaming capture stops after the number of seconds in **wTimeLimit** has elapsed. The default value is **FALSE**.

### `wTimeLimit`

Time limit for capture, in seconds. This parameter is used only if **fLimitEnabled** is **TRUE**.

### `fMCIControl`

MCI device capture flag. If this member is **TRUE**, AVICap controls an MCI-compatible video source during streaming capture. MCI-compatible video sources include VCRs and laserdiscs.

### `fStepMCIDevice`

MCI device step capture flag. If this member is **TRUE**, step capture using an MCI device as a video source is enabled. If it is **FALSE**, real-time capture using an MCI device is enabled. (If **fMCIControl** is **FALSE**, this member is ignored.)

### `dwMCIStartTime`

Starting position, in milliseconds, of the MCI device for the capture sequence. (If **fMCIControl** is **FALSE**, this member is ignored.)

### `dwMCIStopTime`

Stopping position, in milliseconds, of the MCI device for the capture sequence. When this position in the content is reached, capture ends and the MCI device stops. (If **fMCIControl** is **FALSE**, this member is ignored.)

### `fStepCaptureAt2x`

Double-resolution step capture flag. If this member is **TRUE**, the capture hardware captures at twice the specified resolution. (The resolution for the height and width is doubled.)

Enable this option if the hardware does not support hardware-based decimation and you are capturing in the RGB format.

### `wStepCaptureAverageFrames`

Number of times a frame is sampled when creating a frame based on the average sample. A typical value for the number of averages is 5.

### `dwAudioBufferSize`

Audio buffer size. If the default value of zero is used, the size of each buffer will be the maximum of 0.5 seconds of audio or 10K bytes.

### `fDisableWriteCache`

Not used in Win32 applications.

### `AVStreamMaster`

Indicates whether the audio stream controls the clock when writing an AVI file. If this member is set to AVSTREAMMASTER_AUDIO, the audio stream is considered the master stream and the video stream duration is forced to match the audio duration. If this member is set to AVSTREAMMASTER_NONE, the durations of audio and video streams can differ.

## Remarks

The WM_CAP_GET_SEQUENCE_SETUP message or [capCaptureGetSetup](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capcapturegetsetup) macro is used to retrieve the current capture parameters. The WM_CAP_SET_SEQUENCE_SETUP message or [capCaptureSetSetup](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capcapturesetsetup) macro is used to set the capture parameters.

The [WM_CAP_GET_SEQUENCE_SETUP](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-get-sequence-setup) message or [capCaptureGetSetup](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capcapturegetsetup) macro is used to retrieve the current capture parameters. The [WM_CAP_SET_SEQUENCE_SETUP](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-sequence-setup) message or [capCaptureSetSetup](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capcapturesetsetup) macro is used to set the capture parameters.

## See also

[RegisterHotKey](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-registerhotkey)

Video Capture

[Video Capture Structures](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-structures)

[WM_CAP_GET_SEQUENCE_SETUP](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-get-sequence-setup)

[WM_CAP_SET_SEQUENCE_SETUP](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-sequence-setup)

[capCaptureGetSetup](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capcapturegetsetup)

[capCaptureSetSetup](https://learn.microsoft.com/windows/desktop/api/vfw/nf-vfw-capcapturesetsetup)