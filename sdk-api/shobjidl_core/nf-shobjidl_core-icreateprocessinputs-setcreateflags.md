# ICreateProcessInputs::SetCreateFlags

## Description

 Set the flags that will be included in the call to [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa).

## Parameters

### `dwCreationFlags` [in]

The flags that will be passed to the *dwCreationFlags* parameter to [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa).

## Return value

 **S_OK** if the method succeeds. Otherwise, an **HRESULT** error code.

## Remarks

 Any flags set by a previous call to [AddCreateFlags](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icreateprocessinputs-addcreateflags) or **SetCreateFlags**  will be replaced by the values specified by *dwCreationFlags*. Use **AddCreateFlags** to set flags without clearing flags that are already set.

## See also

[AddCreateFlags](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icreateprocessinputs-addcreateflags)

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[ICreateProcessInputs](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icreateprocessinputs)

[ICreatingProcess::OnCreating](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icreatingprocess-oncreating)

[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa)