# DDEML_MSG_HOOK_DATA structure

## Description

Contains information about a Dynamic Data Exchange (DDE) message, and provides read access to the data referenced by the message. This structure is intended to be used by a Dynamic Data Exchange Management Library (DDEML) monitoring application.

## Members

### `uiLo`

Type: **UINT_PTR**

The unpacked low-order word of the *lParam* parameter associated with the DDE message.

### `uiHi`

Type: **UINT_PTR**

The unpacked high-order word of the *lParam* parameter associated with the DDE message.

### `cbData`

Type: **DWORD**

The amount of data being passed with the message, in bytes. This value can be greater than 32.

### `Data`

Type: **DWORD[8]**

The first 32 bytes of data being passed with the message (`8 * sizeof(DWORD)`).

## See also

**Conceptual**

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

[MONCBSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-moncbstruct)

[MONCONVSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monconvstruct)

[MONERRSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monerrstruct)

[MONHSZSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monhszstructa)

[MONLINKSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monlinkstruct)

[MONMSGSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monmsgstruct)

**Reference**