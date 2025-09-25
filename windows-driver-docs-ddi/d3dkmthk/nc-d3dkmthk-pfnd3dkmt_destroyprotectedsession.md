# PFND3DKMT_DESTROYPROTECTEDSESSION callback function

## Description

Implemented by the client driver to destroy a protected session.

## Syntax

```cpp
PFND3DKMT_DESTROYPROTECTEDSESSION PfnD3dkmtDestroyProtectedSession;

NTSTATUS PfnD3dkmtDestroyProtectedSession(
    D3DKMT_DESTROYPROTECTEDSESSION *unnamedParam1
)
{...}
```

## Parameters

### `unnamedParam1`

Pointer to a [D3DKMT_DESTROYPROTECTEDSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyprotectedsession) structure that contains the information needed to destroy a protected session.

## Return value

The method returns **STATUS_SUCCESS** if the operation succeeds. Otherwise, this method might return an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** error code.

## Remarks

Register your implementation of this callback function by setting the appropriate member of [D3DKMT_DESTROYPROTECTEDSESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_destroyprotectedsession) and then calling **PfnD3dkmtDestroyProtectedSession**.