# DdeConnect function

## Description

Establishes a conversation with a server application that supports the specified service name and topic name pair. If more than one such server exists, the system selects only one.

## Parameters

### `idInst` [in]

Type: **DWORD**

The application instance identifier obtained by a previous call to the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function.

### `hszService` [in]

Type: **HSZ**

A handle to the string that specifies the service name of the server application with which a conversation is to be established. This handle must have been created by a previous call to the [DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea) function. If this parameter is 0L, a conversation is established with any available server.

### `hszTopic` [in]

Type: **HSZ**

A handle to the string that specifies the name of the topic on which a conversation is to be established. This handle must have been created by a previous call to [DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea). If this parameter is 0L, a conversation on any topic supported by the selected server is established.

### `pCC` [in, optional]

Type: **PCONVCONTEXT**

A pointer to the [CONVCONTEXT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convcontext) structure that contains conversation context information. If this parameter is **NULL**, the server receives the default **CONVCONTEXT** structure during the
[XTYP_CONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-connect) or
[XTYP_WILDCONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-wildconnect) transaction.

## Return value

Type: **HCONV**

If the function succeeds, the return value is the handle to the established conversation.

If the function fails, the return value is 0L.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## Remarks

The client application cannot make assumptions regarding the server selected. If an instance-specific name is specified in the
*hszService* parameter, a conversation is established with only the specified instance. Instance-specific service names are passed to an application's Dynamic Data Exchange (DDE) callback function during the [XTYP_REGISTER](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-register) and [XTYP_UNREGISTER](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-unregister) transactions.

All members of the default [CONVCONTEXT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convcontext) structure are set to zero except
*cb*, which specifies the size of the structure, and
*iCodePage*, which specifies **CP_WINANSI** (the default code page) or **CP_WINUNICODE**, depending on whether the ANSI or Unicode version of the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function was called by the client application.

## See also

[CONVCONTEXT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convcontext)

**Conceptual**

[DdeConnectList](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnectlist)

[DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea)

[DdeDisconnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddedisconnect)

[DdeDisconnectList](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddedisconnectlist)

[DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**

[XTYP_REGISTER](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-register)

[XTYP_UNREGISTER](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-unregister)