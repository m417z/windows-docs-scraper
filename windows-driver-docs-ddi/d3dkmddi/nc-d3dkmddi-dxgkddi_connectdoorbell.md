## Description

**DxgkDdiConnectDoorbell** connects (or reconnects) a [previously created doorbell object](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createdoorbell) to a hardware queue.

## Parameters

### `pArgs`

[in/out] Pointer to a [**DXGKARG_CONNECTDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_connectdoorbell) structure that describes the doorbell to connect.

## Return value

**DxgkDdiConnectDoorbell** returns STATUS_SUCCESS if KMD was able to successfully connect its doorbell object to the specified hardware queue. This call should not typically fail; however, a returned failure code would be from GPU lost or stopped kinds of irrecoverable scenarios.

## Remarks

When UMD calls [**D3DKMTConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtconnectdoorbell), the OS calls **DxgkDdiConnectDoorbell** so that the KMD can do the following:

* Provide a CPU virtual address mapped to the physical doorbell location.
* Make the required connections between the hardware queue object, doorbell object, doorbell physical address, GPU scheduler, and so forth.

On return from this DDI, KMD should consider this physical address as reserved for this particular hardware queue. However, the OS doesn't have a uniqueness requirement for the doorbell's physical address. That is, KMD can choose to share the same physical address with multiple logical doorbells/hardware queues depending on the hardware implementation. For example, some hardware might choose to assign the same physical address to all the hardware queues of a single hardware context. It's even possible that multiple logical doorbells share the same 4KB physical page but use a unique offset within the page.

For more information, see [User-mode work submission](https://learn.microsoft.com/windows-hardware/drivers/display/user-mode-work-submission).

## See also

[**D3DKMTConnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtconnectdoorbell)

[**DXGKARG_CONNECTDOORBELL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_connectdoorbell)

[**DxgkDdiCreateDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createdoorbell)

[**DxgkDdiDisconnectDoorbell**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_disconnectdoorbell)