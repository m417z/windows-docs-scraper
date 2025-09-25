# SetInputScope function

## Description

Sets an input scope for the specified window.

## Parameters

### `hwnd` [in]

The window to set the scope on.

### `inputscope` [in]

The input scope to associate with the window. To remove the input scope association, pass IS_DEFAULT to this parameter.

## Return value

| Value | Meaning |
| --- | --- |
| S_OK | The method was successful. |

## Remarks

Calling this method replaces whatever scope is associated with the window.

An application must call this method, passing in IS_DEFAULT to the *hwnd* parameter, to remove the input scope association before the window is destroyed.

This API works only when the window (*hwnd* parameter) and the calling thread are in the same thread. If you call this API for a different thread's window, it fails with E_INVALIDARG.

If you call this method on a window (*hwnd* parameter) that has
not been associated with a Document Manager, then no text service notifications are sent to interested clients (such as the touch keyboard) that may want to respond to the
scope change.

#### Examples

[C++]

The following code illustrates how to set an input scope for a window.

```cpp

SetInputScope(hwnd, IS_EMAIL_USERNAME);

```