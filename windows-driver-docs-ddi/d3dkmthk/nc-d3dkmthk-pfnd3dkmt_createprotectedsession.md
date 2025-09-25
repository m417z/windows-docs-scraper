# PFND3DKMT_CREATEPROTECTEDSESSION callback function

## Description

Implemented by the client driver to create a protected session.

## Syntax

```cpp
PFND3DKMT_CREATEPROTECTEDSESSION PfnD3dkmtCreateProtectedSession;

NTSTATUS PfnD3dkmtCreateProtectedSession(
    D3DKMT_CREATEPROTECTEDSESSION *unnamedParam1
)
{...}
```

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_CREATEPROTECTEDSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createprotectedsession) structure that contains the information needed to create a protected session.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS Values error code.

## Remarks

Register your implementation of this callback function by setting the appropriate member of [D3DKMT_CREATEPROTECTEDSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createprotectedsession) and then calling **PfnD3dkmtCreateProtectedSession**.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.