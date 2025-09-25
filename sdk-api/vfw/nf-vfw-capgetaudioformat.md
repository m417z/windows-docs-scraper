# capGetAudioFormat macro

## Syntax

```cpp
DWORD capGetAudioFormat(
     hwnd,
     s,
     wSize
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the size, in bytes, of the audio format.

## Description

The **capGetAudioFormat** macro obtains the audio format. You can use this macro or explicitly call the [WM_CAP_GET_AUDIOFORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-get-audioformat) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `s`

Pointer to a [WAVEFORMATEX](https://learn.microsoft.com/previous-versions/dd757713(v=vs.85)) structure, or **NULL**. If the value is **NULL**, the size, in bytes, required to hold the **WAVEFORMATEX** structure is returned.

### `wSize`

Size, in bytes, of the structure referenced by *s*.

## Remarks

Because compressed audio formats vary in size requirements applications must first retrieve the size, then allocate memory, and finally request the audio format data.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)