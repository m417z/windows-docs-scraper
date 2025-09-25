# IFileIsInUse::GetAppName

## Description

Retrieves the name of the application that is using the file.

## Parameters

### `ppszName` [out]

Type: **LPWSTR***

The address of a pointer to a buffer that, when this method returns successfully, receives the application name.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This information can be passed to the user in a dialog box so that the user knows the source of the conflict and can act accordingly. For instance "File.txt is in use by Litware."