# IMoniker::BindToObject

## Description

Binds to the specified object. The binding process involves finding the object, putting it into the running state if necessary, and providing the caller with a pointer to a specified interface on the identified object.

## Parameters

### `pbc` [in]

A pointer to the [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on the bind context object, which is used in this binding operation. The bind context caches objects bound during the binding process, contains parameters that apply to all operations using the bind context, and provides the means by which the moniker implementation should retrieve information about its environment.

### `pmkToLeft` [in]

If the moniker is part of a composite moniker, pointer to the moniker to the left of this moniker. This parameter is primarily used by moniker implementers to enable cooperation between the various components of a composite moniker. Moniker clients should use **NULL**.

### `riidResult` [in]

The IID of the interface the client wishes to use to communicate with the object that the moniker identifies.

### `ppvResult` [out]

The address of pointer variable that receives the interface pointer requested in *riid*. Upon successful return, **ppvResult* contains the requested interface pointer to the object the moniker identifies. When successful, the implementation must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the moniker. It is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs, **ppvResult* should be **NULL**.

## Return value

This method can return the standard return values E_OUTOFMEMORY and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The binding operation was successful. |
| **MK_E_NOOBJECT** | The object identified by this moniker, or some object identified by the composite moniker of which this moniker is a part, could not be found. |
| **MK_E_EXCEEDEDDEADLINE** | The binding operation could not be completed within the time limit specified by the bind context's [BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts) structure. |
| **MK_E_CONNECTMANUALLY** | The binding operation requires assistance from the end user. The most common reason for returning this value is that a password is needed or that a floppy needs to be mounted. When this value is returned, retrieve the moniker that caused the error with a call to [IBindCtx::GetObjectParam](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-getobjectparam) with the key "ConnectManually". You can then call [IMoniker::GetDisplayName](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-getdisplayname) to get the display name, display a dialog box that communicates the desired information, such as instructions to mount a floppy or a request for a password, and then retry the binding operation. |
| **MK_E_INTERMEDIATEINTERFACENOTSUPPORTED** | An intermediate object was found but it did not support an interface required to complete the binding operation. For example, an item moniker returns this value if its container does not support the [IOleItemContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleitemcontainer) interface. |
| **STG_E_ACCESSDENIED** | Unable to access the storage object. |

This method can also return the errors associated with the [IOleItemContainer::GetObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleitemcontainer-getobject) method.

## Remarks

**BindToObject** implements the primary function of a moniker, which is to locate the object identified by the moniker and return a pointer to one of its interfaces.

### Notes to Callers

If you are using a moniker as a persistent connection between two objects, you activate the connection by calling **BindToObject**.

You typically call **BindToObject** during the following process:

1. Create a bind context object with a call to the [CreateBindCtx](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createbindctx) function.
2. Call **BindToObject** using the moniker, retrieving a pointer to a desired interface on the identified object.
3. Release the bind context.
4. Through the acquired interface pointer, perform the desired operations on the object.
5. When finished with the object, release the object's interface pointer.

The following code fragment illustrates these steps.

``` syntax
HRESULT hr;       // An error code
IMoniker * pMnk;  // A previously acquired interface moniker

// Obtain an IBindCtx interface.
IBindCtx * pbc;
hr = CreateBindCtx(NULL, &pbc);
if (FAILED(hr)) exit(0);  // Handle errors here.

// Obtain an implementation of pCellRange.
ICellRange * pCellRange;
hr = pMnk->BindToObject(pbc, NULL, IID_ICellRange, &pCellRange);
if (FAILED(hr)) exit(0);  // Handle errors here.

// Use pCellRange here.

// Release interfaces after use.
pbc->Release();
pCellRange->Release();

```

You can also use the [BindMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-bindmoniker) function when you intend only one binding operation and don't need to retain the bind context object. This helper function encapsulates the creation of the bind context, calling **BindToObject** and releasing the bind context.

COM containers that support links to objects use monikers to locate and get access to the linked object but typically do not call **BindToObject** directly. Instead, when a user activates a link in a container, the link container usually calls [IOleObject::DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb), using the link handler's implementation, which calls **BindToObject** on the moniker stored in the linked object (if it cannot handle the verb).

### Notes to Implementers

What your implementation does depends on whether you expect your moniker to have a prefix; that is, whether you expect the *pmkToLeft* parameter to be **NULL** or not. For example, an item moniker, which identifies an object within a container, expects that *pmkToLeft* identifies the container. An item moniker consequently uses *pmkToLeft* to request services from that container. If you expect your moniker to have a prefix, you should use the *pmkToLeft* parameter (for example, calling **BindToObject** on it) to request services from the object it identifies.

If you expect your moniker to have no prefix, your **BindToObject** implementation should first check the running object table (ROT) to see whether the object is already running. To acquire a pointer to the ROT, your implementation should call [IBindCtx::GetRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-getrunningobjecttable) on the *pbc* parameter. You can then call the [IRunningObjectTable::GetObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-getobject) method to see if the current moniker has been registered in the ROT. If so, you can immediately call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to get a pointer to the interface requested by the caller.

When your **BindToObject** implementation binds to some object, it should use the *pbc* parameter to call [IBindCtx::RegisterObjectBound](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectbound) to store a reference to the bound object in the bind context. This ensures that the bound object remains running until the bind context is released, which can avoid the expense of having a subsequent binding operation load it again later.

If the bind context's [BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts) structure specifies the BINDFLAGS_JUSTTESTEXISTENCE flag, your implementation has the option of returning **NULL** in *ppvResult* (although you can also ignore the flag and perform the complete binding operation).

### Implementation-specific Notes

| Implementation | Notes |
| --- | --- |
| Anti-moniker | This method is not implemented. It returns E_NOTIMPL. |
| Class moniker | If *pmkLeft* is **NULL**, calls [CoGetClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetclassobject), using the CLSID the class moniker was initialized with (in [CreateClassMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createclassmoniker) or through [MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname)) and the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) of the current *pbc* ([IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)).<br><br>If *pmkLeft* is non-**NULL**, calls pmkLeft->BindToObject for [IClassActivator](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iclassactivator) and calls [IClassActivator::GetClassObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iclassactivator-getclassobject) with the CLSID it was initialized with and the [CLSCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-clsctx) and locale parameters of the current *pbc* ([IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)). |
| File moniker | When *pmkToLeft* is **NULL**, the method looks for the moniker in the ROT and, if found, queries the retrieved object for the requested interface pointer. If the moniker is not found in the ROT, the method loads the object from the file system and retrieves the requested interface pointer.<br><br>If *pmkLeft* is not **NULL**, instead of determining the class to instantiate and initialize with the contents of the file referred to by the file moniker using [GetClassFile](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-getclassfile) (or other means), call pmkLeft->BindToObject for [IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory) and [IClassActivator](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iclassactivator), retrieve this pointer in *pcf*. If this fails with E_NOINTERFACE, return MK_E_INTERMEDIATEINTERFACENOTSUPPORTED.<br><br>If the [IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory) pointer is successfully retrieved, call pcf->CreateInstance(IID_IPersistFile, (void**)&ppf) to get a fresh instance of the class to be initialized and initialize it by using [IPersistFile](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersistfile) or other appropriate means per the existing initialization paths of file moniker. |
| Generic composite moniker | If *pmkToLeft* is **NULL**, this method looks for the moniker in the ROT and, if found, queries the retrieved object for the requested interface pointer. If *pmkToLeft* is not **NULL**, the method recursively calls **BindToObject** on the rightmost component of the composite, passing the rest of the composite as the *pmkToLeft* parameter for that call. |
| Item moniker | If *pmkToLeft* is **NULL**, this method returns E_INVALIDARG. Otherwise, the method calls **BindToObject** on the *pmkToLeft* parameter, requesting an [IOleItemContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleitemcontainer) interface pointer. The method then calls [IOleItemContainer::GetObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleitemcontainer-getobject), passing the string contained within the moniker, and returns the requested interface pointer. |
| OBJREF moniker | The *pmkToLeft* parameter must be **NULL**. Because the OBJREF moniker represents a running object, no activation takes place. If the represented object is no longer running, **BindToObject** fails with E_UNEXPECTED. |
| Pointer moniker | This method queries the wrapped pointer for the requested interface. |
| URL moniker | Because the URL Moniker supports asynchronous binding, the actual return value of its **BindToObject** may vary depending on the object parameters established in the bind context. For more information, see below. |

The semantics of the bind operation for a URL moniker are identical regardless of synchronous or asynchronous usage, and are as follows:

1. The URL moniker pulls further information for the bind operation from the bind context. For example, the moniker can obtain pointers to the [IBindStatusCallback](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775060(v=vs.85)) and [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) interfaces that are registered in the bind context. Further information can include additional bind options specified on the bind context through [IBindCtx::SetBindOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-setbindoptions), such as the *dwTickCountDeadline* parameter or the *grfFlags* value of BIND_MAYBOTHERUSER.
2. Next the moniker checks the ROT of the bind context to determine whether the referenced object is already running. The moniker can obtain this information with the following calls:

   ``` syntax
   IBindCtx::GetRunningObjectTable(&prot)
   prot->IsRunning(this)

   ```
3. If the object is already running, the moniker retrieves the running object with the following call:

   ``` syntax
   prot->GetObject(this, &punk)

   ```
4. Then the moniker calls [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for the requested interface.
5. Otherwise, the moniker queries the client by calling [IBindStatusCallback::GetBindInfo](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775058(v=vs.85)) to obtain additional bind information. The moniker then initiates the bind operation and passes the resulting IBinding interface back to the client by calling [IBindStatusCallback::OnStartBinding](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775065(v=vs.85)).
6. If in step 1 it was determined that this was an asynchronous bind, **BindToObject** returns MK_S_ASYNCHRONOUS at this point with **NULL** in *ppv*. The caller will receive the actual object pointer during the [IBindStatusCallback::OnObjectAvailable](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775063(v=vs.85)) method at some later point. The following steps then occur asynchronously to the caller, typically on another thread of execution.
7. The class of the resource designated by the URL Moniker is determined in one of the following ways:

   * The URL moniker examines the media type of the data. If the media type is application/x-oleobject, the first 16-bytes of the actual data (Content-Body) contain the CLSID of the resource and subsequent data is to be interpreted by the class itself. For all other media types, URL Moniker looks in the system registry for the HKEY_CLASSES_ROOT\MIME\Database\Content-Type\<media-type>\CLSID key. Note that application/x-oleobject will be used until application/oleobject is approved.
   * The URL moniker matches portions of arriving data to patterns registered in the system registry under HKEY_CLASSES_ROOT\FileTypes.
   * Finally, if all else fails, the URL Moniker correlates the trailing extension of the resource, if any, to a CLSID using the HKEY_CLASSES_ROOT\.??? keys in the system registry, as is done by GetClassFile and the shell.
8. Having determined the class, the URL moniker creates an instance using [CoCreateInstance](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cocreateinstance) of CLSCTX_SERVER asking for the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface.
9. The URL moniker next calls the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method of the newly created object for the [IPersistMoniker](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775042(v=vs.85)) interface. If **QueryInterface** is successful, the URL moniker calls [IPersistMoniker::Load](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775044(v=vs.85)) passing itself (this) as the moniker parameter. The object typically calls [BindToStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtostorage) asking for the storage interface that they are interested in.
10. Otherwise, the URL moniker calls [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for [IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream) and, if successful, calls [IPersistStream::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersiststream-load), passing the object an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) pointer for a stream object that is being filled asynchronously by the transport.

    If the class being called is not marked with the category CATID_AsyncAware, calls to [ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read) or [ISequentialStream::Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write) that reference data not yet available block until the data becomes available. These calls block in the traditional COM sense. A message loop is entered which allows certain messages to be processed, and the [IMessageFilter](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imessagefilter) of the thread is called appropriately.

    If the class is marked with the category CATID_AsyncAware, calls to [ISequentialStream::Read](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-read) or [ISequentialStream::Write](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-isequentialstream-write) that reference data not yet available return E_PENDING.
11. Otherwise, the URL moniker calls [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) for [IPersistFile](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersistfile) and, if successful, completes the download into a temporary file. On completion, the URL moniker calls [IPersistFile::Load](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipersistfile-load). The created file is cached along with other Internet downloaded data. The client must be sure not to delete this file.
12. When the object returns from one of the various **Load** calls described in the previous steps, the URL moniker calls the [IBindStatusCallback::OnObjectAvailable](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/ms775063(v=vs.85)) method to return the interface pointer that the client originally requested when the client called **BindToObject**.

## See also

[BindMoniker](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-bindmoniker)

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)