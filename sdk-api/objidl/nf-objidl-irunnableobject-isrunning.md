# IRunnableObject::IsRunning

## Description

Determines whether an object is currently in the running state.

## Return value

If the object is in the running state, the return value is **TRUE**. Otherwise, it is **FALSE**.

## Remarks

A container application could call **IRunnableObject::IsRunning** when it needs to know if the server is immediately available. For example, a container's implementation of the [IOleItemContainer::GetObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleitemcontainer-getobject) method would return an error if the server is not running and the bindspeed parameter specifies BINDSPEED_IMMEDIATE.

An object handler could call **IRunnableObject::IsRunning** when it wants to avoid conflicts with a running server or when the running server might have more up-to-date information. For example, a handler's implementation of [IOleObject::GetExtent](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-getextent) would delegate to the object server if it is running, because the server's information might be more current than that in the handler's cache.

[OleIsRunning](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleisrunning) is a helper function that conveniently repackages the functionality offered by **IRunnableObject::IsRunning**. With the release of OLE 2.01, the implementation of **OleIsRunning** was changed so that it calls [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)), asks for [IRunnableObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunnableobject), and then calls **IRunnableObject::IsRunning**. In other words, you can use the interface and the helper function interchangeably.

## See also

[IRunnableObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunnableobject)

[OleIsRunning](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleisrunning)