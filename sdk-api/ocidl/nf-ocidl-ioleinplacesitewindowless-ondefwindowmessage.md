# IOleInPlaceSiteWindowless::OnDefWindowMessage

## Description

Invokes the default processing for all messages passed to an object.

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
| **S_FALSE** | The container's default processing for the window message was not invoked. See Note to Implementers below. |

## Remarks

A windowless object can explicitly invoke the default processing for a window message by calling this method. A container dispatches window messages to its windowless objects by calling [IOleInPlaceObjectWindowless::OnWindowMessage](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplaceobjectwindowless). The object usually returns S_FALSE to indicate that it did not process the message. Then, the container can perform the default behavior for the message by calling the [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function.

Instead, the object can call this method on the container's site object to explicitly invoke the default processing. Then, the object can take action on its own if the container does not handle the message.

### Notes to Implementers

The container must pass the following window messages to its default window procedure (the [DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function) and return S_OK. Note that **plResult* should contain the value returned by **DefWindowProc**.

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

The container can either process the window messages as its own and return S_OK or not do anything and return S_FALSE.

* WM_CONTEXTMENU
* WM_HELP
* WM_SETCURSOR

If the container returns S_FALSE, the object can take action to process the window message on its own.

## See also

[IOleInPlaceObjectWindowless::OnWindowMessage](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplaceobjectwindowless)

[IOleInPlaceSiteWindowless](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesitewindowless)