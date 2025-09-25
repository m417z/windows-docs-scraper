# IMoniker::BindToStorage

## Description

Binds to the storage for the specified object. Unlike the [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) method, this method does not activate the object identified by the moniker.

## Parameters

### `pbc` [in]

A pointer to the [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on the bind context object, which is used in this binding operation. The bind context caches objects bound during the binding process, contains parameters that apply to all operations using the bind context, and provides the means by which the moniker implementation should retrieve information about its environment.

### `pmkToLeft` [in]

If the moniker is part of a composite moniker, pointer to the moniker to the left of this moniker. This parameter is primarily used by moniker implementers to enable cooperation between the various components of a composite moniker. Moniker clients should use **NULL**.

### `riid` [in]

A reference to the identifier of the storage interface requested, whose pointer will be returned in *ppvObj*. Storage interfaces commonly requested include [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage), [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream), and [ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes).

### `ppvObj` [out]

The address of pointer variable that receives the interface pointer requested in *riid*. Upon successful return, **ppvObj* contains the requested interface pointer to the storage of the object the moniker identifies. When successful, the implementation must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the storage. It is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs, **ppvObj* should be **NULL**.

## Return value

This method can return the standard return values E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The binding operation was successful. |
| **MK_E_NOSTORAGE** | The object identified by this moniker does not have its own storage. |
| **MK_E_EXCEEDEDDEADLINE** | The binding operation could not be completed within the time limit specified by the bind context's [BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts) structure. |
| **MK_E_CONNECTMANUALLY** | The operation was unable to connect to the storage, possibly because a network device could not be connected to. For more information, see [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject). |
| **MK_E_INTERMEDIATEINTERFACENOTSUPPORTED** | An intermediate object was found but it did not support an interface required to complete the binding operation. For example, an item moniker returns this value if its container does not support the [IOleItemContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleitemcontainer) interface. |
| **STG_E_ACCESSDENIED** | Unable to access the storage object. |

This method can also return the errors associated with the [IOleItemContainer::GetObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleitemcontainer-getobject) method.

## Remarks

There is an important difference between the [BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) and **BindToStorage** methods. If, for example, you have a moniker that identifies a spreadsheet object, calling **BindToObject** provides access to the spreadsheet object itself, while calling **BindToStorage** provides access to the storage object in which the spreadsheet resides.

### Notes to Callers

Although none of the COM moniker classes call this method in their binding operations, it might be appropriate to call it in the implementation of a new moniker class. You could call this method in an implementation of [BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) that requires information from the object identified by the *pmkToLeft* parameter and can get it from the persistent storage of the object without activation. For example, if your monikers are used to identify objects that can be activated without activating their containers, you may find this method useful.

A client that can read the storage of the object its moniker identifies could also call this method.

### Notes to Implementers

Your implementation should locate the persistent storage for the object identified by the current moniker and return the desired interface pointer. Some types of monikers represent pseudo-objects, which are objects that do not have their own persistent storage. Such objects comprise some portion of the internal state of its container, for example, a range of cells in a spreadsheet. If your moniker class identifies this type of object, your implementation of **BindToStorage** should return the error MK_E_NOSTORAGE.

If the bind context's [BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts) structure specifies the BINDFLAGS_JUSTTESTEXISTENCE flag, your implementation has the option of returning **NULL** in *ppvObj* (although you can also ignore the flag and perform the complete binding operation).

### Implementation-specific Notes

| Implementation | Notes |
| --- | --- |
| Anti-moniker | This method returns E_NOTIMPL. |
| Class moniker | This method forwards to the class moniker's [BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject). |
| File moniker | This method opens the file specified by the path represented by the moniker and returns an [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) pointer to that file. The method supports binding to the **IStorage** interface only; if [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) or [ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes) is requested in *riid*, the method returns E_UNSPEC, and if other interfaces are requested, this method returns E_NOINTERFACE. Unless *pmkToLeft* is a class moniker, *pmkToLeft* should be **NULL**, as in the implementation of [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject). |
| Generic composite moniker | This method recursively calls **BindToStorage** on the rightmost component of the composite, passing the rest of the composite as the *pmkToLeft* parameter for that call. |
| Item moniker | If *pmkToLeft* is **NULL**, this method returns E_INVALIDARG. Otherwise, the method calls [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) on the *pmkToLeft* parameter, requesting an [IOleItemContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleitemcontainer) interface pointer. The method then calls [IOleItemContainer::GetObjectStorage](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleitemcontainer-getobjectstorage) for the requested interface. |
| OBJREF moniker | This method obtains a marshaled pointer to the requested interface on the storage that contains the running object. Because the OBJREF moniker represents a running object, no activation takes place. If the represented object is no longer running, **BindToStorage** fails with E_UNEXPECTED. |
| Pointer moniker | This method queries the wrapped pointer for the requested interface. |
| URL moniker | The system implementation of URL monikers supports **BindToStorage** for stream objects on all URLs and for storage objects in the case where the designated resource is a compound file.<br><br>Because the URL moniker supports asynchronous binding, the actual return value of its **BindToStorage** may vary depending on the object parameters established in the bind context. However, the semantics of the bind operation are identical regardless of synchronous or asynchronous usage, as follows:<br><br>* The URL moniker pulls further information for the bind operation from the bind context. For example, the moniker can obtain pointers to the [IBindStatusCallback](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775060(v=vs.85)) and [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) interfaces that are registered in the bind context. Further information can include additional bind options specified on the bind context through [IBindCtx::SetBindOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-setbindoptions), such as the *dwTickCountDeadline* parameter or the *grfFlags* value of BIND_MAYBOTHERUSER. The moniker then queries the client by calling [IBindStatusCallback::GetBindInfo](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775058(v=vs.85)) and initiates the bind operation with the transport and passes the resulting IBinding to the client by calling [IBindStatusCallback::OnStartBinding](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775065(v=vs.85)).<br>* If the caller requested an asynchronous [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) or [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) by specifying the BINDF_ASYNCSTORAGE flag in the [BINDINFO](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms774966(v=vs.85)) structure retrieved from the [IBindStatusCallback::GetBindInfo](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775058(v=vs.85)), method the URL moniker returns the object as soon as possible. Calls to these **IStorage** or **IStream** objects that reference data not yet available return E_PENDING.<br>* If the caller does not specify asynchronous [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) or [IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage) as described above, the URL moniker will still return an object through the [IBindStatusCallback::OnDataAvailable](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775061(v=vs.85)) method as soon as possible. However, calls to these objects that reference data not yet available will block until the data becomes available. For some applications, this will require the least modification of their existing I/O code yet may still result in improved performance depending on their access patterns. |

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)