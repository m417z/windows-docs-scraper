# NOTIFYICONIDENTIFIER structure

## Description

Contains information used by [Shell_NotifyIconGetRect](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shell_notifyicongetrect) to identify the icon for which to retrieve the bounding rectangle.

## Members

### `cbSize`

Type: **DWORD**

The size of this structure, in bytes.

### `hWnd`

Type: **HWND**

A handle to the parent window used by the notification's callback function. For more information, see the *hWnd* member of the [NOTIFYICONDATA](https://learn.microsoft.com/windows/desktop/api/shellapi/ns-shellapi-notifyicondataa) structure.

### `uID`

Type: **UINT**

The application-defined identifier of the notification icon. Multiple icons can be associated with a single *hWnd*, each with their own *uID*.

### `guidItem`

Type: **GUID**

A registered GUID that identifies the icon. Use **GUID_NULL** if the icon is not identified by a GUID.

## Remarks

The icon can be identified to [Shell_NotifyIconGetRect](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-shell_notifyicongetrect) through this structure in two ways:

* *guidItem* alone (recommended)
* *hWnd* plus *uID*

If *guidItem* is not **GUID_NULL**, *hWnd* and *uID* are ignored.