# IGetFrame::SetFormat

## Description

The **SetFormat** method sets the decompressed image format of the frames being extracted and optionally provides a buffer for the decompression operation.

## Parameters

### `lpbi`

Pointer to a [BITMAPINFOHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfoheader) structure defining the decompressed image format. You can also specify **NULL** or the value `((LPBITMAPINFOHEADER) 1)` for this parameter. **NULL** causes the decompressor to choose a format that is appropriate for editing (normally a 24-bit image depth format). The value `((LPBITMAPINFOHEADER) 1)` causes the decompressor to choose a format appropriate for the current display mode.

### `lpBits`

Pointer to a buffer to contain the decompressed image data. Specify **NULL** to have this method allocate a buffer.

### `x`

The x-coordinate of the destination rectangle within the DIB specified by *lpbi*. This parameter is used when *lpBits* is not **NULL**.

### `y`

The y-coordinate of the destination rectangle within the DIB specified by *lpbi*. This parameter is used when *lpBits* is not **NULL**.

### `dx`

Width of the destination rectangle. This parameter is used when *lpBits* is not **NULL**.

### `dy`

Height of the destination rectangle. This parameter is used when *lpBits* is not **NULL**.

#### - ps

Pointer to the interface to a stream.

## Return value

Returns **NOERROR** if successful, **E_OUTOFMEMORY** if the decompressed image is larger than the buffer size, or **E_FAIL** otherwise.

## Remarks

The *x*, *y*, *dx*, and *dy* parameters identify the portion of the bitmap specified by *lpbi* and *lpBits* that receives the decompressed image.

For handlers written in C++, **SetFormat** has the following syntax:

```cpp

HRESULT SetFormat(LPBITMAPINFOHEADER lpbi, LPVOID lpBits, int x,
    int y, int dx, int dy);

```

## See also

[Custom File and Stream Handler Interfaces](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handler-interfaces)

[Custom File and Stream Handlers](https://learn.microsoft.com/windows/desktop/Multimedia/custom-file-and-stream-handlers)