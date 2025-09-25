# IRunningObjectTable::Register

## Description

Registers an object and its identifying moniker in the running object table (ROT).

## Parameters

### `grfFlags` [in]

Specifies whether the ROT's reference to punkObject is weak or strong and controls access to the object through its entry in the ROT. For details, see the Remarks section.

| Value | Meaning |
| --- | --- |
| **ROTFLAGS_REGISTRATIONKEEPSALIVE** | When set, indicates a strong registration for the object. |
| **ROTFLAGS_ALLOWANYCLIENT** | When set, any client can connect to the running object through its entry in the ROT. When not set, only clients in the window station that registered the object can connect to it. |

### `punkObject` [in]

A pointer to the object that is being registered as running.

### `pmkObjectName` [in]

A pointer to the moniker that identifies *punkObject*.

### `pdwRegister` [out]

An identifier for this ROT entry that can be used in subsequent calls to [IRunningObjectTable::Revoke](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-revoke) or [IRunningObjectTable::NoteChangeTime](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-notechangetime). The caller cannot specify **NULL** for this parameter. If an error occurs, **pdwRegister* is set to zero.

## Return value

This method can return the standard return values E_INVALIDARG and E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **MK_S_MONIKERALREADYREGISTERED** | The moniker/object pair was successfully registered, but that another object (possibly the same object) has already been registered with the same moniker. |

## Remarks

This method registers a pointer to an object under a moniker that identifies the object. The moniker is used as the key when the table is searched with [IRunningObjectTable::GetObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-getobject).

When an object is registered, the ROT always calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the object. For a weak registration (ROTFLAGS_REGISTRATIONKEEPSALIVE not set), the ROT will release the object whenever the last strong reference to the object is released. For a strong registration (ROTFLAGS_REGISTRATIONKEEPSALIVE set), the ROT prevents the object from being destroyed until the object's registration is explicitly revoked.

A server registered as either LocalService or RunAs can set the ROTFLAGS_ALLOWANYCLIENT flag in its call to **Register** to allow any client to connect to it. A server setting this bit must have its executable name in the AppID section of the registry that refers to the AppID for the executable. An "activate as activator" server (not registered as LocalService or RunAs) must not set this flag in its call to **Register**. For details on installing services, see [Installing as a Service Application](https://learn.microsoft.com/windows/desktop/com/installing-as-a-service-application).

Registering a second object with the same moniker, or re-registering the same object with the same moniker, creates a second entry in the ROT. In this case, **Register** returns MK_S_MONIKERALREADYREGISTERED. Each call to **Register** must be matched by a call to [IRunningObjectTable::Revoke](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-revoke) because even duplicate entries have different *pdwRegister* identifiers. A problem with duplicate registrations is that there is no way to determine which object will be returned if the moniker is specified in a subsequent call to [IRunningObjectTable::IsRunning](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-isrunning).

### Notes to Callers

If you are a moniker provider (that is, you hand out monikers identifying your objects to make them accessible to others), you must call the **Register** method to register your objects when they begin running. You must also call this method if you rename your objects while they are loaded.

The most common type of moniker provider is a compound-document link source. This includes server applications that support linking to their documents (or portions of a document) and container applications that support linking to embeddings within their documents. Server applications that do not support linking can also use the ROT to cooperate with container applications that support linking to embeddings.

If you are writing a server application, you should register an object with the ROT when it begins running, typically in your implementation of [IOleObject::DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb). The object must be registered under its full moniker, which requires getting the moniker of its container document using [IOleClientSite::GetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getmoniker). You should also revoke and re-register the object in your implementation of [IOleObject::SetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setmoniker), which is called if the container document is renamed.

If you are writing a container application that supports linking to embeddings, you should register your document with the ROT when it is loaded. If your document is renamed, you should revoke and re-register it with the ROT and call [IOleObject::SetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setmoniker) for any embedded objects in the document to give them an opportunity to re-register themselves.

Objects registered in the ROT must be explicitly revoked when the object is no longer running or when its moniker changes. This revocation is important because there is no way for the system to automatically remove entries from the ROT. You must cache the identifier that is written through pdwRegister and use it in a call to [IRunningObjectTable::Revoke](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-revoke) to revoke the registration. For a strong registration, a strong reference is released when the objects registration is revoked.

As of Windows Server 2003, if there are stale entries that remain in the ROT due to unexpected server problems, COM will automatically remove these stale entries from the ROT.

The system's implementation of **Register** calls [IMoniker::Reduce](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-reduce) on the *pmkObjectName* parameter to ensure that the moniker is fully reduced before registration. If an object is known by more than one fully reduced moniker, it should be registered under all such monikers.

## See also

[IRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunningobjecttable)