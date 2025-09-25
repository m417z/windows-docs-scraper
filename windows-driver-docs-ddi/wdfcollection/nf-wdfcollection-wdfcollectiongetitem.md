# WdfCollectionGetItem function

## Description

[Applies to KMDF and UMDF]

The **WdfCollectionGetItem** method returns a handle to the object that is contained in a specified object collection and associated with a specified index value.

## Parameters

### `Collection` [in]

A handle to a collection object.

### `Index` [in]

A zero-based index value that identifies an object in the collection.

## Return value

**WdfCollectionGetItem** returns a framework object handle, or **NULL** if the *Index* value is invalid.

A system bug check occurs if the driver supplies an invalid object handle.

## Remarks

Index values represent the order in which objects are added to a collection. An index value of zero represents the first object in the collection, an index value of one represents the second object, and so on, like a linked list. When the driver removes item *i* from a collection, item *i*+1 becomes item *i*.

For more information about object collections, see [Framework Object Collections](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-collections).

#### Examples

For a code example that uses **WdfCollectionGetItem**, see [WdfCollectionGetCount](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectiongetcount).

```cpp

```

## See also

[WdfCollectionGetFirstItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectiongetfirstitem)

[WdfCollectionGetLastItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcollection/nf-wdfcollection-wdfcollectiongetlastitem)