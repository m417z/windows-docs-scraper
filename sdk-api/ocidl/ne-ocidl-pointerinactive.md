# POINTERINACTIVE enumeration

## Description

Indicate the activation policy of the object and are used in the [IPointerInactive::GetActivationPolicy](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipointerinactive-getactivationpolicy) method.

## Constants

### `POINTERINACTIVE_ACTIVATEONENTRY:1`

The object should be in-place activated when the mouse enters it during a mouse move operation.

### `POINTERINACTIVE_DEACTIVATEONLEAVE:2`

The object should be deactivated when the mouse leaves the object during a mouse move operation.

### `POINTERINACTIVE_ACTIVATEONDRAG:4`

The object should be in-place activated when the mouse is dragged over it during a drag and drop operation.

## Remarks

For more information on using the **POINTERINACTIVE_ACTIVATEONENTRY** and **POINTERINACTIVE_DEACTIVATEONLEAVE** values, see the [IPointerInactive::GetActivationPolicy](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipointerinactive-getactivationpolicy) method.

**The POINTERINACTIVE_ACTIVATEONDRAG** value can be used to support drag and drop operations on an inactive object. An inactive object has no window to register itself as a potential drop target. Most containers ignore embedded, inactive objects as drop targets because of the overhead associated with activating them.

As an alternative to activating an object when the mouse pointer is over it during a drag and drop operation, the container can first [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to determine if the inactive object supports [IPointerInactive](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipointerinactive). Then, if the object does not support IPointerInactive, the container can assume that it is not a drop target. If the object does support **IPointerInactive**, the container calls the [IPointerInactive::GetActivationPolicy](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipointerinactive-getactivationpolicy) method. If the **POINTERINACTIVE_ACTIVATEONDRAG** value is set, the container activates the object in-place so the object can register its own [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) interface.

The container is processing its own [IDropTarget::DragOver](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragover) method when all these actions occur. To complete that method, the container returns **DROPEFFECT_NONE** for the *pdwEffect* parameter. Then, the drag and drop operation continues by calling the container's [IDropTarget::DragLeave](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragleave) and then calling the object's [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter).

**Important** For windowless OLE objects this mechanism is slightly different. See I[OleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless) for more information on drag and drop operations for windowless objects.

If the drop occurs on the embedded object, the object is UI-activated and will get UI-deactivated when the focus changes again. If the drop does not occur on the object, the container should deactivate the object the next time it gets a call to its own [IDropTarget::DragEnter](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-idroptarget-dragenter). It is possible for the drop to occur on a third active object without an intervening call to the container's IDropTarget::DragEnter. In this case, the container should try to deactivate the object as soon as it can, for example, when it UI-activates another object.

## See also

[IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget)

[IPointerInactive](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipointerinactive)

[IPointerInactive::GetActivationPolicy](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipointerinactive-getactivationpolicy)