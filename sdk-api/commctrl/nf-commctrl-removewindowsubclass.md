# RemoveWindowSubclass function

## Description

Removes a subclass callback from a window.

## Parameters

### `hWnd` [in]

Type: **HWND**

The handle of the window being subclassed.

### `pfnSubclass` [in]

Type: **[SUBCLASSPROC](https://learn.microsoft.com/windows/desktop/api/commctrl/nc-commctrl-subclassproc)**

A pointer to a window procedure. This pointer and the subclass ID uniquely identify this subclass callback. For the callback function prototype, see [SUBCLASSPROC](https://learn.microsoft.com/windows/desktop/api/commctrl/nc-commctrl-subclassproc).

### `uIdSubclass` [in]

Type: **UINT_PTR**

The **UINT_PTR** subclass ID. This ID and the callback pointer uniquely identify this subclass callback. Note: On 64-bit versions of Windows this is a 64-bit value.

## Return value

Type: **BOOL**

**TRUE** if the subclass callback was successfully removed; otherwise, **FALSE**.

## Remarks

Subclass callbacks are identified by their combination of the callback address and the subclass ID defined by the calling process.

The SUBCLASS module defines helper functions that are used to subclass windows. The code maintains a single property on the subclassed window and dispatches various subclass callbacks to its clients as required. The client is provided reference data and a default processing API.

No reference counting is performed for the callback; it may repeatedly call [SetWindowSubclass](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-setwindowsubclass) to alter the value of its reference data element.

**Warning** You cannot use the subclassing helper functions to subclass a window across threads.

## See also

[DefSubclassProc](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-defsubclassproc)

[GetWindowSubclass](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-getwindowsubclass)

[SetWindowSubclass](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-setwindowsubclass)