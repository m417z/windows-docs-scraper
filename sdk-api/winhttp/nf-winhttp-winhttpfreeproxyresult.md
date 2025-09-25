## Description

Frees the data retrieved from a previous call to [WinHttpGetProxyResult](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyresult).

## Parameters

### `pProxyResult` [in, out]

A pointer to a [WINHTTP_PROXY_RESULT](https://learn.microsoft.com/windows/desktop/api/winhttp/ns-winhttp-winhttp_proxy_result) structure retrieved from a previous call to [WinHttpGetProxyResult](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyresult).

## Return value

This function does not return a value.

## Remarks

Upon completion, all internal members of *pProxyResult* will be zeroed and the memory allocated to those members will be freed. If *pProxyResult* is an allocated pointer, the caller must free the pointer.