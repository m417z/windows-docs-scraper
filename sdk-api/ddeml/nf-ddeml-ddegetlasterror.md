# DdeGetLastError function

## Description

Retrieves the most recent error code set by the failure of a Dynamic Data Exchange Management Library (DDEML) function and resets the error code to DMLERR_NO_ERROR.

## Parameters

### `idInst` [in]

Type: **DWORD**

The application instance identifier obtained by a previous call to the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function.

## Return value

Type: **UINT**

If the function succeeds, the return value is the last error code, which can be one of the following values.

| Return code/value | Description |
| --- | --- |
| **DMLERR_ADVACKTIMEOUT**<br><br>0x4000 | A request for a synchronous advise transaction has timed out. |
| **DMLERR_BUSY**<br><br>0x4001 | The response to the transaction caused the **DDE_FBUSY** flag to be set. |
| **DMLERR_DATAACKTIMEOUT**<br><br>0x4002 | A request for a synchronous data transaction has timed out. |
| **DMLERR_DLL_NOT_INITIALIZED**<br><br>0x4003 | A DDEML function was called without first calling the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function, or an invalid instance identifier was passed to a DDEML function. |
| **DMLERR_DLL_USAGE**<br><br>0x4004 | An application initialized as **APPCLASS_MONITOR** has attempted to perform a DDE transaction, or an application initialized as **APPCMD_CLIENTONLY** has attempted to perform server transactions. |
| **DMLERR_EXECACKTIMEOUT**<br><br>0x4005 | A request for a synchronous execute transaction has timed out. |
| **DMLERR_INVALIDPARAMETER**<br><br>0x4006 | A parameter failed to be validated by the DDEML. Some of the possible causes follow: <br><br>The application used a data handle initialized with a different item name handle than was required by the transaction. <br><br>The application used a data handle that was initialized with a different clipboard data format than was required by the transaction. <br><br>The application used a client-side conversation handle with a server-side function or vice versa. <br><br>The application used a freed data handle or string handle. <br><br>More than one instance of the application used the same object. |
| **DMLERR_LOW_MEMORY**<br><br>0x4007 | A DDEML application has created a prolonged race condition (in which the server application outruns the client), causing large amounts of memory to be consumed. |
| **DMLERR_MEMORY_ERROR**<br><br>0x4008 | A memory allocation has failed. |
| **DMLERR_NO_CONV_ESTABLISHED**<br><br>0x400a | A client's attempt to establish a conversation has failed. |
| **DMLERR_NOTPROCESSED**<br><br>0x4009 | A transaction has failed. |
| **DMLERR_POKEACKTIMEOUT**<br><br>0x400b | A request for a synchronous poke transaction has timed out. |
| **DMLERR_POSTMSG_FAILED**<br><br>0x400c | An internal call to the [PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea) function has failed. |
| **DMLERR_REENTRANCY**<br><br>0x400d | An application instance with a synchronous transaction already in progress attempted to initiate another synchronous transaction, or the [DdeEnableCallback](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeenablecallback) function was called from within a DDEML callback function. |
| **DMLERR_SERVER_DIED**<br><br>0x400e | A server-side transaction was attempted on a conversation terminated by the client, or the server terminated before completing a transaction. |
| **DMLERR_SYS_ERROR**<br><br>0x400f | An internal error has occurred in the DDEML. |
| **DMLERR_UNADVACKTIMEOUT**<br><br>0x4010 | A request to end an advise transaction has timed out. |
| **DMLERR_UNFOUND_QUEUE_ID**<br><br>0x4011 | An invalid transaction identifier was passed to a DDEML function. Once the application has returned from an [XTYP_XACT_COMPLETE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-xact-complete) callback, the transaction identifier for that callback function is no longer valid. |

## See also

**Conceptual**

[DdeEnableCallback](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeenablecallback)

[DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

[PostMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-postmessagea)

**Reference**