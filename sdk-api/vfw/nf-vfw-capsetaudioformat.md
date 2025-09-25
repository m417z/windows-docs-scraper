# capSetAudioFormat macro

## Syntax

```cpp
BOOL capSetAudioFormat(
     hwnd,
     s,
     wSize
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capSetAudioFormat** macro sets the audio format to use when performing streaming or step capture. You can use this macro or explicitly call the [WM_CAP_SET_AUDIOFORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-audioformat) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `s`

Pointer to a [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) or [PCMWAVEFORMAT](https://learn.microsoft.com/previous-versions/dd743663(v=vs.85)) structure that defines the audio format.

### `wSize`

Size, in bytes, of the structure referenced by *psAudioFormat*.

## See also

[PCMWAVEFORMAT](https://learn.microsoft.com/previous-versions/dd743663(v=vs.85))

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)

[WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85))

[WM_CAP_SET_AUDIOFORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-audioformat)