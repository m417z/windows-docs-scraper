# PFN_HANDLE_KMD_MESSAGE callback function

## Description

Called by the operating system to handle the asynchronous kernel-mode message that the Miracast user-mode driver receives when the display miniport driver calls the [DxgkCbMiracastSendMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_miracast_send_message) function.

## Parameters

### `pMiracastContext` [in]

A pointer to a context associated with a display adapter.

The operating system obtained the context when it called the Miracast user-mode driver's [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context) function.

### `InputBufferSize` [in]

The size of the input buffer *pInputBuffer*, supplied by the operating system.

### `pInputBuffer` [in]

A pointer to the input buffer, supplied by the operating system.

### `OutputBufferSize` [in]

The size of the output buffer *pOutputBuffer*, supplied by the operating system.

### `pOutputBuffer` [out]

A pointer to the output buffer, supplied by the operating system.

### `pBytesReturned` [out]

A pointer to a buffer, supplied by the operating system, that holds the number of returned bytes that the display miniport driver wrote in *pOutputBuffer*.

## Return value

On success, this function returns **STATUS_SUCCESS**. Otherwise, the function returns an error code defined in the Ntstatus.h header.

## Remarks

#### Thread Safety

When this function is called, it's possible that it has also been called in another thread. The driver is therefore responsible for synchronizing multiple calls to *HandleKernelModeMessage* if necessary.

The operating system guarantees that this function is not called when [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context), [DestroyMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_destroy_miracast_context), [StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session), and [StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session) are called. All the messages that the display miniport driver sends during the startup of a Miracast connected session (*StartMiracastSession*) are blocked until the session startup process has completed. The operating system also blocks all messages that the display miniport driver sends during or after a call to stop the Miracast session (*StopMiracastSession*).

## See also

[CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context)

[DestroyMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_destroy_miracast_context)

[DxgkCbMiracastSendMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkcb_miracast_send_message)

[StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session)

[StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session)