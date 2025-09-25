# ENOLEOPFAILED structure

## Description

Contains information about a failed operation.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr) notification header.

### `iob`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Object index.

### `lOper`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Operation that failed. This can be **OLEOP_DOVERB** to indicate that [IOleObject::DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb) failed.

### `hr`

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Error code returned by the object on the operation.

## See also

[EN_OLEOPFAILED](https://learn.microsoft.com/windows/win32/controls/en-oleopfailed)

[IOleObject::DoVerb](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-doverb)

**Other Resources**

**Reference**