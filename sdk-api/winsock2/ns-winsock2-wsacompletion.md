# WSACOMPLETION structure

## Description

The **WSACOMPLETION** structure specifies completion notification settings for I/O control calls made to a registered namespace.

## Members

### `Type`

Type: **WSACOMPLETIONTYPE**

The type of completion notification required. See Remarks.

### `Parameters`

The parameters required to complete the callback. The structures within the Parameters union specify information required for completing the callback of each given type. For example, the **WindowMessage** structure must be filled when **Type** is set to NSP_NOTIFY_HWND.

### `Parameters.WindowMessage`

### `Parameters.WindowMessage.hWnd`

Type: **HWND**

Windows handle.

### `Parameters.WindowMessage.uMsg`

Type: **UINT**

Message handle.

### `Parameters.WindowMessage.context`

Type: **WPARAM**

Context of the message or handle.

### `Parameters.Event`

### `Parameters.Event.lpOverlapped`

Type: **LPWSAOVERLAPPED**

A pointer to a [WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure.

### `Parameters.Apc`

### `Parameters.Apc.lpOverlapped`

Type: **LPWSAOVERLAPPED**

A pointer to a [WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure.

### `Parameters.Apc.lpfnCompletionProc`

Type: \_In_opt\_ [**LPWSAOVERLAPPED_COMPLETION_ROUTINE**](https://learn.microsoft.com/windows/win32/api/winsock2/nc-winsock2-lpwsaoverlapped_completion_routine)

A pointer to an application-provided completion routine.

### `Parameters.Port`

### `Parameters.Port.lpOverlapped`

Type: **LPWSAOVERLAPPED**

A pointer to a [WSAOVERLAPPED](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaoverlapped) structure.

### `Parameters.Port.hPort`

Type: **HANDLE**

A handle to the port.

### `Parameters.Port.Key`

Type: **ULONG_PTR**

A pointer to the key.

## Remarks

The **WSACOMPLETION** structure enables callbacks to be provided in any of the following formats, based on the value provided in **Type**:

| Callback Format | Type value |
| --- | --- |
| Polling | NSP_NOTIFY_IMMEDIATELY |
| Window Message | NSP_NOTIFY_HWND |
| Event | NSP_NOTIFY_EVENT |
| APC | NSP_NOTIFY_APC |
| Completion Port | NSP_NOTIFY_PORT |

For a blocking function, set the **WSACOMPLETION** structure to null.

## See also

[WSANSPIoctl](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsanspioctl)