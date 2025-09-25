# ICreateProcessInputs::SetEnvironmentVariable

## Description

Sets a variable in the environment of the created process.

## Parameters

### `pszName` [in]

 A null-terminated string specifying the name of a variable to be set in the environment of the process to be created. This parameter may not be **NULL**.

### `pszValue` [in]

 A null-terminated string specifying the value of the variable to be set in the environment of the process to be created. his parameter may not be **NULL**.

## Return value

 **S_OK** if the method succeeds. Otherwise, an **HRESULT** error code.

## Remarks

If a variable with the same name already exists in the environment of the created process, it is replaced.

## See also

[ICreateProcessInputs](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icreateprocessinputs)

[ICreatingProcess::OnCreating](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icreatingprocess-oncreating)