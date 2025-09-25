# OleGetIconOfFile function

## Description

Returns a handle to a metafile containing an icon and string label for the specified file name.

## Parameters

### `lpszPath` [in]

A pointer to a file for which the icon and string are to be requested.

### `fUseFileAsLabel` [in]

Indicates whether to use the file name as the icon label.

## Return value

If the function succeeds, the return value is a handle to a metafile that contains and icon and label for the specified file. If there is no CLSID in the registration database for the file, then the function returns the string "Document". If *lpszPath* is **NULL**, the function returns **NULL**.

## See also

[OleGetIconOfClass](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegeticonofclass)

[OleMetafilePictFromIconAndLabel](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olemetafilepictfromiconandlabel)