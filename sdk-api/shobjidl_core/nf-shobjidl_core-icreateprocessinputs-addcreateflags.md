# ICreateProcessInputs::AddCreateFlags

## Description

 Set additional flags that will be included in the call to [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa).

## Parameters

### `dwCreationFlags` [in]

The flags that will be included in the *dwCreationFlags* parameter passed to [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa).

## Return value

 **S_OK** if the method succeeds. Otherwise, an **HRESULT** error code.

## Remarks

Any creation flags that were previously set will remain set. This method does not clear any creation flags.

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[ICreateProcessInputs](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icreateprocessinputs)

[ICreatingProcess::OnCreating](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icreatingprocess-oncreating)

[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa)

[SetCreateFlags](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icreateprocessinputs-setcreateflags)