# PlayMetaFileRecord function

## Description

The **PlayMetaFileRecord** function plays a Windows-format metafile record by executing the graphics device interface (GDI) function contained within that record.

**Note** This function is provided only for compatibility with Windows-format metafiles. Enhanced-format metafiles provide superior functionality and are recommended for new applications. The corresponding function for an enhanced-format metafile is [PlayEnhMetaFileRecord](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playenhmetafilerecord).

## Parameters

### `hdc` [in]

A handle to a device context.

### `lpHandleTable` [in]

A pointer to a [HANDLETABLE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-handletable) structure representing the table of handles to GDI objects used when playing the metafile.

### `lpMR` [in]

A pointer to the Windows-format metafile record.

### `noObjs` [in]

The number of handles in the handle table.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

To convert a Windows-format metafile into an enhanced-format metafile, use the [SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits) function.

An application typically uses **PlayMetaFileRecord** in conjunction with the [EnumMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enummetafile) function to process and play a Windows-format metafile one record at a time.

The *lpHandletable* and *nHandles* parameters must be identical to those passed to the [EnumMetaFileProc](https://learn.microsoft.com/previous-versions/dd162630(v=vs.85)) callback procedure by [EnumMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enummetafile).

If the **PlayMetaFileRecord** function does not recognize a record, it ignores the record and returns **TRUE**.

## See also

[EnumMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enummetafile)

[HANDLETABLE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-handletable)

[METARECORD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-metarecord)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PlayMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playmetafile)

[SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits)