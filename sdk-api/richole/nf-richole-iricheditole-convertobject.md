# IRichEditOle::ConvertObject

## Description

Converts an object to a new type. This call reloads the object but does not force an update; the caller must do this.

## Parameters

### `iob`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index of the object to convert. If this parameter is REO_IOB_SELECTION, the selected object is to be converted.

### `rclsidNew`

Type: **REFCLSID**

Class identifier of the class to which the object is converted.

### `lpstrUserTypeNew`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

User-visible type name of the class to which the object is converted.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK on success, or a failure code otherwise. E_INVALIDARG is returned if the index is invalid.

## See also

[IRichEditOle](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditole)