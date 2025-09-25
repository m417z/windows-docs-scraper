# CAPINFOCHUNK structure

## Description

The **CAPINFOCHUNK** structure contains parameters that can be used to define an information chunk within an AVI capture file. The [WM_CAP_FILE_SET_INFOCHUNK](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-file-set-infochunk) message or **capSetInfoChunk** macro is used to send a **CAPINFOCHUNK** structure to a capture window.

## Members

### `fccInfoID`

Four-character code that identifies the representation of the chunk data. If this value is **NULL** and **lpData** is **NULL**, all accumulated information chunks are deleted.

### `lpData`

Pointer to the data. If this value is **NULL**, all **fccInfoID** information chunks are deleted.

### `cbData`

Size, in bytes, of the data pointed to by **lpData**. If **lpData** specifies a null-terminated string, use the string length incremented by one to save the **NULL** with the string.

## See also

Video Capture

[Video Capture Structures](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-structures)

[WM_CAP_FILE_SET_INFOCHUNK](https://learn.microsoft.com/windows/desktop/Multimedia/wm-cap-file-set-infochunk)