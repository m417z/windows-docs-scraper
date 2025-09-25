# IPersistStorage::InitNew

## Description

Initializes a new storage object.

## Parameters

### `pStg` [in]

An [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to the new storage object to be initialized. The container creates a nested storage object in its storage object (see [IStorage::CreateStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-createstorage)). Then, the container calls the [WriteClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstg) function to initialize the new storage object with the object class identifier (CLSID).

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **CO_E_ALREADYINITIALIZED** | The object has already been initialized by a previous call to either the [IPersistStorage::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-load) method or the [IPersistStorage::InitNew](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-initnew) method. |
| **E_OUTOFMEMORY** | The storage object was not initialized due to a lack of memory. |
| **E_FAIL** | The storage object was not initialized for some reason other than a lack of memory. |

## Remarks

A container application can call this method when it needs to initialize a new object, for example, with an InsertObject command.

An object that supports the [IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage) interface must have access to a valid storage object at all times while it is running. This includes the time just after the object has been created but before it has been made persistent. The object's container must provide the object with a valid [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to the storage during this time through the call to **IPersistStorage::InitNew**. Depending on the container's state, a temporary file might have to be created for this purpose.

If the object wants to retain the [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) instance, it must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) to increment its reference count.

After the call to **IPersistStorage::InitNew**, the object is in either the loaded or running state. For example, if the object class has an in-process server, the object will be in the running state. However, if the object uses the default handler, the container's call to **InitNew** only invokes the handler's implementation which does not run the object. Later if the container runs the object, the handler calls the **InitNew** method for the object.

### Notes to Callers

Rather than calling **IPersistStorage::InitNew** directly, you typically call the [OleCreate](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreate) helper function which does the following:

1. Calls the [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) function to create an instance of the object class.
2. Queries the new instance for the [IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage) interface.
3. Calls the **InitNew** method to initialize the object.

The container application should cache the [IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage) pointer to the object for use in later operations on the object.

### Notes to Implementers

An implementation of **IPersistStorage::InitNew** should initialize the object to its default state, taking the following steps:

1. Pre-open and cache the pointers to any streams or storages that the object will need to save itself to this storage.
2. Call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) and cache the storage pointer that is passed in.
3. Call the [WriteFmtUserTypeStg](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-writefmtusertypestg) function to write the native clipboard format and user type string for the object to the storage object.
4. Set the dirty flag for the object.

The first two steps are particularly important for ensuring that the object can save itself in low memory situations. Pre-opening and holding onto pointers to the stream and storage interfaces guarantee that a save operation to this storage will not fail due to insufficient memory.

Your implementation of this method should return the CO_E_ALREADYINITIALIZED error code if it receives a call to either the **IPersistStorage::InitNew** method or the [IPersistStorage::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-load) method after it is already initialized.

## See also

[IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage)