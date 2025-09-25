# capCreateCaptureWindowA function

## Description

The **capCreateCaptureWindow** function creates a capture window.

## Parameters

### `lpszWindowName`

Null-terminated string containing the name used for the capture window.

### `dwStyle`

Window styles used for the capture window. Window styles are described with the [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function.

### `x`

The x-coordinate of the upper left corner of the capture window.

### `y`

The y-coordinate of the upper left corner of the capture window.

### `nWidth`

Width of the capture window.

### `nHeight`

Height of the capture window.

### `hwndParent`

Handle to the parent window.

### `nID`

Window identifier.

## Return value

Returns a handle of the capture window if successful or **NULL** otherwise.

## See also

[Creating a Capture Window](https://learn.microsoft.com/windows/desktop/Multimedia/creating-a-capture-window)

[Video Capture](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture)

[Video Capture Functions](https://learn.microsoft.com/windows/desktop/Multimedia/video-capture-functions)

## Remarks

> [!NOTE]
> The vfw.h header defines capCreateCaptureWindow as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).