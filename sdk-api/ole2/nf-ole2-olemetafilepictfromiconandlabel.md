# OleMetafilePictFromIconAndLabel function

## Description

Creates a metafile in which the specified icon and label are drawn.

## Parameters

### `hIcon` [in]

Handle to the icon that is to be drawn into the metafile. This parameter can be **NULL**. If *hIcon* is **NULL**, this function returns **NULL** without creating a metafile.

### `lpszLabel` [in]

The icon label. This parameter can be **NULL**. If *lpszLabel* is **NULL**, the resulting metafile will not include a label.

### `lpszSourceFile` [in]

The path and file name of the icon file. This string can be obtained through the user interface or from the registration database. This parameter can be **NULL**.

### `iIconIndex` [in]

The location of the icon within the file named by *lpszSourceFile*, expressed as an offset in bytes from the beginning of file.

## Return value

A global handle to a [METAFILEPICT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-metafilepict) structure containing the icon and label. The metafile uses the MM_ANISOTROPIC mapping mode.

If an error occurs, the returned handle is **NULL**. In this case, the caller can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to obtain further information.

## Remarks

This function is called by [OleGetIconOfFile](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegeticonoffile) and [OleGetIconOfClass](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegeticonofclass).

If *lpszSourceFile* is not **NULL** and *iIconIndex* is not 0, the name of the source file passed in *lpszSourceFile* and the index passed by *iIconIndex* are added to the created metafile as a comment record.

## See also

[OleGetIconOfClass](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegeticonofclass)

[OleGetIconOfFile](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegeticonoffile)