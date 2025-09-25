# capSetScrollPos macro

## Syntax

```cpp
BOOL capSetScrollPos(
     hwnd,
     lpP
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.

## Description

The **capSetScrollPos** macro defines the portion of the video frame to display in the capture window. This message sets the upper left corner of the client area of the capture window to the coordinates of a specified pixel within the video frame. You can use this macro or explicitly call the [WM_CAP_SET_SCROLL](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-set-scroll) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `lpP`

Address to contain the desired scroll position.

## Remarks

The scroll position affects the image in both preview and overlay modes.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)