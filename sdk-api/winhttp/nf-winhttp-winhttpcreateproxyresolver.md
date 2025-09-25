# WinHttpCreateProxyResolver function

## Description

The **WinHttpCreateProxyResolver** function creates a handle for use by [WinHttpGetProxyForUrlEx](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurlex).

## Parameters

### `hSession` [in]

Valid [HINTERNET](https://learn.microsoft.com/windows/desktop/WinHttp/hinternet-handles-in-winhttp) WinHTTP session handle returned by a previous call to
[WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen). The session handle must be opened using **WINHTTP_FLAG_ASYNC**.

### `phResolver` [out]

A pointer to a new handle for use by [WinHttpGetProxyForUrlEx](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurlex). When finished or cancelling an outstanding operation, close this handle with [WinHttpCloseHandle](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpclosehandle).

## Return value

A status code indicating the result of the operation.

| The following codes may be returned. | Description |
| --- | --- |
| **ERROR_SUCCESS** | The operation succeeded. |
| **ERROR_INVALID_HANDLE** | *hSession* is NULL. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | *hSession* is not the result of a call to [WinHttpOpen](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpopen) or *hSession* is not marked as asynchronous using **WINHTTP_FLAG_ASYNC**. |