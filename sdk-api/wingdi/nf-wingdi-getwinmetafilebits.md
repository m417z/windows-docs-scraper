# GetWinMetaFileBits function

## Description

The **GetWinMetaFileBits** function converts the enhanced-format records from a metafile into Windows-format records and stores the converted records in the specified buffer.

## Parameters

### `hemf` [in]

A handle to the enhanced metafile.

### `cbData16` [in]

The size, in bytes, of the buffer into which the converted records are to be copied.

### `pData16` [out]

A pointer to the buffer that receives the converted records. If *lpbBuffer* is **NULL**, **GetWinMetaFileBits** returns the number of bytes required to store the converted metafile records.

### `iMapMode` [in]

The mapping mode to use in the converted metafile.

### `hdcRef` [in]

A handle to the reference device context.

## Return value

If the function succeeds and the buffer pointer is **NULL**, the return value is the number of bytes required to store the converted records; if the function succeeds and the buffer pointer is a valid pointer, the return value is the size of the metafile data in bytes.

If the function fails, the return value is zero.

## Remarks

This function converts an enhanced metafile into a Windows-format metafile so that its picture can be displayed in an application that recognizes the older format.

The system uses the reference device context to determine the resolution of the converted metafile.

The **GetWinMetaFileBits** function does not invalidate the enhanced metafile handle. An application should call the [DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile) function to release the handle when it is no longer needed.

To create a scalable Windows-format metafile, specify MM_ANISOTROPIC as the *fnMapMode* parameter.

The upper-left corner of the metafile picture is always mapped to the origin of the reference device.

## See also

[DeleteEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteenhmetafile)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[SetMapMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setmapmode)

[SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits)