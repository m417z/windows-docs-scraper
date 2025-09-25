# IEnumComponents::Next

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Next** method retrieves the next *n* elements in the collection.

## Parameters

### `celt` [in]

The number of elements to retrieve.

### `rgelt` [out]

Address of an array of [IComponent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponent) interface pointers that will receive the retrieved [Component](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/component-object) objects.

### `pceltFetched` [out]

Receives the number of elements actually retrieved.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IEnumComponents Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ienumcomponents)