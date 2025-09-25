## Description

Creates an uninitialized object.

## Parameters

### `pUnkOuter` [in]

If the object is being created as part of an aggregate, specify a pointer to the controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface of the aggregate. Otherwise, this parameter must be **NULL**.

### `riid` [in]

A reference to the identifier of the interface to be used to communicate with the newly created object. If *pUnkOuter* is **NULL**, this parameter is generally the IID of the initializing interface; if *pUnkOuter* is non-**NULL**, *riid* must be IID_IUnknown.

### `ppvObject` [out]

The address of pointer variable that receives the interface pointer requested in *riid*. Upon successful return, **ppvObject* contains the requested interface pointer. If the object does not support the interface specified in *riid*, the implementation must set **ppvObject* to **NULL**.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The specified object was created. |
| **CLASS_E_NOAGGREGATION** | The *pUnkOuter* parameter was non-**NULL** and the object does not support aggregation. |
| **E_NOINTERFACE** | The object that *ppvObject* points to does not support the interface identified by *riid*. |

## Remarks

A COM server's implementation of **CreateInstance** must return a reference to an object contained in an apartment that belongs to the server's DCOM resolver. It must not return a reference to an object that is contained in a remote apartment.

The [IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory) interface is always on a class object. The **CreateInstance** method creates an uninitialized object of the class identified with the specified CLSID. When an object is created in this way, the CLSID must be registered in the system registry with the [CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject) function.

The *pUnkOuter* parameter indicates whether the object is being created as part of an aggregate. Object definitions are not required to support aggregation - they must be specifically designed and implemented to support it.

The *riid* parameter specifies the IID (interface identifier) of the interface through which you will communicate with the new object. If *pUnkOuter* is non-**NULL** (indicating aggregation), the value of the riid parameter must be IID_IUnknown. If the object is not part of an aggregate, riid often specifies the interface though which the object will be initialized.

For OLE embeddings, the initialization interface is [IPersistStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststorage), but in other situations, other interfaces are used. To initialize the object, there must be a subsequent call to an appropriate method in the initializing interface. Common initialization functions include [IPersistStorage::InitNew](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-initnew) (for new, blank embeddable components), [IPersistStorage::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststorage-load) (for reloaded embeddable components), [IPersistStream::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-load), (for objects stored in a stream object) or [IPersistFile::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-load) (for objects stored in a file).

In general, if an application supports only one class of objects, and the class object is registered for single use, only one object can be created. The application must not create other objects, and a request to do so should return an error from **IClassFactory::CreateInstance**. The same is true for applications that support multiple classes, each with a class object registered for single use; a call to **CreateInstance** for one class followed by a call to **CreateInstance** for any of the classes that should return an error.

To avoid returning an error, applications that support multiple classes with single-use class objects can revoke the registered class object of the first class by calling [CoRevokeClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-corevokeclassobject) when a request for instantiating a second is received. For example, suppose there are two classes, A and B. When **CreateInstance** is called for class A, revoke the class object for B. When B is created, revoke the class object for A. This solution complicates shutdown because one of the class objects might have already been revoked (and cannot be revoked twice).

## See also

[CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance)

[CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject)

[CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject)

[CoRevokeClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-corevokeclassobject)

[IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory)