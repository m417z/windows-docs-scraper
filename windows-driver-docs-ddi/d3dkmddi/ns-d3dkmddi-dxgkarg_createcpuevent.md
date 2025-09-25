## Description

The **DXGKARG_CREATECPUEVENT** structure is an argument passed to [**DXGKDDI_CREATECPUEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcpuevent) to create a kernel-mode driver's (KMD's) CPU event object for a corresponding *Dxgkrnl* object.

## Members

### `hKmdDevice`

[in] The KMD device handle, returned from [**DXGKDDI_CREATEDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice).

### `hDxgCpuEvent`

[in] *Dxgkrnl*'s CPU event sync object handle. KMD needs to pass this handle to [**DXGKCB_SIGNALEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_signalevent).

### `Flags`

[in] A [**DXGK_CREATECPUEVENTFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_createcpueventflags) structure specifying creation flags.

### `hKmdCpuEvent`

[out] Handle to the created KMD CPU event object.

## Remarks

See [Signaling a CPU event from KMD](https://learn.microsoft.com/windows-hardware/drivers/display/signaling-cpu-event-from-kmd) for more information.

## See also

[**DXGKCB_SIGNALEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_signalevent)

[**DXGKDDI_CREATECPUEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcpuevent)

[**DXGKDDI_CREATEDEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdevice)