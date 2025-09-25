# IBandSite::EnumBands

## Description

Enumerates the bands in a band site.

## Parameters

### `uBand` [in]

Type: **UINT**

Call the method with this parameter starting at 0 to
begin enumerating. If this parameter is -1, the
*pdwBandID* parameter is ignored and this method returns the count of the
bands in the band site.

### `pdwBandID` [out]

Type: **DWORD***

The address of a band ID variable that receives the band ID.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error code for errors.
If the first parameter is -1, the count of the bands in the band site
is returned.

## See also

[IBandSite](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ibandsite)

[IDeskBand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ideskband)