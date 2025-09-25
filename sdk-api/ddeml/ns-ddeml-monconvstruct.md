# MONCONVSTRUCT structure

## Description

Contains information about a Dynamic Data Exchange (DDE) conversation. A DDE monitoring application can use this structure to obtain information about a conversation that has been established or has terminated.

## Members

### `cb`

Type: **UINT**

The structure's size, in bytes.

### `fConnect`

Type: **BOOL**

Indicates whether the conversation is currently established. A value of **TRUE** indicates the conversation is established; **FALSE** indicates it is not.

### `dwTime`

Type: **DWORD**

The Windows time at which the conversation was established or terminated. Windows time is the number of milliseconds that have elapsed since the system was booted.

### `hTask`

Type: **HANDLE**

A handle to a task (application instance) that is a partner in the conversation.

### `hszSvc`

Type: **HSZ**

A handle to the service name on which the conversation is established.

### `hszTopic`

Type: **HSZ**

A handle to the topic name on which the conversation is established.

### `hConvClient`

Type: **HCONV**

A handle to the client conversation.

### `hConvServer`

Type: **HCONV**

A handle to the server conversation.

## Remarks

Because string handles are local to the process, the **hszSvc** and **hszTopic** members are global atoms. Similarly, conversation handles are local to the instance; therefore, the **hConvClient** and **hConvServer** members are window handles.

The **hConvClient** and **hConvServer** members of the **MONCONVSTRUCT** structure do not hold the same value as would be seen by the applications engaged in the conversation. Instead, they hold a globally unique pair of values that identify the conversation.

## See also

**Conceptual**

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

[MONCBSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-moncbstruct)

[MONERRSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monerrstruct)

[MONHSZSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monhszstructa)

[MONLINKSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monlinkstruct)

[MONMSGSTRUCT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-monmsgstruct)

**Reference**