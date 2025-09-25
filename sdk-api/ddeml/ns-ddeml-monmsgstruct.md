# MONMSGSTRUCT structure

## Description

Contains information about a Dynamic Data Exchange (DDE) message. A DDE monitoring application can use this structure to obtain information about a DDE message that was sent or posted.

## Members

### `cb`

Type: **UINT**

The structure's size, in bytes.

### `hwndTo`

Type: **HWND**

A handle to the window that receives the DDE message.

### `dwTime`

Type: **DWORD**

The Windows time at which the message was sent or posted. Windows time is the number of milliseconds that have elapsed since the system was booted.

### `hTask`

Type: **HANDLE**

A handle to the task (application instance) containing the window that receives the DDE message.

### `wMsg`

Type: **UINT**

The identifier of the DDE message.

### `wParam`

Type: **WPARAM**

The **wParam** parameter of the DDE message.

### `lParam`

Type: **LPARAM**

The **lParam** parameter of the DDE message.

### `dmhd`

Type: **[DDEML_MSG_HOOK_DATA](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-ddeml_msg_hook_data)**

Additional information about the DDE message.

## See also

**Conceptual**

[DDEML_MSG_HOOK_DATA](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-ddeml_msg_hook_data)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

[MONCBSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-moncbstruct)

[MONCONVSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monconvstruct)

[MONERRSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monerrstruct)

[MONHSZSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monhszstructa)

[MONLINKSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monlinkstruct)

**Reference**