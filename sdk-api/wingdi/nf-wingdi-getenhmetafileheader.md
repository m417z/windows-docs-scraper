# GetEnhMetaFileHeader function

## Description

The **GetEnhMetaFileHeader** function retrieves the record containing the header for the specified enhanced-format metafile.

## Parameters

### `hemf` [in]

A handle to the enhanced metafile for which the header is to be retrieved.

### `nSize` [in]

The size, in bytes, of the buffer to receive the data. Only this many bytes will be copied.

### `lpEnhMetaHeader` [out]

A pointer to an [ENHMETAHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enhmetaheader) structure that receives the header record. If this parameter is **NULL**, the function returns the size of the header record.

## Return value

If the function succeeds and the structure pointer is **NULL**, the return value is the size of the record that contains the header; if the structure pointer is a valid pointer, the return value is the number of bytes copied. Otherwise, it is zero.

## Remarks

An enhanced-metafile header contains such information as the metafile's size, in bytes; the dimensions of the picture stored in the metafile; the number of records stored in the metafile; the offset to the optional text description; the size of the optional palette, and the resolution of the device on which the picture was created.

The record that contains the enhanced-metafile header is always the first record in the metafile.

## See also

[ENHMETAHEADER](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enhmetaheader)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PlayEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playenhmetafile)