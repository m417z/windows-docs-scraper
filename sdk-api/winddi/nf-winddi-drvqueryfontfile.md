# DrvQueryFontFile function

## Description

The **DrvQueryFontFile** function provides font file information.

## Parameters

### `iFile`

Pointer to a driver-defined value that identifies the driver font file. This pointer is returned by a prior call to [DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile).

### `ulMode`

Specifies the type of information to be written. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| QFF_DESCRIPTION | The function provides a string that an NT-based operating system will use to describe the font file. A null-terminated Unicode string is written to the buffer pointed to by *pulBuffer*. |
| QFF_NUMFACES | The function returns the number of typefaces in the font file; the *cjBuf* and *pulBuf* parameters are ignored. Typefaces are identified by an index ranging from one through the number of typefaces. |

### `cjBuf`

Specifies the size, in bytes, of the return buffer.

### `pulBuf`

Pointer to the return buffer.

## Return value

If *ulMode* is QFF_NUMFACES, then the return value is the number of faces in the font file. If *pulBuf* is **NULL**, it is the number of bytes of data that would be written to *pulBuf*; otherwise, it is the number of bytes written to *pulBuf*. If an error occurs, the return value is FD_ERROR.

## Remarks

**DrvQueryFontFile** is required for font drivers.

## See also

[DrvLoadFontFile](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvloadfontfile)