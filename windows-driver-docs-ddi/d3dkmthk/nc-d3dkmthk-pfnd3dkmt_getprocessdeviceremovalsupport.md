# PFND3DKMT_GETPROCESSDEVICEREMOVALSUPPORT callback function

## Description

Implemented by the client driver to get process device removal support.

## Syntax

```cpp
PFND3DKMT_GETPROCESSDEVICEREMOVALSUPPORT PfnD3dkmtGetProcessDeviceRemovalSupport;

NTSTATUS PfnD3dkmtGetProcessDeviceRemovalSupport(
    D3DKMT_GETPROCESSDEVICEREMOVALSUPPORT *unnamedParam1
)
{...}
```

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_GETPROCESSDEVICEREMOVALSUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getprocessdeviceremovalsupport) structure that contains the information needed to get process device removal support.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

Register your implementation of this callback function by setting the appropriate member of [D3DKMT_GETPROCESSDEVICEREMOVALSUPPORT](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_getprocessdeviceremovalsupport) and then calling **PfnD3dkmtGetProcessDeviceRemovalSupport**.