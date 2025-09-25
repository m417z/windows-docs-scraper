# DXGKDDI_MIRACAST_HANDLE_IO_CONTROL callback function

## Description

Called by the operating system to request that the display miniport driver process a synchronous I/O control request in response to a user-mode display driver call to the [MiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_miracast_io_control) function.

## Parameters

### `DriverContext` [in]

A handle to a context block that is associated with a display adapter. The display miniport driver's [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function previously provided this handle to the DirectX graphics kernel subsystem.

### `MiracastContext` [in]

The Miracast device context, supplied by the operating system. This context was provided by the display miniport driver in a call to the [DxgkDdiMiracastCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_create_context) function.

### `InputBufferSize` [in]

Supplied by the operating system as the size, in bytes, of the input buffer pointed to by *pInputBuffer*. This value originated as the user-mode [MiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_miracast_io_control) function's *InputBufferSize* parameter.

### `pInputBuffer` [in]

Supplied by the operating system as a pointer to the input buffer. This value originated as the user-mode [MiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_miracast_io_control) function's *InputBufferSize* parameter.

*InputBufferSize* specifies the size of the buffer.

### `OutputBufferSize` [in]

Supplied by the operating system as the size, in bytes, of the output buffer pointed to by *pOutputBuffer*.

This value originated as the user-mode [MiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_miracast_io_control) function's *OutputBufferSize* parameter.

### `pOutputBuffer` [out]

Supplied by the operating system as a pointer to the output buffer. This value originated as the user-mode [MiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_miracast_io_control) function's *pOutputBuffer* parameter.

*OutBufferSize* specifies the size of the buffer.

### `BytesReturned` [out]

Supplied by the operating system as a pointer to a buffer that holds a **ULONG**-type value that is the number of bytes that the display miniport driver returned in the buffer pointed to by *pOutputBuffer*.

## Return value

Returns **STATUS_SUCCESS** if it succeeds. Otherwise, it returns one of the error codes that are defined in Ntstatus.h.

## Remarks

The operating system guarantees that a call to *DxgkDdiMiracastIoControl* occurs in the same process space as the user-mode [MiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_miracast_io_control) request is called in.

Even though the operating system merely copies the values of the input and output buffer sizes from the respective parameters of [MiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_miracast_io_control), the display miniport driver is responsible for checking buffer sizes before using the buffers. Also, the driver should perform probing operations within a try/except calling block, using [ProbeForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-probeforread) and/or [ProbeForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-probeforwrite) functions, to verify any user-mode memory that input buffers point to.

This I/O control operation is processed synchronously with a call to the user-mode [MiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_miracast_io_control) function.

### Synchronization

The operating system groups the [DxgkDdiMiracastCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_create_context), [DxgkDdiMiracastDestroyContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_destroy_context), and *DxgkDdiMiracastIoControl* functions as a *Miracast* class.

The threading and synchronization level for this function is set by how the user-mode driver sets the *HardwareAccess* parameter in a call to the [MiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_miracast_io_control) function:

* If *HardwareAccess* is **FALSE**, then the operating system guarantees that *DxgkDdiMiracastIoControl* follows the second-level synchronization mode as defined in [Threading and Synchronization Second Level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-second-level). *DxgkDdiMiracastIoControl* can be called when other level 0, 1, or non-Miracast classes of level 2 functions are being called on another thread context. However, only one of the level 2 Miracast-class functions can be called at a time.
* If *HardwareAccess* is **TRUE**, then *DxgkDdiMiracastIoControl* follows the third-level synchronization mode as defined in [Threading and Synchronization Third Level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-third-level). Note that the flushing of the GPU will create substantial processing overhead.

## See also

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)

[DxgkDdiMiracastCreateContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_miracast_create_context)

[MiracastIoControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/netdispumdddi/nc-netdispumdddi-pfn_miracast_io_control)

[ProbeForRead](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-probeforread)

[ProbeForWrite](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-probeforwrite)