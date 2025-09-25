# capSetVideoFormat macro

## Syntax

```cpp
BOOL capSetVideoFormat(
     hwnd,
     s,
     wSize
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capSetVideoFormat** macro sets the format of captured video data. You can use this macro or explicitly call the [WM_CAP_SET_VIDEOFORMAT](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-videoformat) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `s`

Pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

### `wSize`

The size, in bytes, of the structure referenced by *psVideoFormat*.

## Remarks

Because video formats are device-specific, applications should check the return value from this function to determine if the format is accepted by the driver.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)