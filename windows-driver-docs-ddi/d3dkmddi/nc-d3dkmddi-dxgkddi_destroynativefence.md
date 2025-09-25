## Description

The OS calls KMD's **DxgkDdiDestroyNativeFence** to destroy a tracking object for a native GPU fence.

## Parameters

### `pDestroyNativeFence`

[in/out] Pointer to a [**DXGKARG_DESTROYNATIVEFENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_destroynativefence) structure that describes the native GPU fence object to destroy.

## Return value

**DxgkDdiDestroyNativeFence** returns STATUS_SUCCESS if KMD was able to successfully destroy the native GPU fence object. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

The OS calls **DxgkDdiDestroyNativeFence** to instruct the KMD to destroy the driver tracking object for a given native GPU fence. After the call returns, the OS will deallocate storage for **CurrentValue** and **MonitoredValue**.

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGKARG_DESTROYNATIVEFENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_destroynativefence)

[**DxgkDdiCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createnativefence)