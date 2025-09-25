# GetWindowSubclass function

## Description

Retrieves the reference data for the specified window subclass callback.

## Parameters

### `hWnd` [in]

Type: **HWND**

The handle of the window being subclassed.

### `pfnSubclass` [in]

Type: **[SUBCLASSPROC](https://learn.microsoft.com/windows/desktop/api/commctrl/nc-commctrl-subclassproc)**

A pointer to a window procedure. This pointer and the subclass ID uniquely identify this subclass callback.

### `uIdSubclass` [in]

Type: **UINT_PTR**

**UINT_PTR** subclass ID. This ID and the callback pointer uniquely identify this subclass callback. Note: On 64-bit versions of Windows this is a 64-bit value.

### `pdwRefData` [out]

Type: **DWORD_PTR***

A pointer to a **DWORD** which will return the reference data. Note: On 64-bit versions of Windows, pointers are 64-bit values.

## Return value

Type: **BOOL**

| Return code | Description |
| --- | --- |
| **TRUE** | The subclass callback was successfully installed. |
| **FALSE** | The subclass callback was not installed. |

## Remarks

To use **GetWindowSubclass**, specify Comctl32.dll version 6 in the manifest. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).

## See also

[DefSubclassProc](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-defsubclassproc)

[RemoveWindowSubclass](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-removewindowsubclass)

[SetWindowSubclass](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-setwindowsubclass)