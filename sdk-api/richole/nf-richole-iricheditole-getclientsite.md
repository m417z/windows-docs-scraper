# IRichEditOle::GetClientSite

## Description

Retrieves an [IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite) interface to be used when creating a new object. All objects inserted into a rich edit control must use client site interfaces returned by this function. A client site may be used with exactly one object.

## Parameters

### `lplpolesite`

Type: **LPOLECLIENTSITE***

The address of the [IOleClientSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleclientsite) interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns **S_OK** on success, or a failure code otherwise. **E_OUTOFMEMORY** is returned if memory could not be allocated for the client site.

## See also

[IRichEditOle](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditole)