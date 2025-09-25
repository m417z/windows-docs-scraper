# MONLINKSTRUCT structure

## Description

Contains information about a Dynamic Data Exchange (DDE) advise loop. A DDE monitoring application can use this structure to obtain information about an advise loop that has started or ended.

## Members

### `cb`

Type: **UINT**

The structure's size, in bytes.

### `dwTime`

Type: **DWORD**

The Windows time at which the advise loop was started or ended. Windows time is the number of milliseconds that have elapsed since the system was booted.

### `hTask`

Type: **HANDLE**

A handle to a task (application instance) that is a partner in the advise loop.

### `fEstablished`

Type: **BOOL**

Indicates whether an advise loop was successfully established. A value of **TRUE** indicates an advise loop was established; **FALSE** indicates it was not.

### `fNoData`

Type: **BOOL**

Indicates whether the XTYPF_NODATA flag is set for the advise loop. A value of **TRUE** indicates the flag is set; **FALSE** indicates it is not.

### `hszSvc`

Type: **HSZ**

A handle to the service name of the server in the advise loop.

### `hszTopic`

Type: **HSZ**

A handle to the topic name on which the advise loop is established.

### `hszItem`

Type: **HSZ**

A handle to the item name that is the subject of the advise loop.

### `wFmt`

Type: **UINT**

The format of the data exchanged (if any) during the advise loop.

### `fServer`

Type: **BOOL**

Indicates whether the link notification came from the server. A value of **TRUE** indicates the notification came from the server; **FALSE** indicates otherwise.

### `hConvServer`

Type: **HCONV**

A handle to the server conversation.

### `hConvClient`

Type: **HCONV**

A handle to the client conversation.

## Remarks

Because string handles are local to the process, the **hszSvc**, **hszTopic**, and **hszItem** members are global atoms.

The
**hConvClient** and **hConvServer** members of the **MONLINKSTRUCT** structure do not hold the same value as would be seen by the applications engaged in the conversation. Instead, they hold a globally unique pair of values that identify the conversation.

## See also

**Conceptual**

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

[MONCBSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-moncbstruct)

[MONERRSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monerrstruct)

[MONHSZSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monhszstructa)

[MONMSGSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monmsgstruct)

**Reference**