# IOleInPlaceObjectWindowless::OnWindowMessage

## Description

Dispatches a message from a container to a windowless object that is in-place active.

## Parameters

### `msg` [in]

The identifier for the window message provided to the container by Windows.

### `wParam` [in]

A parameter for the window message provided to the container by Windows.

### `lParam` [in]

A parameter for the window message provided to the container by Windows.

### `plResult` [out]

A pointer to result code for the window message.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The windowless object did not process the window message. The container should call the DefWindowProc for the message or process the message itself as described below. |

## Remarks

A container calls this method to send window messages to a windowless object that is in-place active. The container should dispatch messages according to the following guidelines:

For the following messages, the container should first dispatch the message to the windowless object that has captured the mouse, if any. Otherwise, the container should dispatch the message to the windowless object under the mouse cursor. If there is no such object, the container is free to process the following messages for itself:

* WM_MOUSEMOVE
* WM_SETCURSOR
* WM_XBUTTONDOWN
* WM_XBUTTONUP
* WM_XBUTTONDBLCLK

The container should dispatch the message to the windowless object with the keyboard focus for the following messages:

* WM_CANCELMODE
* WM_CHAR
* WM_DEADCHAR
* WM_HELP
* WM_IMExxx
* WM_KEYDOWN
* WM_KEYUP
* WM_SYSDEADCHAR
* WM_SYSKEYDOWN
* WM_SYSKEYUP

For all other messages, the container should process the message on its own.

The windowless object can return S_FALSE to this method to indicate that it did not process the message. Then, the container either performs the default behavior for the message by calling the [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function, or processes the message itself.

The container must pass the following window messages to the default window procedure:

* WM_CHAR
* WM_DEADCHAR
* WM_IMExxx
* WM_KEYDOWN
* WM_KEYUP
* WM_MOUSEMOVE
* WM_SYSCHAR
* WM_SYSDEADCHAR
* WM_SYSKEYUP
* WM_XBUTTONDOWN
* WM_XBUTTONUP
* WM_XBUTTONDBLCLK

The container must process the following window messages as its own:

* WM_CONTEXTMENU
* WM_HELP
* WM_SETCURSOR

**Note** For WM_SETCURSOR, the container can either set the cursor itself or do nothing.

Objects can also use [IOleInPlaceSiteWindowless::OnDefWindowMessage](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-ondefwindowmessage) to explicitly invoke the default message processing from the container. In the case of the WM_SETCURSOR message, this allows an object to take action if the container does not set the cursor.

All coordinates passed to the object in *wParam* and *lParam* are specified as client coordinates of the containing window.

## See also

- [IOleInPlaceObjectWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplaceobjectwindowless)
- [IOleInPlaceSiteWindowless::OnDefWindowMessage](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-ondefwindowmessage)
- [IOleInPlaceSiteWindowless:SetCapture](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ioleinplacesitewindowless-setcapture)
- [Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)