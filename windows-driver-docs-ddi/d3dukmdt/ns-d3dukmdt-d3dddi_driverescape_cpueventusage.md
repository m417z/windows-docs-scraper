## Description

The **D3DDDI_DRIVERESCAPE_CPUEVENTUSAGE** structure defines the kernel-mode driver (KMD) CPU event usage escape when notifying KMD about the intended usage of a KMD CPU event object.

## Members

### `EscapeType`

[in] A [**D3DDDI_DRIVERESCAPETYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-_d3dddi_driverescapetype). Must be set to **D3DDDI_DRIVERESCAPETYPE_CPUEVENTUSAGE**.

### `hSyncObject`

[in] CPU event synchronization object handle, returned from [**D3DKMTCreateSynchronizationObject2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatesynchronizationobject2).

### `hKmdCpuEvent`

[in] Handle that KMD returned from [**DXGKDDI_CREATECPUEVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createcpuevent)

### `Usage[8]`

Driver-defined usage for the synchronization object.

## Remarks

See [Signaling a CPU event from KMD](https://learn.microsoft.com/windows-hardware/drivers/display/signaling-cpu-event-from-kmd) for more information and sample code.

## See also

[**DXGKARG_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_escape)

[**DXGKDDI_ESCAPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_escape)