# IBandSite::SetBandState

## Description

Set the state of a band in the band site.

## Parameters

### `dwBandID` [in]

Type: **DWORD**

The ID of the band to set. If this parameter is -1, then
set the state of all bands in the band site.

### `dwMask` [in]

Type: **DWORD**

The mask of the states to set.

### `dwState` [in]

Type: **DWORD**

The state values to be set. These are combinations of
BSSF_* flags. For more information, see [BANDSITEINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-bandsiteinfo).

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM-defined error code otherwise.

## See also

[BANDSITEINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-bandsiteinfo)

[IBandSite](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ibandsite)

[IDeskBand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ideskband)