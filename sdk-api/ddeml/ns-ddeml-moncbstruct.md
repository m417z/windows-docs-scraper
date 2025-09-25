# MONCBSTRUCT structure

## Description

Contains information about the current Dynamic Data Exchange (DDE) transaction. A DDE debugging application can use this structure when monitoring transactions that the system passes to the DDE callback functions of other applications.

## Members

### `cb`

Type: **UINT**

The structure's size, in bytes.

### `dwTime`

Type: **DWORD**

The Windows time at which the transaction occurred. Windows time is the number of milliseconds that have elapsed since the system was booted.

### `hTask`

Type: **HANDLE**

A handle to the task (application instance) containing the DDE callback function that received the transaction.

### `dwRet`

Type: **DWORD**

The value returned by the DDE callback function that processed the transaction.

### `wType`

Type: **UINT**

The transaction type.

### `wFmt`

Type: **UINT**

The format of the data exchanged (if any) during the transaction.

### `hConv`

Type: **HCONV**

A handle to the conversation in which the transaction took place.

### `hsz1`

Type: **HSZ**

A handle to a string.

### `hsz2`

Type: **HSZ**

A handle to a string.

### `hData`

Type: **HDDEDATA**

A handle to the data exchanged (if any) during the transaction.

### `dwData1`

Type: **ULONG_PTR**

Additional data.

### `dwData2`

Type: **ULONG_PTR**

Additional data.

### `cc`

Type: **[CONVCONTEXT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convcontext)**

The language information used to share data in different languages.

### `cbData`

Type: **DWORD**

The amount, in bytes, of data being passed with the transaction. This value can be more than 32 bytes.

### `Data`

Type: **DWORD[8]**

Contains the first 32 bytes of data being passed with the transaction (`8 * sizeof(DWORD)`).

## See also

[CONVCONTEXT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convcontext)

**Conceptual**

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

[MONERRSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monerrstruct)

[MONHSZSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monhszstructa)

[MONLINKSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monlinkstruct)

[MONMSGSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monmsgstruct)

**Reference**