# SetWindowSubclass function

## Description

Installs or updates a window subclass callback.

## Parameters

### `hWnd` [in]

Type: **HWND**

The handle of the window being subclassed.

### `pfnSubclass` [in]

Type: **[SUBCLASSPROC](https://learn.microsoft.com/windows/desktop/api/commctrl/nc-commctrl-subclassproc)**

A pointer to a window procedure. This pointer and the subclass ID uniquely identify this subclass callback. For the callback function prototype, see [SUBCLASSPROC](https://learn.microsoft.com/windows/desktop/api/commctrl/nc-commctrl-subclassproc).

### `uIdSubclass` [in]

Type: **UINT_PTR**

The subclass ID. This ID together with the subclass procedure uniquely identify a subclass. To remove a subclass, pass the subclass procedure and this value to the [RemoveWindowSubclass](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-removewindowsubclass) function. This value is passed to the subclass procedure in the uIdSubclass parameter.

### `dwRefData` [in]

Type: **DWORD_PTR**

**DWORD_PTR** to reference data. The meaning of this value is determined by the calling application. This value is passed to the subclass procedure in the dwRefData parameter. A different dwRefData is associated with each combination of window handle, subclass procedure and uIdSubclass.

## Return value

Type: **BOOL**

**TRUE** if the subclass callback was successfully installed; otherwise, **FALSE**.

## Remarks

Subclass callbacks are identified by the combination of the callback address and the caller-defined subclass ID. If the callback address and ID pair have not yet been installed, then this function installs the subclass. If the pair has already been installed, then this function just updates the reference data.

Each callback can store a single **DWORD_PTR** of reference data, which is passed to the callback function when it is called to filter messages. No reference counting is performed for the callback; it may repeatedly call **SetWindowSubclass** to alter the value of its reference data element.

**Warning** You cannot use the subclassing helper functions to subclass a window across threads.

## See also

[DefSubclassProc](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-defsubclassproc)

[GetWindowSubclass](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-getwindowsubclass)

[RemoveWindowSubclass](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-removewindowsubclass)