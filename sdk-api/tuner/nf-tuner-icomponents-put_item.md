# IComponents::put_Item

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Item** method inserts a component into the collection, replacing the item that is identified by the specified index.

## Parameters

### `Index` [in]

Specifies the index to assign to the component. This parameter is a value of type **VARIANT**.

### `ppComponent` [in]

Pointer to the [IComponent](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponent) interface of the component object. The method creates a clone of the component and inserts the clone into the collection.

## Return value

Returns S_OK if successful. If the method fails, error information can be retrieved using the standard COM **IErrorInfo** interface.

## Remarks

This method allows the client to replace an existing item in the collection.

If the collection contains *n* items, valid indexes are in the range 0 to *n*-1. To determine the number of items in the collection, call [get_Count](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-icomponents-get_count).

## See also

[IComponents Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nn-tuner-icomponents)

[get_Item](https://learn.microsoft.com/previous-versions/windows/desktop/api/tuner/nf-tuner-icomponents-get_item)