# IPropertyEnumType2::GetImageReference

## Description

Retrieves the image reference associated with a property enumeration.

## Parameters

### `ppszImageRes` [out]

Type: **LPWSTR***

A pointer to a buffer that, when this method returns successfully, receives a string of the form \<dll name>,-\<resid> that is suitable to be passed to [PathParseIconLocation](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-pathparseiconlocationa).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.