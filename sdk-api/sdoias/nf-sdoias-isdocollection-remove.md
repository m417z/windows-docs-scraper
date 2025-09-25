# ISdoCollection::Remove

## Description

The
**Remove** method removes the specified item from the collection.

## Parameters

### `pItem` [in]

Pointer to an
[IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) interface that specifies the item to remove.

This parameter must not be **NULL**.

## Return value

If the method succeeds the return value is **S_OK**.

If the method fails, the return value is one of the following error codes.

## See also

[ISdoCollection](https://learn.microsoft.com/windows/desktop/api/sdoias/nn-sdoias-isdocollection)

[ISdoCollection::Add](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdocollection-add)

[ISdoCollection::RemoveAll](https://learn.microsoft.com/windows/desktop/api/sdoias/nf-sdoias-isdocollection-removeall)