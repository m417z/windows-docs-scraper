# WinHttpGetProxyResult function

## Description

The **WinHttpGetProxyResult** function retrieves the results of a call to [WinHttpGetProxyForUrlEx](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurlex).

## Parameters

### `hResolver` [in]

The resolver handle used to issue a previously completed call to [WinHttpGetProxyForUrlEx](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurlex).

### `pProxyResult` [out]

A pointer to a [WINHTTP_PROXY_RESULT](https://learn.microsoft.com/windows/desktop/api/winhttp/ns-winhttp-winhttp_proxy_result) structure that contains the results of a previous call to [WinHttpGetProxyForUrlEx](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurlex). The results must be freed by calling [WinHttpFreeProxyResult](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpfreeproxyresult).

## Return value

A status code indicating the result of the operation.

| The following codes may be returned. | Description |
| --- | --- |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_STATE** | The resolver handle has not successfully completed a call to [WinHttpGetProxyForUrlEx](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyforurlex). |