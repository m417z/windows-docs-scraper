# DdeConnectList function

## Description

Establishes a conversation with all server applications that support the specified service name and topic name pair. An application can also use this function to obtain a list of conversation handles by passing the function an existing conversation handle. The [Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library) removes the handles of any terminated conversations from the conversation list. The resulting conversation list contains the handles of all currently established conversations that support the specified service name and topic name.

## Parameters

### `idInst` [in]

Type: **DWORD**

The application instance identifier obtained by a previous call to the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function.

### `hszService` [in]

Type: **HSZ**

A handle to the string that specifies the service name of the server application with which a conversation is to be established. If this parameter is 0L, the system attempts to establish conversations with all available servers that support the specified topic name.

### `hszTopic` [in]

Type: **HSZ**

A handle to the string that specifies the name of the topic on which a conversation is to be established. This handle must have been created by a previous call to the [DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea) function. If this parameter is 0L, the system will attempt to establish conversations on all topics supported by the selected server (or servers).

### `hConvList` [in]

Type: **HCONVLIST**

A handle to the conversation list to be enumerated. This parameter should be 0L if a new conversation list is to be established.

### `pCC` [in, optional]

Type: **PCONVCONTEXT**

A pointer to the [CONVCONTEXT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convcontext) structure that contains conversation-context information. If this parameter is **NULL**, the server receives the default **CONVCONTEXT** structure during the
[XTYP_CONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-connect) or
[XTYP_WILDCONNECT](https://learn.microsoft.com/windows/desktop/dataxchg/xtyp-wildconnect) transaction.

## Return value

Type: **HCONVLIST**

If the function succeeds, the return value is the handle to a new conversation list.

If the function fails, the return value is 0L. The handle to the old conversation list is no longer valid.

The [DdeGetLastError](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddegetlasterror) function can be used to get the error code, which can be one of the following values:

## Remarks

An application must free the conversation list handle returned by the **DdeConnectList** function, regardless of whether any conversation handles within the list are active. To free the handle, an application can call [DdeDisconnectList](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddedisconnectlist).

All members of the default [CONVCONTEXT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convcontext) structure are set to zero except
*cb*, specifying the size of the structure, and
*iCodePage*, specifying **CP_WINANSI** (the default code page) or **CP_WINUNICODE**, depending on whether the ANSI or Unicode version of the [DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea) function was called by the client application.

## See also

[CONVCONTEXT](https://learn.microsoft.com/windows/desktop/api/ddeml/ns-ddeml-convcontext)

**Conceptual**

[DdeConnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeconnect)

[DdeCreateStringHandle](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddecreatestringhandlea)

[DdeDisconnect](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddedisconnect)

[DdeDisconnectList](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddedisconnectlist)

[DdeInitialize](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddeinitializea)

[DdeQueryNextServer](https://learn.microsoft.com/windows/desktop/api/ddeml/nf-ddeml-ddequerynextserver)

[Dynamic Data Exchange Management Library](https://learn.microsoft.com/windows/desktop/dataxchg/dynamic-data-exchange-management-library)

**Reference**