# capFileSaveDIB macro

## Syntax

```cpp
BOOL capFileSaveDIB(
     hwnd,
     szName
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.If an error occurs and an error callback function is set using the **capSetCallbackOnError** macro, the error callback function is called.

## Description

The **capFileSaveDIB** macro copies the current frame to a DIB file. You can use this macro or explicitly call the [WM_CAP_FILE_SAVEDIB](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-file-savedib) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `szName`

Pointer to the null-terminated string that contains the name of the destination DIB file.

## Remarks

If the capture driver supplies frames in a compressed format, this call attempts to decompress the frame before writing the file.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)