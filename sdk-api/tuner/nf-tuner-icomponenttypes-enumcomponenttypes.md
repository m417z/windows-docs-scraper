# IComponentTypes::EnumComponentTypes

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **EnumComponentTypes** method returns an **IEnumComponentTypes** enumerator for all component types in the collection.

## Parameters

### `ppNewEnum` [out]

Receives a pointer to the [IEnumComponentTypes](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-ienumcomponenttypes) interface. The caller must release the interface.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IComponentTypes Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttypes)