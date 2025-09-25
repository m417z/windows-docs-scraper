# EnumMetaFile function

## Description

The **EnumMetaFile** function enumerates the records within a Windows-format metafile by retrieving each record and passing it to the specified callback function. The application-supplied callback function processes each record as required. The enumeration continues until the last record is processed or when the callback function returns zero.

**Note** This function is provided only for compatibility with Windows-format metafiles. Enhanced-format metafiles provide superior functionality and are recommended for new applications. The corresponding function for an enhanced-format metafile is [EnumEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumenhmetafile).

## Parameters

### `hdc` [in]

Handle to a device context. This handle is passed to the callback function.

### `hmf` [in]

Handle to a Windows-format metafile.

### `proc` [in]

Pointer to an application-supplied callback function. For more information, see [EnumMetaFileProc](https://learn.microsoft.com/previous-versions/dd162630(v=vs.85)).

### `param` [in]

Pointer to optional data.

## Return value

If the callback function successfully enumerates all the records in the Windows-format metafile, the return value is nonzero.

If the callback function does not successfully enumerate all the records in the Windows-format metafile, the return value is zero.

## Remarks

To convert a Windows-format metafile into an enhanced-format metafile, use the [SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits) function.

You can use the **EnumMetaFile** function to embed one Windows-format metafile within another.

## See also

[EnumEnhMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-enumenhmetafile)

[EnumMetaFileProc](https://learn.microsoft.com/previous-versions/dd162630(v=vs.85))

[Metafile Functions](https://learn.microsoft.com/windows/desktop/gdi/metafile-functions)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PlayMetaFile](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playmetafile)

[PlayMetaFileRecord](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-playmetafilerecord)

[SetWinMetaFileBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwinmetafilebits)