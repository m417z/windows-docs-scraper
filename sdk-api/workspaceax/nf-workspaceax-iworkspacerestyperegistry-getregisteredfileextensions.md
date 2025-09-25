# IWorkspaceResTypeRegistry::GetRegisteredFileExtensions

## Description

Retrieves the third-party file name extensions that are registered with the RemoteApp and Desktop Connections runtime.

## Parameters

### `fMachineWide` [in]

Specifies whether the resource is registered per user or per machine.

#### VARIANT_TRUE

The resource is registered per machine.

#### VARIANT_FALSE

The resource is registered per user.

### `psaFileExtensions` [out, retval]

The address of a pointer to a **SAFEARRAY** variable that receives an array of **BSTR**s that contain the registered file name extensions.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWorkspaceResTypeRegistry](https://learn.microsoft.com/windows/desktop/api/workspaceax/nn-workspaceax-iworkspacerestyperegistry)