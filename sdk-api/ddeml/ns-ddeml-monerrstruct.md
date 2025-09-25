# MONERRSTRUCT structure

## Description

Contains information about the current Dynamic Data Exchange (DDE) error. A DDE monitoring application can use this structure to monitor errors returned by DDE Management Library functions.

## Members

### `cb`

Type: **UINT**

The structure's size, in bytes.

### `wLastError`

Type: **UINT**

The current error.

### `dwTime`

Type: **DWORD**

The Windows time at which the error occurred. Windows time is the number of milliseconds that have elapsed since the system was booted.

### `hTask`

Type: **HANDLE**

A handle to the task (application instance) that called the DDE function that caused the error.

## See also

**Conceptual**

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

[MONCBSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-moncbstruct)

[MONCONVSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monconvstruct)

[MONHSZSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monhszstructa)

[MONLINKSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monlinkstruct)

[MONMSGSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monmsgstruct)

**Reference**