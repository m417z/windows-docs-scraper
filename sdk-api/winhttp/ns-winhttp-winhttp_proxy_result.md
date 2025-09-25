# WINHTTP_PROXY_RESULT structure

## Description

The **WINHTTP_PROXY_RESULT** structure contains collection of proxy result entries provided by [WinHttpGetProxyResult](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyresult).

## Members

### `cEntries`

The number of entries in the **pEntries** array.

### `pEntries`

A pointer to an array of [WINHTTP_PROXY_RESULT_ENTRY](https://learn.microsoft.com/windows/desktop/api/winhttp/ns-winhttp-winhttp_proxy_result_entry) structures.

## See also

[WINHTTP_PROXY_RESULT_ENTRY](https://learn.microsoft.com/windows/desktop/api/winhttp/ns-winhttp-winhttp_proxy_result_entry)

[WinHttpFreeProxyResult](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpfreeproxyresult)

[WinHttpGetProxyResult](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpgetproxyresult)