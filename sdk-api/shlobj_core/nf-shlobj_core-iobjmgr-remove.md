# IObjMgr::Remove

## Description

Removes an object from the collection of managed objects.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

The address of the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the object to be removed from the list.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a COM error code otherwise.

## See also

[IObjMgr](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iobjmgr)

[IObjMgr::Append](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iobjmgr-append)