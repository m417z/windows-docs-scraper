# ISuspensionDependencyManager::RegisterAsChild

## Description

Registers the specified process as a child. This method is no longer supported on Windows 10, version 1809, and later versions.

## Parameters

### `processHandle` [in]

Type: **HANDLE**

The process to be registered as a child.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISuspensionDependencyManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-isuspensiondependencymanager)