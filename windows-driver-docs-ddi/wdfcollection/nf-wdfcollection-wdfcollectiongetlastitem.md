# WdfCollectionGetLastItem function

## Description

[Applies to KMDF and UMDF]

The **WdfCollectionGetLastItem** method returns a handle to the last object that is in an object collection.

## Parameters

### `Collection` [in]

A handle to a collection object.

## Return value

**WdfCollectionGetLastItem** returns a handle to the object that is currently at the end of the specified collection's list of objects, or **NULL** if the list is empty.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

For more information about object collections, see [Framework Object Collections](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-collections).

#### Examples

The following code example obtains a handle to the last object that is in an object collection.

```cpp
WDFOBJECT lastItem;

lastItem = WdfCollectionGetLastItem(hCollection);
```

## See also

[WdfCollectionGetFirstItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectiongetfirstitem)

[WdfCollectionGetItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectiongetitem)