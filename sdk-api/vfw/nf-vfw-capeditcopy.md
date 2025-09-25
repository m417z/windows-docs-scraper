# capEditCopy macro

## Syntax

```cpp
BOOL capEditCopy(
     hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capEditCopy** macro copies the contents of the video frame buffer and associated palette to the clipboard. You can use this macro or explicitly send the [WM_CAP_EDIT_COPY](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-edit-copy) message.

## Parameters

### `hwnd`

Handle to a capture window.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)