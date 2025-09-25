# IComponentTypes::Add

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Add** method adds a new [ComponentType](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd693036(v=vs.85)) object to the collection.

## Parameters

### `ComponentType` [in]

Pointer to the [IComponentType](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttype) object that will be added to the collection.

### `NewIndex` [out]

The index number of the component type after it has been added to the collection.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IComponentTypes Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttypes)