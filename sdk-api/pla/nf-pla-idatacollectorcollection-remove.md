# IDataCollectorCollection::Remove

## Description

Removes a data collector from the collection.

## Parameters

### `collector` [in]

The zero-based index of the data collector to remove from the collection. The variant type can be VT_I4, VT_UI4, or VT_DISPATCH.

## Return value

Returns S_OK if successful.

## Remarks

If the variant type is VT_DISPATCH, pass the **IDispatch** interface of the [IDataCollector](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollector) to be removed.

Note that by removing the collector from the collection, you are also removing the collector from the data collector set.

## See also

[IDataCollectorCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-idatacollectorcollection)

[IDataCollectorCollection::Add](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorcollection-add)

[IDataCollectorCollection::Clear](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-idatacollectorcollection-clear)