# PFN_START_MIRACAST_SESSION callback function

## Description

Called by the operating system to start a Miracast connected session.

## Parameters

### `pMiracastContext` [in]

A pointer to a context associated with a display adapter.

The operating system obtained the context when it called the Miracast user-mode driver's [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context) function.

### `MiracastRTSPSocket` [in]

The operating system-supplied network socket handle of the Real Time Streaming Protocol (RTSP).

**Note** The Miracast user-mode driver should not close this socket. When the [StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session) function is called, the operating system will close this socket.

### `pWfdConnectionStats` [in]

A pointer to a [MIRACAST_WFD_CONNECTION_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_wfd_connection_stats) structure that indicates the Wi-Fi Direct connection statistics.

### `pSessionInfo` [out]

A pointer to a [MIRACAST_SESSION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_session_info) structure that the Miracast user-mode driver should complete after it has obtained the capabilities of the Miracast sink.

## Return value

On success, this function returns **STATUS_SUCCESS**. Otherwise, the function returns an error code defined in the Ntstatus.h header, including the following:

|Return code|Description|
|--- |--- |
|STATUS_DEVICE_INSUFFICIENT_RESOURCES|The current suggested encode rate cannot sustain a Miracast sink that supports more than 1024 x 768 pixels.|

## Remarks

When this function is called, the Miracast user-mode driver should start communicating with the Miracast sink using the Miracast protocol. The driver should gather the capabilities of the sink and the attributes of the monitor that's connected to the sink. The driver should perform enough of the negotiation with the sink to determine whether a monitor is connected to the sink or not. If the driver determines that a monitor is connected to the sink, it should also determine whether the current suggested bit rate is high enough to at least support the lowest sink supported mode of 1024 x 768 pixels.

The driver should also set the value of these members of [MIRACAST_SESSION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_session_info) pointed to by *pSessionInfo* in these cases:

#### Thread Safety

The operating system guarantees that only one of the [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context), [DestroyMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_destroy_miracast_context), *StartMiracastSession*, and [StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session) functions is called at a time.

## See also

[CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context)

[DestroyMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_destroy_miracast_context)

[MIRACAST_SESSION_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_session_info)

[MIRACAST_WFD_CONNECTION_STATS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/ns-netdispumdddi-miracast_wfd_connection_stats)

[StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session)