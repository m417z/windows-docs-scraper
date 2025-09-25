# MFENUMPROC callback function

## Description

The **EnumMetaFileProc** function is an application-defined callback function that processes Windows-format metafile records. This function is called by the [EnumMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enummetafile) function. The **MFENUMPROC** type defines a pointer to this callback function. **EnumMetaFileProc** is a placeholder for the application-defined function name.

**Note** This function is provided only for compatibility with Windows-format metafiles. Enhanced-format metafiles provide superior functionality and are recommended for new applications. The corresponding function for an enhanced-format metafile is [EnhMetaFileProc](https://learn.microsoft.com/previous-versions/dd162606(v=vs.85)).

## Parameters

### `hdc`

### `lpht`

### `lpMR`

### `nObj` [in]

Specifies the number of objects with associated handles in the handle table.

### `param`

### `hDC` [in]

Handle to the device context passed to [EnumMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enummetafile).

#### - lpClientData [in]

Pointer to optional data.

#### - lpHTable [in]

Pointer to a table of handles associated with the graphics objects (pens, brushes, and so on) in the metafile.

#### - lpMFR [in]

Pointer to one of the records in the metafile. This record should not be modified. (If modification is necessary, it should be performed on a copy of the record.)

## Return value

This function must return a nonzero value to continue enumeration; to stop enumeration, it must return zero.

## Remarks

An application must register the callback function by passing its address to the [EnumMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enummetafile) function.

**EnumMetaFileProc** is a placeholder for the application-supplied function name.

## See also

[EnhMetaFileProc](https://learn.microsoft.com/previous-versions/dd162606(v=vs.85))

[EnumEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumenhmetafile)

[EnumMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enummetafile)

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)