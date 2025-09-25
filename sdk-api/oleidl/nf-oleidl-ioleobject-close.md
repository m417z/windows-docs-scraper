# IOleObject::Close

## Description

Changes an embedded object from the running to the loaded state. Disconnects a linked object from its link source.

## Parameters

### `dwSaveOption` [in]

Indicates whether the object is to be saved as part of the transition to the loaded state. Valid values are taken from the enumeration [OLECLOSE](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-oleclose).

**Note** The OLE 2 user model recommends that object applications do not prompt users before saving linked or embedded objects, including those activated in place. This policy represents a change from the OLE 1 user model, in which object applications always prompt the user to decide whether to save changes.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **OLE_E_PROMPTSAVECANCELLED** | The user was prompted to save but chose the **Cancel** button from the prompt message box. |

## Remarks

### Notes to Callers

A container application calls **IOleObject::Close** when it wants to move the object from a running to a loaded state. Following such a call, the object still appears in its container but is not open for editing. Calling **IOleObject::Close** on an object that is loaded but not running has no effect. Closing a linked object simply means disconnecting it.

### Notes to Implementers

Upon receiving a call to **IOleObject::Close**, a running object should do the following:

* If the object has been changed since it was last opened for editing, it should request to be saved, or not, according to instructions specified in *dwSaveOption*. If the option is to save the object, then it should call its container's [IOleClientSite::SaveObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-saveobject) interface.
* If the object has [IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise) connections with [ADVF](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-advf)_DATAONSTOP flags, then it should send an [IAdviseSink::OnDataChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-ondatachange) notification. See **IDataObject::DAdvise** for details.
* If the object currently owns the Clipboard, it should empty it by calling [OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard).
* If the object is currently visible, notify its container by calling [IOleClientSite::OnShowWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-onshowwindow) with the *fshow* argument set to **FALSE**.
* Send [IAdviseSink::OnClose](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onclose) notifications to appropriate advise sinks.
* Finally, forcibly cut off all remoting clients by calling [CoDisconnectObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codisconnectobject).

If the object application is a local server (an EXE rather than a DLL), closing the object should also shut down the object application unless the latter is supporting other running objects or has another reason to remain in the running state. Such reasons might include the presence of [IClassFactory::LockServer](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nf-unknwnbase-iclassfactory-lockserver) locks, end-user control of the application, or the existence of other open documents requiring access to the application.

Calling **IOleObject::Close** on a linked object disconnects it from, but does not shut down, its source application. A source application that is visible to the user when the object is closed remains visible and running after the disconnection and does not send an [IAdviseSink::OnClose](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onclose) notification to the link container.

## See also

[CoDisconnectObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-codisconnectobject)

[IAdviseSink::OnClose](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iadvisesink-onclose)

[IClassFactory::LockServer](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nf-unknwnbase-iclassfactory-lockserver)

[IDataObject::DAdvise](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-idataobject-dadvise)

[IOleClientSite::OnShowWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-onshowwindow)

[IOleClientSite::SaveObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-saveobject)

[IOleObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleobject)

[OLECLOSE](https://learn.microsoft.com/windows/desktop/api/oleidl/ne-oleidl-oleclose)

[OleFlushClipboard](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleflushclipboard)