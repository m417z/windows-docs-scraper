# IBandSite::QueryBand

## Description

Gets information about a band in a band site.

## Parameters

### `dwBandID` [in]

Type: **DWORD**

The ID of the band object to query.

### `ppstb` [out, optional]

Type: **[IDeskBand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ideskband)****

Address of an [IDeskBand](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ideskband) interface pointer that, when this method returns successfully, points to the **IDeskBand** object that represents the band. This value can be **NULL**.

### `pdwState` [out, optional]

Type: **DWORD***

Pointer to a **DWORD** value that, when this method returns successfully, receives the state of the band object. This state is a combination of BSSF_VISIBLE, BSSF_NOTITLE, and BSSF_UNDELETEABLE. See [BANDSITEINFO](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ns-shobjidl_core-bandsiteinfo) for more information on those flags. This value can be **NULL** if the state information is not needed.

### `pszName` [out]

Type: **LPWSTR**

Pointer to a buffer of *cchName* Unicode characters that, when this method returns successfully, receives the name of the band object.

### `cchName` [in]

Type: **int**

The size of the *pszName* buffer, in characters.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.