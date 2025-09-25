# ICreateProcessInputs::GetCreateFlags

## Description

Gets the additional flags that will be passed to [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa).

## Parameters

### `pdwCreationFlags` [out]

 A pointer to a **DWORD** which receives the flags that will be passed as the *dwCreationFlags* parameter to [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa).

## Return value

 **S_OK** if the method succeeds. Otherwise, an **HRESULT** error code.

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[ICreateProcessInputs](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icreateprocessinputs)

[ICreatingProcess::OnCreating](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icreatingprocess-oncreating)