# MCIWndRecord macro

## Syntax

```cpp
LONG MCIWndRecord(
     hwnd
);
```

## Return value

Type: **LONG**

Returns zero if successful or an error otherwise.

## Description

The **MCIWndRecord** macro begins recording content using the MCI device. The recording process begins at the current position in the content and will overwrite existing data for the duration of the recording.

## Parameters

### `hwnd`

Handle of the MCIWnd window.

## Remarks

The function that an MCI device performs during recording depends on the characteristics of the device. An MCI device that uses files, such as a waveform-audio device, sends data to the file during recording. An MCI device that does not use files, such as a video-cassette recorder, receives and externally records data on another medium.