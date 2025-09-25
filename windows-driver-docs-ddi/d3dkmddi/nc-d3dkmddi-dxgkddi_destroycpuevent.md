## Description

**DXGKDDI_DESTROYCPUEVENT** destroys the specified kernel-mode driver (KMD) CPU object.

## Parameters

### `hAdapter`

[in] Handle to a KMD context that is associated with a display adapter. The display miniport driver previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DXGKDDI_ADD_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `hKmdCpuEvent`

[in] KMD CPU event object handle, which was returned by KMD from [**DXGKDDI_CREATECPUEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcpuevent).

## Return value

**DXGKDDI_DESTROYCPUEVENT** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

The *Dxgkrnl* CPU event object cannot be used after this DDI is called. The driver must synchronize destruction with all calls to [**DXGKCB_SIGNALEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_signalevent).

It is guaranteed that the OS will call this DDI to destroy KMD sync objects. Objects could be destroyed when a user-mode client destroys a sync object, when a process terminates, or when the adapter is stopped.

See [Signaling a CPU event from KMD](https://learn.microsoft.com/windows-hardware/drivers/display/signaling-cpu-event-from-kmd) for more information.

## See also

[**DXGKDDI_CREATECPUEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcpuevent)