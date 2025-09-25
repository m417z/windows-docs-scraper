# PFND3DKMT_QUERYPROTECTEDSESSIONSTATUS callback function

## Description

Implemented by the client driver to query a protected session.

## Syntax

```cpp
PFND3DKMT_QUERYPROTECTEDSESSIONSTATUS PfnD3dkmtQueryProtectedSessionStatus;

NTSTATUS PfnD3dkmtQueryProtectedSessionStatus(
    D3DKMT_QUERYPROTECTEDSESSIONSTATUS *
)
{...}
```

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_QUERYPROTECTEDSESSIONSTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryprotectedsessionstatus) structure.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

Register your implementation of this callback function by setting the appropriate member of [D3DKMT_QUERYPROTECTEDSESSIONSTATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_queryprotectedsessionstatus) and then calling **PfnD3dkmtQueryProtectedSessionStatus**.