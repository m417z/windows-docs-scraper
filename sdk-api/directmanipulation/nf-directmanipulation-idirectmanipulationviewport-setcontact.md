# IDirectManipulationViewport::SetContact

## Description

Specifies an association between a contact and the viewport.

## Parameters

### `pointerId` [in]

The ID of the pointer.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this method when a [WM_POINTERDOWN](https://learn.microsoft.com/previous-versions/windows/desktop/inputmsg/wm-pointerdown) message is received. Upon receiving a **WM_POINTERDOWN**, the application can use the coordinates of the input to hit-test and determine the viewports to which the contact is associated.

[DeferContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationdefercontactservice-defercontact) must be called before **SetContact**.

After initialization, [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) is not aware of viewport z-order or parent-child relations between viewports. The order of **SetContact** calls defines the viewport tree. To establish the correct viewport hierarchy, **SetContact** should be called first on the child-most viewport, followed by the parent, grand-parent, and so on.

Use [GET_POINTERID_WPARAM](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-get_pointerid_wparam) to get the pointer identifier from a pointer message. The contact is removed automatically when [WM_POINTERUP](https://learn.microsoft.com/previous-versions/windows/desktop/inputmsg/wm-pointerup) is received.

If a contact is associated with one or more viewports using the **SetContact** method, [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) will examine further input from that contact and attempt to identify an appropriate manipulation based on the configuration of the associated viewports. If a manipulation is recognized, the application will then receive a [WM_POINTERCAPTURECHANGED](https://learn.microsoft.com/previous-versions/windows/desktop/inputmsg/wm-pointercapturechanged) message for this contact. In this context, the **WM_POINTERCAPTURECHANGED** message indicates that Direct Manipulation has captured the contact and the application will not receive input from this contact that is consumed for this manipulation.

## See also

[IDirectManipulationViewport](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationviewport)

[User Input Messages and Notifications](https://learn.microsoft.com/previous-versions/windows/desktop/inputmsg/messages-and-notifications)