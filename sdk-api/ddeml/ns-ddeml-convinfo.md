# CONVINFO structure

## Description

Contains information about a Dynamic Data Exchange (DDE) conversation.

## Members

### `cb`

Type: **DWORD**

The structure's size, in bytes.

### `hUser`

Type: **DWORD_PTR**

Application-defined data.

### `hConvPartner`

Type: **HCONV**

A handle to the partner application in the DDE conversation. This member is zero if the partner has not registered itself (using the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function) to make DDEML function calls. An application should not pass this member to any DDEML function except [DdeQueryConvInfo](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequeryconvinfo).

### `hszSvcPartner`

Type: **HSZ**

A handle to the service name of the partner application.

### `hszServiceReq`

Type: **HSZ**

A handle to the service name of the server application that was requested for connection.

### `hszTopic`

Type: **HSZ**

A handle to the name of the requested topic.

### `hszItem`

Type: **HSZ**

A handle to the name of the requested item. This member is transaction specific.

### `wFmt`

Type: **UINT**

The format of the data being exchanged. This member is transaction specific.

### `wType`

Type: **UINT**

The type of the current transaction. This member is transaction specific; it can be one of the following values.

| Value | Meaning |
| --- | --- |
| **XTYP_ADVDATA**<br><br>0x4010 | Informs a client that advise data from a server has arrived. |
| **XTYP_ADVREQ**<br><br>0x2022 | Requests a server to send updated data to the client during an advise loop. This transaction results when the server calls [DdePostAdvise](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddepostadvise). |
| **XTYP_ADVSTART**<br><br>0x1030 | Requests a server to begin an advise loop with a client. |
| **XTYP_ADVSTOP**<br><br>0x8040 | Notifies a server that an advise loop is stopping. |
| **XTYP_CONNECT**<br><br>0x1062 | Requests a server to establish a conversation with a client. |
| **XTYP_CONNECT_CONFIRM**<br><br>0x8072 | Notifies a server that a conversation with a client has been established. |
| **XTYP_DISCONNECT**<br><br>0x80C2 | Notifies a server that a conversation has terminated. |
| **XTYP_EXECUTE**<br><br>0x4050 | Requests a server to execute a command sent by a client. |
| **XTYP_MONITOR**<br><br>0x80F2 | Notifies an application registered as **APPCMD_MONITOR** that DDE data is being transmitted. |
| **XTYP_POKE**<br><br>0x4090 | Requests a server to accept unsolicited data from a client. |
| **XTYP_REGISTER**<br><br>0x80A2 | Notifies other DDEML applications that a server has registered a service name. |
| **XTYP_REQUEST**<br><br>0x20B0 | Requests a server to send data to a client. |
| **XTYP_UNREGISTER**<br><br>0x80D2 | Notifies other DDEML applications that a server has unregistered a service name. |
| **XTYP_WILDCONNECT**<br><br>0x20E2 | Requests a server to establish multiple conversations with the same client. |
| **XTYP_XACT_COMPLETE**<br><br>0x8080 | Notifies a client that an asynchronous data transaction has been completed. |

### `wStatus`

Type: **UINT**

The status of the current conversation. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **ST_ADVISE**<br><br>0x0002 | One or more links are in progress. |
| **ST_BLOCKED**<br><br>0x0008 | The conversation is blocked. |
| **ST_BLOCKNEXT**<br><br>0x0080 | The conversation will block after calling the next callback. |
| **ST_CLIENT**<br><br>0x0010 | The con0x0010versation handle passed to the [DdeQueryConvInfo](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequeryconvinfo) function is a client-side handle. If the handle is zero, the conversation handle passed to the **DdeQueryConvInfo** function is a server-side handle. |
| **ST_CONNECTED**<br><br>0x0001 | The conversation is connected. |
| **ST_INLIST**<br><br>0x0040 | The conversation is a member of a conversation list. |
| **ST_ISLOCAL**<br><br>0x0004 | Both sides of the conversation are using the DDEML. |
| **ST_ISSELF**<br><br>0x0100 | Both sides of the conversation are using the same instance of the DDEML. |
| **ST_TERMINATED**<br><br>0x0020 | The conversation has been terminated by the partner. |

### `wConvst`

Type: **UINT**

The conversation state. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **XST_ADVACKRCVD**<br><br>13 | The advise transaction has just been completed. |
| **XST_ADVDATAACKRCVD**<br><br>16 | The advise data transaction has just been completed. |
| **XST_ADVDATASENT**<br><br>15 | Advise data has been sent and is awaiting an acknowledgment. |
| **XST_ADVSENT**<br><br>11 | An advise transaction is awaiting an acknowledgment. |
| **XST_CONNECTED**<br><br>2 | The conversation has no active transactions. |
| **XST_DATARCVD**<br><br>6 | The requested data has just been received. |
| **XST_EXECACKRCVD**<br><br>10 | An execute transaction has just been completed. |
| **XST_EXECSENT**<br><br>9 | An execute transaction is awaiting an acknowledgment. |
| **XST_INCOMPLETE**<br><br>1 | The last transaction failed. |
| **XST_INIT1**<br><br>3 | Mid-initiate state 1. |
| **XST_INIT2**<br><br>4 | Mid-initiate state 2. |
| **XST_NULL**<br><br>0 | Pre-initiate state. |
| **XST_POKEACKRCVD**<br><br>8 | A poke transaction has just been completed. |
| **XST_POKESENT**<br><br>7 | A poke transaction is awaiting an acknowledgment. |
| **XST_REQSENT**<br><br>5 | A request transaction is awaiting an acknowledgment. |
| **XST_UNADVACKRCVD**<br><br>14 | An unadvise transaction has just been completed. |
| **XST_UNADVSENT**<br><br>12 | An unadvise transaction is awaiting an acknowledgment. |

### `wLastError`

Type: **UINT**

The error value associated with the last transaction.

### `hConvList`

Type: **HCONVLIST**

A handle to the conversation list if the handle to the current conversation is in a conversation list. This member is **NULL** if the conversation is not in a conversation list.

### `ConvCtxt`

Type: **[CONVCONTEXT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convcontext)**

The conversation context.

### `hwndPartner`

Type: **HWND**

A handle to the window of the partner application involved in the current conversation.

### `hwnd`

Type: **HWND**

A handle to the window of the calling application involved in the conversation.

## See also

[CONVCONTEXT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convcontext)

**Conceptual**

[DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea)

[DdePostAdvise](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddepostadvise)

[DdeQueryConvInfo](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequeryconvinfo)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**