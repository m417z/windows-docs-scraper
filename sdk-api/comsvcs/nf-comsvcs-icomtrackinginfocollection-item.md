# IComTrackingInfoCollection::Item

## Description

Retrieves the specified interface from a specified member of a tracking information collection.

## Parameters

### `ulIndex` [in]

The index of the object in the collection.

### `riid` [in]

The identifier of the interface to be requested.

### `ppv` [out]

A pointer to the requested interface.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IComTrackingInfoCollection](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomtrackinginfocollection)