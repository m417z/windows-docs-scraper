# ISuspensionDependencyManager::GroupChildWithParent

## Description

Groups the specified child process with the parent process. This method is no longer supported on Windows 10, version 1809, and later versions.

## Parameters

### `childProcessHandle` [in]

Type: **HANDLE**

The child process to group with the parent process.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ISuspensionDependencyManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-isuspensiondependencymanager)