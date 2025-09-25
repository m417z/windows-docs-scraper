# capFileSetInfoChunk macro

## Syntax

```cpp
BOOL capFileSetInfoChunk(
     hwnd,
     lpInfoChunk
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful or **FALSE** otherwise.If an error occurs and an error callback function is set using the **capSetCallbackOnError** macro, the error callback function is called.

## Description

The **capFileSetInfoChunk** macro sets and clears information chunks. Information chunks can be inserted in an AVI file during capture to embed text strings or custom data. You can use this macro or explicitly call the [WM_CAP_FILE_SET_INFOCHUNK](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-file-set-infochunk) message.

## Parameters

### `hwnd`

Handle to a capture window.

### `lpInfoChunk`

Pointer to a CAPINFOCHUNK structure defining the information chunk to be created or deleted.

## Remarks

Multiple registered information chunks can be added to an AVI file. After an information chunk is set, it continues to be added to subsequent capture files until either the entry is cleared or all information chunk entries are cleared. To clear a single entry, specify the information chunk in the **fccInfoID** member and **NULL** in the **lpData** member of the [CAPINFOCHUNK](https://learn.microsoft.com/windows/desktop/api/vfw/ns-vfw-capinfochunk) structure. To clear all entries, specify **NULL** in **fccInfoID**.

## See also

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Macros](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-macros)