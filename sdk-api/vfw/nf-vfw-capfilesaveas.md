# capFileSaveAs macro

## Syntax

```cpp
BOOL capFileSaveAs(
     hwnd,
     szName
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.If an error occurs and an error callback function is set using the **capSetCallbackOnError** macro, the error callback function is called.

## Description

The **capFileSaveAs** macro copies the contents of the capture file to another file. You can use this macro or explicitly call the [WM_CAP_FILE_SAVEAS](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-file-saveas) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `szName`

Pointer to the null-terminated string that contains the name of the destination file used to copy the file.

## Remarks

This message does not change the name or contents of the current capture file.

If the copy operation is unsuccessful due to a disk full error, the destination file is automatically deleted.

Typically, a capture file is preallocated for the largest capture segment anticipated and only a portion of it might be used to capture data. This message copies only the portion of the file containing the capture data.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)