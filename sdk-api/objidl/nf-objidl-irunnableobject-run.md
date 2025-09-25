# IRunnableObject::Run

## Description

Forces an object to run.

## Parameters

### `pbc` [in]

A pointer to the binding context of the run operation. See [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx). This parameter can be **NULL**.

## Return value

This method can return the standard return values E_INVALIDARG, E_UNEXPECTED, and S_OK.

## Remarks

Containers call **IRunnableObject::Run** to force their objects to enter the running state. If the object is not already running, calling **Run** can be an expensive operation, on the order of many seconds. If the object is already running, then this method has no effect on the object.

### Notes to Callers

When called on a linked object that has been converted to a new class since the link was last activated, **IRunnableObject::Run** may return OLE_E_CLASSDIFF. In this case, the client should call [IOleLink::BindToSource](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-bindtosource).

[OleRun](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olerun) is a helper function that conveniently repackages the functionality offered by **IRunnableObject::Run**. With the release of OLE 2.01, the implementation of **OleRun** was changed so that it calls [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)), asks for [IRunnableObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunnableobject), and then calls **IRunnableObject::Run**. In other words, you can use the interface and the helper function interchangeably.

### Notes to Implementers

The object should register in the running object table if it has a moniker assigned. The object should not hold any strong locks on itself; instead, it should remain in the unstable, unlocked state. The object should be locked when the first external connection is made to the object.

An embedded object must hold a lock on its embedding container while it is in the running state. The default handler provided by OLE 2 takes care of locking the embedding container on behalf of objects implemented by an EXE object application. Objects implemented by a DLL object application must explicitly put a lock on their embedding containers, which they do by first calling [IOleClientSite::GetContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleclientsite-getcontainer) to get a pointer to the container, then calling [IOleContainer::LockContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolecontainer-lockcontainer) to actually place the lock. This lock must be released when [IOleObject::Close](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-close) is called.

## See also

[IRunnableObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunnableobject)

[OleRun](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olerun)