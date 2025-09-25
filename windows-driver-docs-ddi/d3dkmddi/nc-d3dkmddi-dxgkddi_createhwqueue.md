## Description

*Dxgkrnl* calls **DxgkDdiCreateHwQueue** to have the kernel-mode display driver (KMD) perform the work to create a hardware queue.

## Parameters

### `hHwContext`

[in] The hardware context handle that the hardware queue belongs to.

### `pCreateHwQueue`

[in/out] A pointer to a [**DXGKARG_CREATEHWQUEUE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createhwqueue) structure that describes the hardware queue to create.

## Return value

**DxgkDdiCreateHwQueue** returns STATUS_SUCCESS if KMD was able to successfully create a hardware queue. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

**DxgkDdiCreateHwQueue**'s [WDDM synchronization class is Zero level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-zero-level).

## See also

[**DXGKARG_CREATEHWQUEUE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_createhwqueue)

[**DxgkDestroyHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroyhwqueue)