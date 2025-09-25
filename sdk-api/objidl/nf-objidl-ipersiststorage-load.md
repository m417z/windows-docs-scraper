# IPersistStorage::Load

## Description

Loads an object from its existing storage.

## Parameters

### `pStg` [in]

An [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to the existing storage from which the object is to be loaded.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CO_E_ALREADYINITIALIZED** | The object has already been initialized by a previous call to the [IPersistStorage::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-load) method or the [IPersistStorage::InitNew](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-initnew) method. |
| **E_OUTOFMEMORY** | The object was not loaded due to lack of memory. |
| **E_FAIL** | The object was not loaded due to some reason other than a lack of memory. |

## Remarks

This method initializes an object from an existing storage. The object is placed in the loaded state if this method is called by the container application. If called by the default handler, this method places the object in the running state.

Either the default handler or the object itself can hold onto the [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer while the object is loaded or running.

### Notes to Callers

Rather than calling **IPersistStorage::Load** directly, you typically call the [OleLoad](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleload) helper function which does the following:

1. Create an uninitialized instance of the object class.
2. Query the new instance for the [IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage) interface.
3. Call **Load** to initialize the object from the existing storage.

You also call this method indirectly when you call the [OleCreateFromData](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatefromdata) function or the [OleCreateFromFile](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreatefromfile) function to insert an object into a compound file (as in a drag-and-drop or clipboard paste operation).

The container should cache the [IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage) pointer for use in later operations on the object.

### Notes to Implementers

Your implementation should perform the following steps to load an object:

1. Open the object's streams in the storage object, and read the necessary data into the object's internal data structures.
2. Clear the object's dirty flag.
3. Call the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method and cache the passed in storage pointer.
4. Keep open and cache the pointers to any streams or storages that the object will need to save itself to this storage.
5. Perform any other default initialization required for the object.

Steps 3 and 4 are particularly important for ensuring that the object can save itself in low memory situations. Holding onto pointers to the storage and stream interfaces guarantees that a save operation to this storage will not fail due to insufficient memory.

Your implementation of this method should return the CO_E_ALREADYINITIALIZED error code if it receives a call to either the [IPersistStorage::InitNew](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-initnew) method or the **IPersistStorage::Load** method after it is already initialized.

## See also

[IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage)

[OleLoad](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleload)