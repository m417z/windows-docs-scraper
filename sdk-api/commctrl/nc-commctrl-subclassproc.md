# SUBCLASSPROC callback function

## Description

Defines the prototype for the callback function used by [RemoveWindowSubclass](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-removewindowsubclass) and [SetWindowSubclass](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-setwindowsubclass).

## Parameters

### `hWnd`

Type: **HWND**

The handle to the subclassed window.

### `uMsg`

Type: **UINT**

The message being passed.

### `wParam`

Type: **WPARAM**

Additional message information. The contents of this parameter depend on the value of *uMsg*.

### `lParam`

Type: **LPARAM**

Additional message information. The contents of this parameter depend on the value of *uMsg*.

### `uIdSubclass`

Type: **UINT_PTR**

The subclass ID.

### `dwRefData`

Type: **DWORD_PTR**

The reference data provided to the [SetWindowSubclass](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-setwindowsubclass) function. This can be used to associate the subclass instance with a "this" pointer.

## Return value

Type: **LRESULT**

The return value is the result of the message processing and depends on the message sent.