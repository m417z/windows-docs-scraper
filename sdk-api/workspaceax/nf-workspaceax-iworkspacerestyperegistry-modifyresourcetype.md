# IWorkspaceResTypeRegistry::ModifyResourceType

## Description

Modifies a third-party file name extension that is registered with the RemoteApp and Desktop Connections runtime.

## Parameters

### `fMachineWide` [in]

Specifies whether the resource is registered per user or per machine.

#### VARIANT_TRUE

The resource is registered per machine.

#### VARIANT_FALSE

The resource is registered per user.

### `bstrFileExtension` [in]

A string that contains the file name extension to update. The period must be included in the extension, for example, ".txt".

### `bstrLauncher` [in]

A string that contains the new fully qualified path and file name of the application to use to launch files with the extension specified by the *bstrFileExtension* parameter.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWorkspaceResTypeRegistry](https://learn.microsoft.com/windows/desktop/api/workspaceax/nn-workspaceax-iworkspacerestyperegistry)