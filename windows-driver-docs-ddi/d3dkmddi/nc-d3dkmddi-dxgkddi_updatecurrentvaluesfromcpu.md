## Description

The OS calls **DxgkDdiUpdateCurrentValuesFromCpu** to update the **CurrentValue** of a batch of native fences from the CPU.

## Parameters

### `pUpdateCurrentValuesFromCpu`

[in] Pointer to a [**DXGKARG_UPDATECURRENTVALUESFROMCPU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_updatecurrentvaluesfromcpu) structure that contains the current values to update.

## Return value

## Remarks

 This DDI is used to support the existing "signal fence from CPU" API semantics. Instead of *Dxgkrnl* writing a new **CurrentValue**, the driver is asked to write to **CurrentValue** in order to give drivers an opportunity to insert any required pre-write synchronization/barriers. The OS synchronizes CPU-side updates and guarantees that the most up to date value is available to **DxgkDdiUpdateCurrentValuesFromCpu**. After updating **CurrentValue**, the driver must trigger the GPU to unblock hardware queues that were waiting on this fence and got unblocked with the update to **CurrentValue**.

In a nutshell the steps to be followed by the driver are:

``` pseudocode

for i = 1 : NumFences
  1. Insert pre-write memory barrier if required
  2. write new value to CurrentValueCpuVa
  3. trigger GPU to unblock any HwQueues that got unblocked by the updated CurrentValue
end
```

The OS only guarantees that the **CurrentValueKernelCpuVa** pointer is valid for the duration of this DDI call, and not before or after it. Hence, KMD must never cache this pointer for use elsewhere.

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**DXGKARG_UPDATECURRENTVALUESFROMCPU**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkarg_updatecurrentvaluesfromcpu)