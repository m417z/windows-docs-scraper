## Description

Adds one or more HTTP request headers to an HTTP request handle, allowing you to use separate name/value strings.

## Parameters

### `hRequest`

Type: IN **[HINTERNET](https://learn.microsoft.com/windows/win32/winhttp/hinternet-handles-in-winhttp)**

An **HINTERNET** handle returned by a call to [WinHttpOpenRequest](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpopenrequest).

### `dwModifiers`

Type: IN **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

An unsigned long integer value that contains the flags used to modify the semantics of this function. Can be one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **WINHTTP_ADDREQ_FLAG_ADD** | Adds the header if it does not exist. Used with **WINHTTP_ADDREQ_FLAG_REPLACE**. |
| **WINHTTP_ADDREQ_FLAG_ADD_IF_NEW** | Adds the header only if it does not already exist; otherwise, an error is returned. |
| **WINHTTP_ADDREQ_FLAG_COALESCE** | Merges headers of the same name. |
| **WINHTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA** | Merges headers of the same name using a comma. For example, adding "Accept: text/*" followed by "Accept: audio/*" with this flag results in a single header "Accept: text/*, audio/*". This causes the first header found to be merged. The calling application must to ensure a cohesive scheme with respect to merged and separate headers. |
| **WINHTTP_ADDREQ_FLAG_COALESCE_WITH_SEMICOLON** | Merges headers of the same name using a semicolon. |
| **WINHTTP_ADDREQ_FLAG_REPLACE** | Replaces or removes a header. If the header value is empty and the header is found, it is removed. If the value is not empty, it is replaced. |

### `ullFlags`

Type: IN **[ULONGLONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Pass **WINHTTP_EXTENDED_HEADER_FLAG_UNICODE** to indicate that the strings passed in are Unicode strings.

### `ullExtra`

Type: IN **[ULONGLONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Reserved.

### `cHeaders`

Type: IN **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of elements in *pHeaders*.

### `pHeaders`

Type: \_In\_reads\_(cHeaders) **[WINHTTP_EXTENDED_HEADER](https://learn.microsoft.com/windows/win32/api/winhttp/ns-winhttp-winhttp_extended_header)\***

An array of **WINHTTP_EXTENDED_HEADER** structures.

## Return value

A status code indicating the result of the operation. Among the error codes returned are the following.

| Error Code | Description |
| --- | --- |
| **ERROR_WINHTTP_INCORRECT_HANDLE_STATE** | The requested operation cannot be performed because the handle supplied is not in the correct state. |
| **ERROR_WINHTTP_INCORRECT_HANDLE_TYPE** | The type of handle supplied is incorrect for this operation. |
| **ERROR_WINHTTP_INTERNAL_ERROR** | An internal error has occurred. |
| **ERROR_NOT_ENOUGH_MEMORY** | Not enough memory was available to complete the requested operation. |

## Remarks

## See also

* [About Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/win32/WinHttp/about-winhttp)
* [WinHTTP versions](https://learn.microsoft.com/windows/win32/WinHttp/winhttp-versions)
* [WinHttpOpenRequest](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpopenrequest)
* [WinHttpSendRequest](https://learn.microsoft.com/windows/win32/api/winhttp/nf-winhttp-winhttpsendrequest)