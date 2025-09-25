# WinHttpWebSocketCompleteUpgrade function

## Description

The **WinHttpWebSocketCompleteUpgrade** function completes a WebSocket handshake started by [WinHttpSendRequest](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsendrequest).

## Parameters

### `hRequest` [in]

Type: **HINTERNET**

HTTP request handle used to send a WebSocket handshake.

### `pContext` [in, optional]

Type: **DWORD_PTR**

Context to be associated with the new handle.

## Return value

Type: **HINTERNET**

A new WebSocket handle. If NULL, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to determine the cause of failure.

## Remarks

**WinHttpWebSocketCompleteUpgrade** can be called on an open HTTP request to get a WebSocket handle for performing other WebSocket operations.

The request handle must be marked as a WebSocket upgrade by calling [WinHttpSetOption](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpsetoption) with **WINHTTP_OPTION_UPGRADE_TO_WEB_SOCKET** before sending the request.

The caller should check the HTTP status code returned by the server and call this function only if the status code was 101. Calling it with any other status code will result in a failure.