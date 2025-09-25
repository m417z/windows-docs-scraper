# WdfCollectionRemoveItem function

## Description

[Applies to KMDF and UMDF]

The **WdfCollectionRemoveItem** method removes a specified object from an object collection, based on a specified index value.

## Parameters

### `Collection` [in]

A handle to a collection object.

### `Index` [in]

A zero-based index that identifies the object to remove.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

Index values represent the order in which objects are added to a collection. An index value of zero represents the first object that was added to the collection, an index value of one represents the second object, and so on.

When **WdfCollectionRemoveItem** removes an object from a collection, it decrements the object's reference count.

For more information about object collections, see [Framework Object Collections](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-collections)

#### Examples

For a code example that uses **WdfCollectionRemoveItem**, see [WdfCollectionGetFirstItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectiongetfirstitem).

## See also

[WdfCollectionRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectionremove)