# DefSubclassProc function

## Description

Calls the next handler in a window's subclass chain. The last handler in the subclass chain calls the original window procedure for the window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window being subclassed.

### `uMsg` [in]

Type: **UINT**

A value of type unsigned **int** that specifies a window message.

### `wParam` [in]

Type: **WPARAM**

Specifies additional message information. The contents of this parameter depend on the value of the window message.

### `lParam` [in]

Type: **LPARAM**

Specifies additional message information. The contents of this parameter depend on the value of the window message. Note: On 64-bit versions of Windows LPARAM is a 64-bit value.

## Return value

Type: **LRESULT**

The returned value is specific to the message sent. This value should be ignored.

## Remarks

You do not need to call the default window procedure; this function calls it automatically.

The SUBCLASS module defines helper functions that are used to subclass windows. The code maintains a single property on the subclassed window and dispatches various subclass callbacks to its clients as required. The client is provided reference data and a default processing API.

A subclass callback is identified by a unique pairing of a callback function pointer and an unsigned ID value. Each callback can also store a single **DWORD** of reference data, which is passed to the callback function when it is called to filter messages. No reference counting is performed for the callback; it may repeatedly call [SetWindowSubclass](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-setwindowsubclass) to alter the value of its reference data element.

**Warning** You cannot use the subclassing helper functions to subclass a window across threads.

## See also

[GetWindowSubclass](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-getwindowsubclass)

[RemoveWindowSubclass](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-removewindowsubclass)

[SetWindowSubclass](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-setwindowsubclass)