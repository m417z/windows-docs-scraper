# IComponents::get_Item

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Item** method enables the caller to access a component by index.

## Parameters

### `Index` [in]

Variable of type **VARIANT** specifying the zero-based index in the collection.

### `ppComponent` [out]

Address of an [IComponent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponent) interface pointer that will receive the **Component** object at the specified index.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## See also

[IComponents Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponents)