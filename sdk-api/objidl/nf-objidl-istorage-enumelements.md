# IStorage::EnumElements

## Description

The **EnumElements** method retrieves a pointer to an enumerator object that can be used to enumerate the storage and stream objects contained within this storage object.

## Parameters

### `reserved1` [in]

Reserved for future use; must be zero.

### `reserved2` [in]

Reserved for future use; must be **NULL**.

### `reserved3` [in]

Reserved for future use; must be zero.

### `ppenum` [out]

Pointer to
[IEnumSTATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatstg)* pointer variable that receives the interface pointer to the new enumerator object.

## Return value

This method can return one of these values.

| Return code | Description |
|----------------|---------------|
|S_OK | The enumerator object was successfully returned.|
|E_PENDING | Asynchronous Storage only: Part or all of the element's data is currently unavailable.|
|STG_E_INSUFFICIENTMEMORY | The enumerator object could not be created due to lack of memory.|
|STG_E_INVALIDPARAMETER | One of the parameters was not valid.|
|STG_E_REVERTED | The storage object has been invalidated by a revert operation above it in the transaction tree.|

## Remarks

The enumerator object returned by this method implements the
[IEnumSTATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatstg) interface, one of the standard enumerator interfaces that contain the **Next**, **Reset**,
**Clone**, and **Skip** methods.
**IEnumSTATSTG** enumerates the data stored in an array of
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structures.

The storage object must be open in read mode to allow the enumeration of its elements.

The enumerator object is permitted to enumerate the elements in any order.
The enumerator object is also permitted to treat the enumeration as a snapshot
or to have the enumeration reflect the current state of the storage object.

## See also

[IEnumSTATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatstg)

[IStorage - Compound File Implementation](https://learn.microsoft.com/windows/desktop/Stg/istorage-compound-file-implementation)

[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg)