# PFN_MIRACAST_IO_CONTROL callback function

## Description

Called by the user-mode display driver to send the kernel-mode display miniport driver a synchronous I/O control request.The data type of this function is **PFN_MIRACAST_IO_CONTROL**.

## Parameters

### `hMiracastDeviceHandle` [in]

A handle that represents a Miracast device. The Miracast user-mode driver previously obtained this handle as the *hMiracastDeviceHandle* parameter in a call to the [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context) function.

### `HardwareAccess` [in]

A Boolean value that indicates whether this I/O control request from the user-mode display driver needs to flush all the pending GPU DMA buffers.

We don't recommend that the driver set this value to **TRUE** except when necessary, because flushing the GPU will create substantial processing overhead.

### `InputBufferSize` [in]

The size, in bytes, of the input buffer pointed to by *pInputBuffer*.

### `pInputBuffer` [in]

A pointer to the input buffer. The *InputBufferSize* parameter specifies the size of the buffer.

### `OutputBufferSize` [in]

The size, in bytes, of the output buffer pointed to by *pOutputBuffer*.

### `pOutputBuffer` [out]

A driver-supplied pointer to the output buffer. The *OutputBufferSize* parameter specifies the size of the buffer.

### `pBytesReturned` [out, optional]

An optional driver-supplied pointer to a **UINT**-type variable that holds the number of bytes that the display miniport driver returned.

## Return value

On success, the operating system returns **STATUS_SUCCESS**. Otherwise, the function returns an error code defined in the Ntstatus.h header.

## Remarks

If the Miracast user-mode driver calls **MiracastIoControl** when the operating system is starting a Miracast session, and if the calling thread is not the thread in which the operating system calls the [StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session) function, the operating system blocks the **MiracastIoControl** call until the Miracast start session is finished. If the user-mode driver calls **MiracastIoControl** in the same context as is used in the [CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context) or *StartMiracastSession* functions, the operating system will process the call.

If the Miracast user-mode driver calls **MiracastIoControl** when the operating system is stopping a Miracast session, and if the calling thread is not the thread in which the operating system calls the [StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session) function, the operating system will fail this call. If the user-mode driver calls **MiracastIoControl** in the same context as is used in the *StopMiracastSession* or [DestroyMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_destroy_miracast_context) functions, the operating system will process the call.

## See also

[CreateMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_create_miracast_context)

[DestroyMiracastContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_destroy_miracast_context)

[StartMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_start_miracast_session)

[StopMiracastSession](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_stop_miracast_session)