# OleGetIconOfClass function

## Description

Returns a handle to a metafile containing an icon and a string label for the specified CLSID.

## Parameters

### `rclsid` [in]

The CLSID for which the icon and string are to be requested.

### `lpszLabel` [in, optional]

A pointer to the label for the icon.

### `fUseTypeAsLabel` [in]

Indicates whether to use the user type string in the CLSID as the icon label.

## Return value

If the function succeeds, the return value is a handle to a metafile that contains and icon and label for the specified CLSID. Otherwise, the function returns **NULL**.

## See also

[OleGetIconOfFile](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olegeticonoffile)

[OleMetafilePictFromIconAndLabel](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olemetafilepictfromiconandlabel)