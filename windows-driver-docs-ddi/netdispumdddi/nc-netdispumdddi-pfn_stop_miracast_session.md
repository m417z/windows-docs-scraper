# PFN_STOP_MIRACAST_SESSION callback function

## Description

Called by the operating system to start a Miracast connected session that had earlier been started by a call to the [StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session) function.

## Parameters

### `pMiracastContext` [in]

A pointer to a context associated with a display adapter.

The operating system obtained the context when it called the Miracast user-mode driver's [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context) function.

## Remarks

When this function is called, the Miracast user-mode driver should follow these procedures:

1. It should not notify the display miniport driver to remove the Miracast monitor unless it knows that the monitor has been physically removed from the remote side.
2. It should return as quickly as possible to avoid blocking system plug and play (PnP) or power operations.
3. It should stop all communications and close all sockets that it created, but it should not close the Real-Time Streaming Protocol (RTSP) socket that was passed by the operating system.

Also, after this function is called, the Miracast user-mode driver might still receive stream data that the display miniport driver generated. The user-mode driver should drop the stream.

#### Thread Safety

The operating system guarantees that only one of the [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context), [DestroyMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_destroy_miracast_context), [StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session), and *StopMiracastSession* functions is called at a time.

## See also

[CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context)

[DestroyMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_destroy_miracast_context)

[StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session)