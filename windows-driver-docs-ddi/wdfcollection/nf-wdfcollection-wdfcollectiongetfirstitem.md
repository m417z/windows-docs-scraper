# WdfCollectionGetFirstItem function

## Description

[Applies to KMDF and UMDF]

The **WdfCollectionGetFirstItem** method returns a handle to the first object that is in an object collection.

## Parameters

### `Collection` [in]

A handle to a collection object.

## Return value

**WdfCollectionGetFirstItem** returns a handle to the object that is currently at the front of the specified collection's list of objects, or **NULL** if the list is empty.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about object collections, see [Framework Object Collections](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-collections).

#### Examples

The following code example removes each item from a collection and deletes each item's object.

```cpp
while ((subRequest = WdfCollectionGetFirstItem(hCollection)) != NULL) {
    WdfCollectionRemoveItem(
                            hCollection,
                            0
                            );
    WdfObjectDelete(subRequest);
}
```

## See also

[WdfCollectionGetItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectiongetitem)

[WdfCollectionGetLastItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectiongetlastitem)