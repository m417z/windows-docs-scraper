# capFileAlloc macro

## Syntax

```cpp
BOOL capFileAlloc(
     hwnd,
     dwSize
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.If an error occurs and an error callback function is set using the **capSetCallbackOnError** macro, the error callback function is called.

## Description

The **capFileAlloc** macro creates (preallocates) a capture file of a specified size. You can use this macro or explicitly send the [WM_CAP_FILE_ALLOCATE](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-file-allocate) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `dwSize`

Size, in bytes, to create the capture file.

## Remarks

You can improve streaming capture performance significantly by preallocating a capture file large enough to store an entire video clip and by defragmenting the capture file before capturing the clip.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)