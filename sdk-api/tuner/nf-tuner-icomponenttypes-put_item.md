# IComponentTypes::put_Item

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Item** method replaces the [ComponentType](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd693036(v=vs.85)) object at the specified index with a new **ComponentType** object.

## Parameters

### `Index` [in]

Index number of the item to be replaced.

### `ComponentType` [in]

Pointer to the [IComponentType](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttype) object that will be inserted into the collection.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IComponentTypes Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponenttypes)