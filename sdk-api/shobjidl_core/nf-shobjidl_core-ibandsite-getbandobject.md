# IBandSite::GetBandObject

## Description

Gets a specified band object from a band site.

## Parameters

### `dwBandID` [in]

Type: **DWORD**

The ID of the band object to get.

### `riid` [in]

Type: **REFIID**

The IID of the object to obtain.

### `ppv` [out]

Type: **VOID****

The address of a pointer variable that receives a pointer
to the object requested.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error code otherwise.

## See also

[IBandSite](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ibandsite)

[IDeskBand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ideskband)