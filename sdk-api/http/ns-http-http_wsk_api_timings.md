## Description

Represents statistics on the time spent on specific API calls.

## Members

### `ConnectCount`

Tracks the number of times that **Connect** was called.

### `ConnectSum`

Tracks the number of ticks of the high-performance counter that have been spent in **Connect** calls for the socket.

### `DisconnectCount`

Tracks the number of times that **Disconnect** was called.

### `DisconnectSum`

Tracks the number of ticks of the high-performance counter that have been spent in **Disconnect** calls for the socket.

### `SendCount`

Tracks the number of times that **Send** was called.

### `SendSum`

Tracks the number of ticks of the high-performance counter that have been spent in **Send** calls for the socket.

### `ReceiveCount`

Tracks the number of times that **Receive** was called.

### `ReceiveSum`

Tracks the number of ticks of the high-performance counter that have been spent in **Receive** calls for the socket.

### `ReleaseCount`

Tracks the number of times that **Release** was called.

### `ReleaseSum`

Tracks the number of ticks of the high-performance counter that have been spent in **Release** calls for the socket.

### `ControlSocketCount`

Tracks the number of times that **ControlSocket** was called.

### `ControlSocketSum`

Tracks the number of ticks of the high-performance counter that have been spent in **ControlSocket** calls for the socket.

## Remarks

`Http.sys` can provide statistics on the time spent on specific API calls as listed here. Since the gathering of statistics has a slight overhead in time and memory, there's a registry key that you'll need to set in order to enable using **HTTP_WSK_API_TIMINGS**. For more details, see the notes in [HTTP_REQUEST_PROPERTY](https://learn.microsoft.com/windows/win32/api/http/ne-http-http_request_property).

To check the actual duration of an HPC tick, see [QueryPerformanceFrequency](https://learn.microsoft.com/windows/win32/api/profileapi/nf-profileapi-queryperformancefrequency).

## See also