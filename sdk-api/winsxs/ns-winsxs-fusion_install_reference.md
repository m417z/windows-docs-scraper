# FUSION_INSTALL_REFERENCE structure

## Description

The **FUSION_INSTALL_REFERENCE** structure contains information about the application which references the side-by-side assembly. The assembly being referenced can be added to or removed from the side-by-side assembly store using the [InstallAssembly](https://learn.microsoft.com/windows/desktop/api/winsxs/nf-winsxs-iassemblycache-installassembly) and [UninstallAssembly](https://learn.microsoft.com/windows/desktop/api/winsxs/nf-winsxs-iassemblycache-uninstallassembly) methods.

## Members

### `cbSize`

The size of the structure in bytes.

### `dwFlags`

Reserved, this member must be zero.

### `guidScheme`

The application that uses the side-by-side assembly.

 This parameter can have one of the following values:

| Value | Meaning |
| --- | --- |
| **FUSION_REFCOUNT_MSI_GUID** | The assembly is referenced by an application that has been installed by using the [Windows Installer](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-portal). The **szIdentifier** member is set to MSI, and **szNonCannonicalData** is set to Windows Installer. Use this value for Windows side-by-side assemblies. |
| **FUSION_REFCOUNT_UNINSTALL_SUBKEY_GUID** | The assembly is referenced by an application that appears in Add/Remove Programs. The **szIdentifier** member is the token used to register the application with Add/Remove programs. |
| **FUSION_REFCOUNT_FILEPATH_GUID** | The assembly is referenced by an application that is represented by a file in the file system. The **szIdentifier** parameter is the path to this file. |
| **FUSION_REFCOUNT_OPAQUE_STRING_GUID** | The assembly is referenced by an application that is only represented by an opaque string. The **szIdentifier** member is this opaque string. This value is required for the side-by-side store to check for the existence of opaque references. |
| **FUSION_REFCOUNT_OSINSTALL_GUID** | Reserved |

### `szIdentifier`

A pointer to a string value that identifies the application that references assembly. The meaning of this identifier depends on the **guidScheme** parameter.

### `szNonCannonicalData`

A string that is used only by the application that reference the assembly.