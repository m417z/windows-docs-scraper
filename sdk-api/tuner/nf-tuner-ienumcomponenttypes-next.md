# IEnumComponentTypes::Next

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Next** method retrieves the next *n* elements in the collection.

## Parameters

### `celt` [in]

The number of elements to retrieve.

### `rgelt` [out]

Address of an array of [IComponentType](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttype) interface pointers that will receive the returned [ComponentType](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd693036(v=vs.85)) objects.

### `pceltFetched` [out]

Receives the number of elements actually retrieved.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IEnumComponentTypes Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ienumcomponenttypes)