## Description

The **D3DDDI_NATIVEFENCEMAPPING** structure contains native GPU fence address mappings in the caller's process address space.

## Members

### `CurrentValueCpuVa`

Read-only mapping of the current value for the CPU. This value is is used by user-mode components to poll the native fence [*CurrentValue*](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

### `CurrentValueGpuVa`

Read/write mapping of the current value for the GPU in the current process's address space. This value is used by the GPU engine to read or write to the native fence *CurrentValue* as a fence signal operation.

### `MonitoredValueGpuVa`

Read/write mapping of the monitored value for the GPU in the current process's address space. This value is used by the GPU engine to check whether a conditional CPU interrupt should be raised.

### `Reserved[32]`

Reserved for system use.

## Remarks

For more information about native GPU fences, see [Native GPU fence objects](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects).

## See also

[**D3DDDI_NATIVEFENCEINFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ns-d3dukmdt-d3dddi_nativefenceinfo)

[**D3DKMT_CREATENATIVEFENCE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-d3dkmt_createnativefence)

[**D3DKMTCreateNativeFence**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatenativefence)