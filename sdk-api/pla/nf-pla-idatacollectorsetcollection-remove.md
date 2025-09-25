# IDataCollectorSetCollection::Remove

## Description

Removes a data collector set from the collection.

## Parameters

### `set` [in]

The zero-based index of the data collector set to remove from the collection. The variant type can be VT_I4, VT_UI4, or VT_DISPATCH.

## Return value

Returns S_OK if successful.

## Remarks

If the variant type is VT_DISPATCH, pass the **IDispatch** interface of the [IDataCollectorSet](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorset) to be removed.

Note that by removing the set from the collection, you are also deleting the set from the hard disk.

## See also

[IDataCollectorSetCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorsetcollection)

[IDataCollectorSetCollection::Add](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorsetcollection-add)

[IDataCollectorSetCollection::Clear](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorsetcollection-clear)