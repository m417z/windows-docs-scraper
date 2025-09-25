# MsiProvideComponentW function

## Description

The
**MsiProvideComponent** function returns the full component path, performing any necessary installation. This function prompts for source if necessary and increments the usage count for the feature.

## Parameters

### `szProduct` [in]

Specifies the product code for the product that contains the feature with the necessary component.

### `szFeature` [in]

Specifies the feature ID of the feature with the necessary component.

### `szComponent` [in]

Specifies the component code of the necessary component.

### `dwInstallMode` [in]

Defines the installation mode. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLMODE_DEFAULT** | Provide the component and perform any installation necessary to provide the component. If the key file of a component in the requested feature, or a feature parent, is missing, reinstall the feature using [MsiReinstallFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msireinstallfeaturea) with the following flag bits set: REINSTALLMODE_FILEMISSING, REINSTALLMODE_FILEOLDERVERSION, REINSTALLMODE_FILEVERIFY, REINSTALLMODE_MACHINEDATA, REINSTALLMODE_USERDATA and REINSTALLMODE_SHORTCUT. |
| **INSTALLMODE_EXISTING** | Provide the component only if the feature exists. Otherwise return ERROR_FILE_NOT_FOUND. <br><br>This mode verifies that the key file of the component exists. |
| **INSTALLMODE_NODETECTION** | Provide the component only if the feature exists. Otherwise return ERROR_FILE_NOT_FOUND. <br><br>This mode only checks that the component is registered and does not verify that the key file of the component exists. |
| **combination of the REINSTALLMODE flags** | Call [MsiReinstallFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msireinstallfeaturea) to reinstall feature using this parameter for the *dwReinstallMode* parameter, and then provide the component. |
| **INSTALLMODE_NOSOURCERESOLUTION** | Provide the component only if the feature's installation state is INSTALLSTATE_LOCAL. If the feature's installation state is INSTALLSTATE_SOURCE, return ERROR_INSTALL_SOURCE_ABSENT. Otherwise return ERROR_FILE_NOT_FOUND. This mode only checks that the component is registered and does not verify that the key file exists. |

### `lpPathBuf` [out]

Pointer to a variable that receives the path to the component. This parameter can be null.

### `pcchPathBuf` [in, out]

Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the *lpPathBuf* parameter. On input, this is the full size of the buffer, including a space for a terminating null character. If the buffer passed in is too small, the count returned does not include the terminating null character.

If *lpPathBuf* is null, *pcchBuf* can be null.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration data is corrupt. |
| **ERROR_FILE_NOT_FOUND** | The feature is absent or broken. this error is returned for dwInstallMode = INSTALLMODE_EXISTING. |
| **ERROR_INSTALL_FAILURE** | The installation failed. |
| **ERROR_INSTALL_NOTUSED** | The component being requested is disabled on the computer. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_UNKNOWN_FEATURE** | The feature ID does not identify a known feature. |
| **ERROR_UNKNOWN_PRODUCT** | The product code does not identify a known product. |
| **INSTALLSTATE_UNKNOWN** | An unrecognized product or a feature name was passed to the function. |
| **ERROR_MORE_DATA** | The buffer overflow is returned. |
| **ERROR_INSTALL_SOURCE_ABSENT** | Unable to detect a source. |

For more information, see
[Displayed Error Messages](https://learn.microsoft.com/windows/desktop/Msi/displayed-error-messages).

## Remarks

Upon success of the
**MsiProvideComponent** function, the *pcchPathBuf* parameter contains the length of the string in *lpPathBuf*.

The
**MsiProvideComponent** function combines the functionality of
[MsiUseFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiusefeaturea),
[MsiConfigureFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigurefeaturea), and
[MsiGetComponentPath](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msigetcomponentpatha). You can use the
**MsiProvideComponent** function to simplify the calling sequence. However, because this function increments the usage count, use it with caution to prevent inaccurate usage counts. The
**MsiProvideComponent** function also provides less flexibility than the series of individual calls.

If the application is recovering from an unexpected situation, the application has probably already called
[MsiUseFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiusefeaturea) and incremented the usage count. In this case, the application should call
[MsiConfigureFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigurefeaturea) instead of
**MsiProvideComponent** to avoid incrementing the count again.

The INSTALLMODE_EXISTING option cannot be used in combination with the REINSTALLMODE flag.

Features with components containing a corrupted file or the wrong version of a file must be explicitly reinstalled by the user or by having the application call
[MsiReinstallFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msireinstallfeaturea).

> [!NOTE]
> The msi.h header defines MsiProvideComponent as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Component-Specific Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)

[Multiple-Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)