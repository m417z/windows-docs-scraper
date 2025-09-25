# IComponentTypes::Clone

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Clone** method creates a new copy of the collection.

## Parameters

### `NewList` [out]

Address of an **IComponentTypes** interface pointer that will be set to the new [ComponentTypes](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/componenttypes-object) object.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IComponentTypes Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttypes)