# MsiProvideAssemblyW function

## Description

The
**MsiProvideAssembly** function returns the full path to a Windows Installer component that contains an assembly. The function prompts for a source and performs any necessary installation.
**MsiProvideAssembly** increments the usage count for the feature.

## Parameters

### `szAssemblyName` [in]

The assembly name as a string.

### `szAppContext` [in]

Set to null for global assemblies. For private assemblies, set *szAppContext* to the full path of the application configuration file or to the full path of the executable file of the application to which the assembly has been made private.

### `dwInstallMode` [in]

Defines the installation mode. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLMODE_DEFAULT** | Provide the component and perform any installation necessary to provide the component. If the key file of a component in the requested feature, or a feature parent, is missing, reinstall the feature using [MsiReinstallFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msireinstallfeaturea) with the following flag bits set: REINSTALLMODE_FILEMISSING, REINSTALLMODE_FILEOLDERVERSION, REINSTALLMODE_FILEVERIFY, REINSTALLMODE_MACHINEDATA, REINSTALLMODE_USERDATA and REINSTALLMODE_SHORTCUT. |
| **INSTALLMODE_EXISTING** | Provide the component only if the feature exists. Otherwise return ERROR_FILE_NOT_FOUND. <br><br>This mode verifies that the key file of the component exists. |
| **INSTALLMODE_NODETECTION** | Provide the component only if the feature exists. Otherwise return ERROR_FILE_NOT_FOUND. <br><br>This mode only checks that the component is registered and does not verify that the key file of the component exists. |
| **INSTALLMODE_NOSOURCERESOLUTION** | Provide the component only if the feature's installation state is INSTALLSTATE_LOCAL. If the feature installation state is INSTALLSTATE_SOURCE, return ERROR_INSTALL_SOURCE_ABSENT. Otherwise return ERROR_FILE_NOT_FOUND. This mode only checks that the component is registered and does not verify that the key file exists. |
| **INSTALLMODE_NODETECTION_ANY** | Provide the component if a feature exists from any installed product. Otherwise return ERROR_FILE_NOT_FOUND. This mode only checks that the component is registered and does not verify that the key file of the component exists. This flag is similar to the INSTALLMODE_NODETECTION flag except that with this flag we check for any product that has installed the assembly as opposed to the last product as is the case with the INSTALLMODE_NODETECTION flag. This flag can only be used with **MsiProvideAssembly**. |
| **combination of the REINSTALLMODE flags** | Call [MsiReinstallFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msireinstallfeaturea) to reinstall feature using this parameter for the *dwReinstallMode* parameter, and then provide the component. |

### `dwAssemblyInfo` [in]

Assembly information and assembly type. Set to one of the following values.

| Value | Meaning |
| --- | --- |
| **MSIASSEMBLYINFO_NETASSEMBLY**<br><br>0 | .NET Assembly |
| **MSIASSEMBLYINFO_WIN32ASSEMBLY**<br><br>1 | Win32 Assembly |

### `lpPathBuf` [out]

Pointer to a variable that receives the path to the component. This parameter can be null.

### `pcchPathBuf` [in, out]

Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the *lpPathBuf* parameter. On input, this is the full size of the buffer, including a space for a terminating null character. If the buffer passed in is too small, the count returned does not include the terminating null character.

If *lpPathBuf* is null, *pcchPathBuf* can be null.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_FILE_NOT_FOUND** | The feature is absent or broken. This error is returned for dwInstallMode = INSTALLMODE_EXISTING. |
| **ERROR_INSTALL_FAILURE** | The installation failed. |
| **ERROR_INSTALL_NOTUSED** | The component being requested is disabled on the computer. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_UNKNOWN_FEATURE** | The feature ID does not identify a known feature. |
| **ERROR_UNKNOWN_COMPONENT** | The component ID does not specify a known component. |
| **ERROR_UNKNOWN_PRODUCT** | The product code does not identify a known product. |
| **INSTALLSTATE_UNKNOWN** | An unrecognized product or a feature name was passed to the function. |
| **ERROR_MORE_DATA** | The buffer overflow is returned. |
| **ERROR_NOT_ENOUGH_MEMORY** | The system does not have enough memory to complete the operation. Available with Windows Server 2003. |
| **ERROR_INSTALL_SOURCE_ABSENT** | Unable to detect a source. |

For more information, see
[Displayed Error Messages](https://learn.microsoft.com/windows/desktop/Msi/displayed-error-messages).

## Remarks

When the
**MsiProvideAssembly** function succeeds, the *pcchPathBuf* parameter contains the length of the string in *lpPathBuf*.

The INSTALLMODE_EXISTING option cannot be used in combination with the REINSTALLMODE flag.

Features with components that contain a corrupted file or the wrong version of a file must be explicitly reinstalled by the user, or by having the application call
[MsiReinstallFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msireinstallfeaturea).

> [!NOTE]
> The msi.h header defines MsiProvideAssembly as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Component-Specific Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)

[Multiple-Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)