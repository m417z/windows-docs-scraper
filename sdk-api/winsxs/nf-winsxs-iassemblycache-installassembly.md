# IAssemblyCache::InstallAssembly

## Description

The **InstallAssembly** method adds an application reference to an assembly to the side-by-side store and copies the files of the assembly to the side-by-side store. The files of the assembly being installed must be present in the current file system.

## Parameters

### `dwFlags` [in]

This parameter specifies how existing files in the side-by-side store are to replaced by files in the assembly being installed.

One of the following options can be specified.

| Value | Meaning |
| --- | --- |
| **IASSEMBLYCACHE_INSTALL_FLAG_REFRESH** | Replace existing files in the side-by-side store with the files in the assembly being installed if the version of the file in the assembly is greater than or equal to the version of the existing file. |
| **IASSEMBLYCACHE_INSTALL_FLAG_FORCE_REFRESH** | Replace existing files in the side-by-side store with the files in the assembly being installed. |

### `pszManifestFilePath` [in]

A pointer to a string value that contains the full path to the dynamic-linked library (DLL) or executable (EXE) file that contains the assembly manifest. Any other assembly files must be located in the same directory as this DLL or EXE.

### `pRefData` [in, optional]

A pointer to a [FUSION_INSTALL_REFERENCE](https://learn.microsoft.com/windows/win32/api/winsxs/ns-winsxs-fusion_install_reference) structure that describes the application that holds the reference to the assembly being installed. If this parameter is null, the assembly files are copied, but no application reference is added to the side-by-side store.

## Return value

This method can return one of these values.

| Return value | Description |
| --- | --- |
| S_OK | The method succeeded. |
| S_FALSE | The method did not succeed. |

## See also

[IAssemblyCache](https://learn.microsoft.com/windows/desktop/api/winsxs/nn-winsxs-iassemblycache)