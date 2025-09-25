# PFND3DKMT_OPENKEYEDMUTEXFROMNTHANDLE callback function

## Description

Implemented by the client driver to open a keyed mutex from an NT handle to the process.

## Syntax

```cpp
PFND3DKMT_OPENKEYEDMUTEXFROMNTHANDLE PfnD3dkmtOpenKeyedMutexFromNtHandle;

NTSTATUS PfnD3dkmtOpenKeyedMutexFromNtHandle(
    D3DKMT_OPENKEYEDMUTEXFROMNTHANDLE *unnamedParam1
)
{...}
```

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_OPENKEYEDMUTEXFROMNTHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openkeyedmutexfromnthandle) structure that contains information to open a keyed mutex from NT handle.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

Register your implementation of this callback function by setting the appropriate member of [D3DKMT_OPENKEYEDMUTEXFROMNTHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_openkeyedmutexfromnthandle) and then calling **PfnD3dkmtOpenKeyedMutexFromNtHandle**.