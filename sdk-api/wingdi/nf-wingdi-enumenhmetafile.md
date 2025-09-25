# EnumEnhMetaFile function

## Description

The **EnumEnhMetaFile** function enumerates the records within an enhanced-format metafile by retrieving each record and passing it to the specified callback function. The application-supplied callback function processes each record as required. The enumeration continues until the last record is processed or when the callback function returns zero.

## Parameters

### `hdc` [in]

A handle to a device context. This handle is passed to the callback function.

### `hmf` [in]

A handle to an enhanced metafile.

### `proc` [in]

A pointer to the application-supplied callback function. For more information, see the [EnhMetaFileProc](https://learn.microsoft.com/previous-versions/dd162606(v=vs.85)) function.

### `param` [in]

A pointer to optional callback-function data.

### `lpRect` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the coordinates, in logical units, of the picture's upper-left and lower-right corners.

## Return value

If the callback function successfully enumerates all the records in the enhanced metafile, the return value is nonzero.

If the callback function does not successfully enumerate all the records in the enhanced metafile, the return value is zero.

## Remarks

Points along the edge of the rectangle pointed to by the *lpRect* parameter are included in the picture. If the *hdc* parameter is **NULL**, the system ignores *lpRect*.

If the callback function calls the [PlayEnhMetaFileRecord](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playenhmetafilerecord) function, *hdc* must identify a valid device context. The system uses the device context's transformation and mapping mode to transform the picture displayed by the **PlayEnhMetaFileRecord** function.

You can use the **EnumEnhMetaFile** function to embed one enhanced-metafile within another.

## See also

[EnhMetaFileProc](https://learn.microsoft.com/previous-versions/dd162606(v=vs.85))

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PlayEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playenhmetafile)

[PlayEnhMetaFileRecord](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playenhmetafilerecord)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)