# ITraceDataProviderCollection::Remove

## Description

Removes a trace provider from the collection.

## Parameters

### `vProvider` [in]

The zero-based index of the trace provider to remove from the collection. The variant type can be VT_I4, VT_UI4, or VT_DISPATCH.

## Return value

Returns S_OK if successful.

## Remarks

If the variant type is VT_DISPATCH, pass the **IDispatch** interface of the [ITraceDataProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedataprovider) interface to be removed.

Note that by removing the trace provider from the collection, you are also removing the provider from the trace data collector.

## See also

[ITraceDataProviderCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedataprovidercollection)

[ITraceDataProviderCollection::Add](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedataprovidercollection-add)

[ITraceDataProviderCollection::Clear](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nf-pla-itracedataprovidercollection-clear)