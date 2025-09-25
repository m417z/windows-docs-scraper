# IOleInPlaceSiteWindowless::SetCapture

## Description

Enables an in-place active, windowless object to capture all mouse messages.

## Parameters

### `fCapture` [in]

If **TRUE**, the container should capture the mouse for the object. If **FALSE**, the container should release mouse capture for the object.

## Return value

This method returns S_OK if the mouse capture was successfully granted to the object. If called to release the mouse capture, this method must not fail. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Mouse capture was denied to the object. |

## Remarks

A windowless object captures the mouse input, by calling **IOleInPlaceSiteWindowless::SetCapture** with **TRUE** on its site object. The container can deny mouse capture, in which case this method returns S_FALSE. If the capture is granted, the container must set the Windows mouse capture to its own window and dispatch any subsequent mouse message to the object, regardless of whether the mouse cursor position is over this object or not.

The object can later release mouse capture by calling **IOleInPlaceSiteWindowless::SetCapture** with **FALSE** on its site object. The capture can also be released because of an external event, such as the ESC key being pressed. In this case, the object is notified by a [WM_CANCELMODE](https://learn.microsoft.com/windows/desktop/winmsg/wm-cancelmode) message that the container dispatches along with the keyboard focus.

Containers should dispatch all mouse messages, including [WM_SETCURSOR](https://learn.microsoft.com/windows/desktop/menurc/wm-setcursor), to the windowless OLE object that has captured the mouse. If no object has captured the mouse, the container should dispatch the mouse message to the object under the mouse cursor.

The container dispatches these window messages by calling [IOleInPlaceObjectWindowless::OnWindowMessage](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplaceobjectwindowless-onwindowmessage) on the windowless object. The windowless object can return S_FALSE to this method to indicate that it did not process the mouse message. Then, the container should perform the default behavior for the message by calling the [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function. For [WM_SETCURSOR](https://learn.microsoft.com/windows/desktop/menurc/wm-setcursor), the container can either set the cursor itself or do nothing.

Objects can also use [IOleInPlaceSiteWindowless::OnDefWindowMessage](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-ondefwindowmessage) to invoke the default message processing from the container. In the case of the [WM_SETCURSOR](https://learn.microsoft.com/windows/desktop/menurc/wm-setcursor) message, this allows an object to take action if the container does not set the cursor.

## See also

[IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless)

[IOleInPlaceSiteWindowless::OnDefWindowMessage](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-ondefwindowmessage)