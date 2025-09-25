## Description

**DXGKDDI_CREATECPUEVENT** creates the kernel-mode driver's (KMD's) CPU event object for the corresponding *Dxgkrnl* object.

## Parameters

### `hAdapter`

[in] Handle to a KMD context that is associated with a display adapter. The display miniport driver previously provided this handle to *Dxgkrnl* in the **MiniportDeviceContext** output parameter of the [**DXGKDDI_ADD_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `pArgs`

[in/out] Pointer to a [**DXGKARG_CREATECPUEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createcpuevent) structure with additional parameters.

## Return value

**DXGKDDI_CREATECPUEVENT** returns STATUS_SUCCESS if it succeeds; otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

KMD CPU event sync objects are linked with a device object (**hKmdDevice**). When a device object is destroyed, *Dxgkrnl* will destroy all associated KMD CPU event sync objects by calling [**DXGKDDI_DESTROYCPUEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroycpuevent).

KMD can signal the event by calling [**DXGKCB_SIGNALEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_signalevent) and providing the **hDxgCpuEvent** handle.

The CPU event object lifetime does not depend on KMD's device lifetime; that is, the object could be destroyed after the device is destroyed. **hKmdDevice** is passed so the driver can associate the KMD process objects (created by [**DXGKDDI_CREATEPROCESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess)) with the CPU event object.

See [Signaling a CPU event from KMD](https://learn.microsoft.com/windows-hardware/drivers/display/signaling-cpu-event-from-kmd) for more information.

## See also

[**DXGKARG_CREATECPUEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createcpuevent)

[**DXGKDDI_DESTROYCPUEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroycpuevent)