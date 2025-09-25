# IPointerInactive::GetActivationPolicy

## Description

Retrieves the current activation policy for the object. This method is called by the container on receipt of a WM_SETCURSOR or WM_MOUSEMOVE message when an inactive object is under the mouse pointer.

## Parameters

### `pdwPolicy` [out]

A pointer to a variable that receives the activation policy. Possible values come from the [POINTERINACTIVE](https://learn.microsoft.com/windows/desktop/api/ocidl/ne-ocidl-pointerinactive) enumeration.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## Remarks

The object can request to be in-place activated as soon as the mouse enters it through the POINTERINACTIVE_ACTIVATEONENTRY value. An object that provides more visual feedback than simply setting the mouse pointer would use this value. For example, if the object supports special visual feedback, it must enter the active state so it can draw the visual feedback that it supports.

An object can also use this method to request activation when the mouse is dragged over them during a drag and drop operation through the POINTERINACTIVE_ACTIVATEONDRAG.

If the object returns one of these values, the container should activate the object immediately and forward the Window message that triggered the call. The object then stays active and processes subsequent messages through its own window until the container gets another WM_SETCURSOR or WM_MOUSEMOVE. At this point, the container should deactivate the object.

For windowless OLE objects this mechanism is slightly different. See [IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless) for more information on drag and drop operations for windowless objects.

If the object returns both the POINTERINACTIVE_ACTIVATEONENTRY and the POINTERINACTIVE_DEACTIVATEONLEAVE values, the object is activated only when the mouse is over the object. If the POINTERINACTIVE_ACTIVATEONENTRY value alone is set, the object is activated once when the mouse first enters it, and it remains active.

### Notes to Callers

The activation policy should not be cached. The container should call this method each time the mouse enters an inactive object.

## See also

[IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless)

[IPointerInactive](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipointerinactive)