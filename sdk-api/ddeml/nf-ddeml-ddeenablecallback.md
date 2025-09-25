# DdeEnableCallback function

## Description

Enables or disables transactions for a specific conversation or for all conversations currently established by the calling application.

## Parameters

### `idInst` [in]

Type: **DWORD**

The application-instance identifier obtained by a previous call to the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function.

### `hConv` [in]

Type: **HCONV**

A handle to the conversation to enable or disable. If this parameter is **NULL**, the function affects all conversations.

### `wCmd` [in]

Type: **UINT**

The function code. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **EC_ENABLEALL**<br><br>0 | Enables all transactions for the specified conversation. |
| **EC_ENABLEONE**<br><br>0x0080 | Enables one transaction for the specified conversation. |
| **EC_DISABLE**<br><br>0x0008 | Disables all blockable transactions for the specified conversation. <br><br>A server application can disable the following transactions:<br><br>* [XTYP_ADVSTART](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advstart)<br>* [XTYP_ADVSTOP](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advstop)<br>* [XTYP_EXECUTE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-execute)<br>* [XTYP_POKE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-poke)<br>* [XTYP_REQUEST](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-request)<br><br>A client application can disable the following transactions:<br><br>* [XTYP_ADVDATA](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-advdata)<br>* [XTYP_XACT_COMPLETE](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-xact-complete) |
| **EC_QUERYWAITING**<br><br>2 | Determines whether any transactions are in the queue for the specified conversation. |

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

If the
*wCmd* parameter is **EC_QUERYWAITING**, and the application transaction queue contains one or more unprocessed transactions that are not being processed, the return value is **TRUE**; otherwise, it is **FALSE**.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## Remarks

An application can disable transactions for a specific conversation by returning the **CBR_BLOCK** return code from its Dynamic Data Exchange (DDE) callback function. When you reenable the conversation by using the **DdeEnableCallback** function, the operating system generates the same transaction that was in process when the conversation was disabled.

Using the **EC_QUERYWAITING** flag does not change the enable state of the conversation and does not cause transactions to be issued within the context of the call to **DdeEnableCallback**.

If **DdeEnableCallback** is called with **EC_QUERYWAITING** and the function returns a nonzero, an application should try to quickly allow message processing, return from its callback, or enable callbacks. Such a result does not guarantee that subsequent callbacks will be made. Calling **DdeEnableCallback** with **EC_QUERYWAITING** lets an application with blocked callbacks determine whether there are any transactions pending on the blocked conversation. Of course, even if such a call returns zero, an application should always process messages in a timely manner.

## See also

**Conceptual**

[DdeConnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnect)

[DdeConnectList](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnectlist)

[DdeDisconnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddedisconnect)

[DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**