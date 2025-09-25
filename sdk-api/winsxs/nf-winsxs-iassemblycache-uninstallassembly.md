# IAssemblyCache::UninstallAssembly

## Description

The **UnistallAssembly** method removes an application reference to an assembly from the side-by-side store. If there are no other references to the assembly by other applications, the assembly becomes unusable. Windows may remove the assembly's files from the side-by-side store and reclaim disk space at a later time.

## Parameters

### `dwFlags` [in]

This parameter must be 0.

### `pszAssemblyName` [in]

A pointer to a null-terminated string value that contains the fully-specified strong name of the assembly. If the full name is not provided, the result is undefined.

### `pRefData` [in]

A pointer to a [FUSION_INSTALL_REFERENCE](https://learn.microsoft.com/windows/win32/api/winsxs/ns-winsxs-fusion_install_reference) structure that describes the application that holds the reference to the assembly being removed. If this value is null, no references to the assembly by applications are left in the side-by-side store and the assembly's files are removed.

**Note** The characters \, /, :, ;, *, <, >, and | are invalid in the reference ID.

### `pulDisposition` [out, optional]

A pointer to an integer value that describes the action performed.

The *pulDisposition* parameter can contain one of the following values or null.

| Value | Meaning |
| --- | --- |
| **IASSEMBLYCACHE_UNINSTALL_DISPOSITION_UNINSTALLED** | The assembly files have been removed from the side-by-side store. |
| **IASSEMBLYCACHE_UNINSTALL_DISPOSITION_STILL_IN_USE** | The assembly's files have not been removed because an application is using the assembly. |
| **IASSEMBLYCACHE_UNINSTALL_DISPOSITION_ALREADY_UNINSTALLED** | The assembly does not exist in the side-by-side store. |
| **IASSEMBLYCACHE_UNINSTALL_DISPOSITION_DELETE_PENDING** | Reserved. |
| **IASSEMBLYCACHE_UNINSTALL_DISPOSITION_HAS_INSTALL_REFERENCES** | The assembly's files have not been removed because the side-by-side store contains a reference to the assembly by another application. |
| **IASSEMBLYCACHE_UNINSTALL_DISPOSITION_REFERENCE_NOT_FOUND** | The reference specified in *pRefData* does not exist in the side-by-side store. |

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The files of the assembly have been removed from the side-by-side store. |
| S_FALSE | The operation succeeded and the reference to the assembly was removed. The assembly files were not removed from the side-by-side store for the reason described by the value returned by *pulDisposition*. |

## See also

[IAssemblyCache](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblycache)