## Description

*Dxgkrnel* calls **DxgkDdiDestroyHwQueue** to have the kernel-mode display driver (KMD) perform the work to destroy a hardware queue.

## Parameters

### `hHwQueue`

[in] Handle to the queue to be destroyed.

## Return value

**DxgkDdiDestroyHwQueue** returns STATUS_SUCCESS if KMD was able to successfully destroy the hardware queue. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

**DxgkDdiDestroyHwQueue**'s [WDDM synchronization class is Zero level](https://learn.microsoft.com/windows-hardware/drivers/display/threading-and-synchronization-zero-level).

## See also

[**DxgkDdiCreateHwQueue**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createhwqueue)