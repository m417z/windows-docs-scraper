# PlayEnhMetaFileRecord function

## Description

The **PlayEnhMetaFileRecord** function plays an enhanced-metafile record by executing the graphics device interface (GDI) functions identified by the record.

## Parameters

### `hdc` [in]

A handle to the device context passed to the [EnumEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumenhmetafile) function.

### `pht` [in]

A pointer to a table of handles to GDI objects used when playing the metafile. The first entry in this table contains the enhanced-metafile handle.

### `pmr` [in]

A pointer to the enhanced-metafile record to be played.

### `cht` [in]

The number of handles in the handle table.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

This is an enhanced-metafile function.

An application typically uses **PlayEnhMetaFileRecord** in conjunction with the [EnumEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumenhmetafile) function to process and play an enhanced-format metafile one record at a time.

The *hdc*, *lpHandletable*, and *nHandles* parameters must be exactly those passed to the [EnhMetaFileProc](https://learn.microsoft.com/previous-versions/dd162606(v=vs.85)) callback procedure by the [EnumEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumenhmetafile) function.

If **PlayEnhMetaFileRecord** does not recognize a record, it ignores the record and returns **TRUE**.

## See also

[EnumEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumenhmetafile)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PlayEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playenhmetafile)