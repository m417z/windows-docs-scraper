# IRunnableObject::SetContainedObject

## Description

Notifies an object that it is embedded in an OLE container, which ensures that reference counting is done correctly for containers that support links to embedded objects.

## Parameters

### `fContained` [in]

**TRUE** specifies that the object is contained in an OLE container. **FALSE** indicates that it is not.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and S_OK.

## Remarks

The **SetContainedObject** method enables a container to inform an object handler that it is embedded in the container, rather than acting as a link. This call changes the container's reference on the object from strong, the default for external connections, to weak. When the object is running visibly, this method is of little significance because the end user has a lock on the object. During a silent update of an embedded link source, however, the container should not be able to hold an object in the running state after the link has been broken. For this reason, the container's reference to the object must be weak.

### Notes to Callers

A container application must call **SetContainedObject** if it supports linking to embedded objects. It normally makes the call immediately after calling [OleLoad](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-oleload) or [OleCreate](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreate) and never calls the method again, even before it closes. Moreover, a container almost always calls this method with *fContained* set to **TRUE**. The use of this method with *fContained* set to **FALSE** is rare.

Calling **SetContainedObject** is optional only when you know that the embedded object will not be referenced by any client other than the container. If your container application does not support linking to embedded objects; it is preferable, but not necessary, to call **SetContainedObject**.

[OleSetContainedObject](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetcontainedobject) is a helper function that conveniently repackages the functionality offered by **SetContainedObject**. With the release of OLE 2.01, the implementation of **OleSetContainedObject** was changed to call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)), ask for [IRunnableObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunnableobject), and then call **IRunnableObject::SetContainedObject**. In other words, you can use the interface and the helper function interchangeably.

## See also

[IRunnableObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunnableobject)

[OleSetContainedObject](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olesetcontainedobject)