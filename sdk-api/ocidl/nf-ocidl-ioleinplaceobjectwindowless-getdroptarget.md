# IOleInPlaceObjectWindowless::GetDropTarget

## Description

Retrieves the [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interface for an in-place active, windowless object that supports drag and drop.

## Parameters

### `ppDropTarget` [out]

A pointer to an [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) pointer variable that receives the interface pointer to the windowless object.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | The windowless object does not support drag and drop. |

## Remarks

A windowed object registers its [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interface by calling the [RegisterDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-registerdragdrop) function and supplying its window handle as a parameter. Registering its **IDropTarget** interface enables the object to participate in drag and drop operations. Because it does not have a window when active, a windowless object cannot register its **IDropTarget** interface. Therefore, it cannot directly participate in drag and drop operations without support from its container.

The following events occur during a drag and drop operation involving windowless objects:

* The container registers its own [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interface through the [RegisterDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-registerdragdrop) function.
* In the container's implementation of its own [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter) or [IDropTarget::DragOver](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover) methods, the container detects whether the mouse pointer just entered an embedded object.
* If the object is inactive, the container calls the object's [IPointerInactive::GetActivationPolicy](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipointerinactive-getactivationpolicy) method. The object returns the POINTERINACTIVE_ACTIVATEONDRAG flag. The container then activates the object in place. If the object was already active, the container does not have to do this step.
* After the object is active, the container must then obtain the object's [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interface.
* A windowless object that wishes to be a drop target still implements the [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interface, but does not register it and does not return it through calls to [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)). Instead, the container can obtain this interface by calling the object's **IOleInPlaceObjectWindowless::GetDropTarget** method. The object returns a pointer to its own **IDropTarget** interface if it wants to participate in drag and drop operations. The container can cache this interface pointer for later use. For example, on subsequent calls to the container's [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter) or [IDropTarget::DragLeave](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragleave) methods, the container can use the cached pointer instead of calling the object's GetDropTarget method again.
* The container then calls the object's [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter) and passes the returned value for *pdwEffect* from its own [IDropTarget::DragOver](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover) or **IDropTarget::DragEnter** methods. From this point on, the container forwards all subsequent **IDropTarget::DragOver** calls to the windowless object until the mouse leaves the object or a drop occurs on the object. If the mouse leaves the object, the container calls the object's [IDropTarget::DragLeave](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragleave) and then releases the object's [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interface. If the drop occurs, the container forwards the [IDropTarget::Drop](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-drop) call to the object.
* Finally, the container in-place deactivates the object.

An object can return S_FALSE from its own [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter) to indicate that it does not accept any of the data formats in the data object. In that case, the container can decide to accept the data for itself and return an appropriate *dwEffect* from its own **IDropTarget::DragEnter** or [IDropTarget::DragOver](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover) methods.

An object that returns S_FALSE from [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter) should be prepared to receive subsequent calls to **IDropTarget::DragEnter** without any [IDropTarget::DragLeave](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragleave) in between. Indeed, if the mouse is still over the same object during the next call to the container's [IDropTarget::DragOver](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover), the container may decide to try and call **IDropTarget::DragEnter** again on the object.

### Notes to Callers

A container can cache the pointer to the object's [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interface for later use.

## See also

[IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget)

[IOleInPlaceObjectWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplaceobjectwindowless)

[IPointerInactive::GetActivationPolicy](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipointerinactive-getactivationpolicy)

[RegisterDragDrop](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-registerdragdrop)