# PFND3DKMT_QUERYPROTECTEDSESSIONINFOFROMNTHANDLE callback function

## Description

Implemented by the client driver to query protected session info from NT handle.

## Syntax

```cpp
PFND3DKMT_QUERYPROTECTEDSESSIONINFOFROMNTHANDLE PfnD3dkmtQueryProtectedSessionInfoFromNtHandle;

NTSTATUS PfnD3dkmtQueryProtectedSessionInfoFromNtHandle(
    D3DKMT_QUERYPROTECTEDSESSIONINFOFROMNTHANDLE *
)
{...}
```

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_QUERYPROTECTEDSESSIONINFOFROMNTHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryprotectedsessioninfofromnthandle) structure.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

Register your implementation of this callback function by setting the appropriate member of [D3DKMT_QUERYPROTECTEDSESSIONINFOFROMNTHANDLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryprotectedsessioninfofromnthandle) and then calling **PfnD3dkmtQueryProtectedSessionInfoFromNtHandle**.