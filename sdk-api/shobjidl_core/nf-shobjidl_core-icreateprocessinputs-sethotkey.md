# ICreateProcessInputs::SetHotKey

## Description

Sets the hot key for the application.

## Parameters

### `wHotKey` [in]

The hotkey to assign to the application. See the documentation of the **hStdIn** member of the [STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) structure for more information.

## Return value

 **S_OK** if the method succeeds. Otherwise, an **HRESULT** error code.

## Remarks

 This method also sets the **STARTF_USEHOTKEY** flag in the **dwFlags** member of the [STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa) structure passed to [CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa).

## See also

[CreateProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createprocessa)

[ICreateProcessInputs](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icreateprocessinputs)

[ICreatingProcess::OnCreating](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icreatingprocess-oncreating)

[STARTUPINFO](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/ns-processthreadsapi-startupinfoa)