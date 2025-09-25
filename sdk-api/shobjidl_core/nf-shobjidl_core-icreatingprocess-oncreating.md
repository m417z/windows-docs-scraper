# ICreatingProcess::OnCreating

## Description

Allows you to modify the parameters of the process being created.

## Parameters

### `pcpi` [in]

 A pointer to an [ICreateProcessInputs](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icreateprocessinputs) interface which allows you to set some parameters for the process that is being created.

## Return value

 **S_OK** if the method succeeds. Otherwise, an **HRESULT** error code, and the process is not created.

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[ICreatingProcess](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icreatingprocess)