# ITraceDataProvider::Resolve

## Description

Merges the details about a provider with this instance.

## Parameters

### `pFrom` [in]

The interface of the provider to merge with this instance.

## Return value

Returns S_OK if successful.

## Remarks

You can specify an interface of a provider or a collection that contains the provider. If you specify a collection, the method finds the matching provider.

## See also

[ITraceDataProvider](https://learn.microsoft.com/previous-versions/windows/desktop/api/pla/nn-pla-itracedataprovider)