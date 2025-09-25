# WdfCollectionRemove function

## Description

[Applies to KMDF and UMDF]

The **WdfCollectionRemove** method removes an object from a specified object collection.

## Parameters

### `Collection` [in]

A handle to a collection object.

### `Item` [in]

A handle to the framework object that will be removed from the collection.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

When **WdfCollectionRemove** removes an object from a collection, it decrements the object's reference count.

For more information about object collections, see [Framework Object Collections](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-collections).

#### Examples

The following code example removes a specified object from a specified object collection.

```cpp
WdfCollectionRemove(
                    hCollection,
                    hObject
                    );
```

## See also

[WdfCollectionRemoveItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectionremoveitem)