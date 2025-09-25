# IWorkspaceResTypeRegistry::DeleteResourceType

## Description

Unregisters a third-party file name extension with the RemoteApp and Desktop Connections
runtime.

## Parameters

### `fMachineWide` [in]

Specifies whether the resource is registered per user or per machine.

#### VARIANT_TRUE

The resource is registered per machine.

#### VARIANT_FALSE

The resource is registered per user.

### `bstrFileExtension` [in]

A string that contains the file name extension to unregister. The period must be included in the extension,
for example, ".txt".

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called when the plug-in is uninstalled to unregister non-RDP resources.

## See also

[IWorkspaceResTypeRegistry](https://learn.microsoft.com/windows/desktop/api/workspaceax/nn-workspaceax-iworkspacerestyperegistry)