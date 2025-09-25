## Description

*Dxgkrnl* calls **DxgkDdiUpdateMonitoredValues** to instruct the kernel-mode display driver (KMD) to update a batch of monitored values.

## Parameters

### `pUpdateMonitoredValues`

[in] Pointer to a [**DXGKARG_UPDATEMONITOREDVALUES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_updatemonitoredvalues) structure that contains the monitored values to update.

## Return value

**DxgkDdiUpdateMonitoredValues** returns STATUS_SUCCESS if KMD was able to successfully update the batch of monitored values. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

**DxgkDdiUpdateMonitoredValues** executes at the device interrupt level and is thus synchronized with the monitored fence signaled interrupt service routine (ISR).

A KMD's **DxgkDdiUpdateMonitoredValues** implementation must guarantee that the [**CurrentValue**](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects) read by any processor core after the call returns was written by the GPU context management processor after having observed the new [**MonitoredValue**](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

**DxgkDdiUpdateMonitoredValues** is expected to write the **UpdatedValueArray** values to the location specified by **MonitoredValueGpuVa** while honoring the synchronization contract.

The OS only guarantees that the **MonitoredValueKernelCpuVa** pointer is valid for the duration of this DDI call, and not before or after it. Hence, KMD must never cache this pointer for use it elsewhere.

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGKARG_UPDATEMONITOREDVALUES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_updatemonitoredvalues)