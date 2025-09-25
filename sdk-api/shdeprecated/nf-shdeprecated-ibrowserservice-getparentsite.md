# IBrowserService::GetParentSite

## Description

Deprecated. Retrieves the browser parent's in-place client site.

## Parameters

### `ppipsite` [out]

Type: **[IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite)****

The address of a pointer to an [IOleInPlaceSite](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleinplacesite) that indicates the browser parent's in-place client site.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A client site is the display site for embedded objects and provides position and conceptual information about the object.