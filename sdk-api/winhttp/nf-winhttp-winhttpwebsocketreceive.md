# WinHttpWebSocketReceive function

## Description

The **WinHttpWebSocketReceive** function receives data from a WebSocket connection.

## Parameters

### `hWebSocket` [in]

Type: **HINTERNET**

Handle to a WebSocket.

### `pvBuffer` [out]

Type: **PVOID**

Pointer to a buffer to receive the data.

### `dwBufferLength` [in]

Type: **DWORD**

Length of *pvBuffer*, in bytes.

### `pdwBytesRead` [out]

Type: **DWORD***

Pointer to a **DWORD** that receives the number of bytes read from the connection at the end of the operation. This is set only if **WinHttpWebSocketReceive** returns **NO_ERROR** and the handle was opened in synchronous mode.

### `peBufferType` [out]

Type: **[WINHTTP_WEB_SOCKET_BUFFER_TYPE](https://learn.microsoft.com/windows/desktop/api/winhttp/ne-winhttp-winhttp_web_socket_buffer_type)***

The type of a returned buffer. This is only set if **WinHttpWebSocketReceive** returns **NO_ERROR** and the handle was opened in synchronous mode.

## Return value

Type: **DWORD**

**NO_ERROR** on success. Otherwise an error code.

|  | Description |
| --- | --- |
| **ERROR_INVALID_OPERATION** | A close or receive is pending, or the receive channel has already been closed. |
| **ERROR_INVALID_PARAMETER** | A parameter is invalid. |
| **ERROR_WINHTTP_INVALID_SERVER_RESPONSE** | Invalid data was received from the server. |
| **ERROR_WINHTTP_OPERATION_CANCELLED** | The operation was cancelled because [WinHttpWebSocketClose](https://learn.microsoft.com/windows/desktop/api/winhttp/nf-winhttp-winhttpwebsocketclose) was called to close the connection. |