# ENHMFENUMPROC callback function

## Description

The **EnhMetaFileProc** function is an application-defined callback function used with the [EnumEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumenhmetafile) function. The **ENHMFENUMPROC** type defines a pointer to this callback function. **EnhMetaFileProc** is a placeholder for the application-defined function name.

## Parameters

### `hdc`

### `lpht`

### `lpmr`

### `nHandles`

### `data`

### `hDC` [in]

Handle to the device context passed to [EnumEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumenhmetafile).

#### - lpData [in]

Pointer to optional data.

#### - lpEMFR [in]

Pointer to one of the records in the metafile. This record should not be modified. (If modification is necessary, it should be performed on a copy of the record.)

#### - lpHTable [in]

Pointer to a [HANDLETABLE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-handletable) structure representing the table of handles associated with the graphics objects (pens, brushes, and so on) in the metafile. The first entry contains the enhanced-metafile handle.

#### - nObj [in]

Specifies the number of objects with associated handles in the handle table.

## Return value

This function must return a nonzero value to continue enumeration; to stop enumeration, it must return zero.

## Remarks

An application must register the callback function by passing its address to the [EnumEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumenhmetafile) function.

## See also

[ENHMETARECORD](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-enhmetarecord)

[EnumEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumenhmetafile)

[HANDLETABLE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-handletable)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)