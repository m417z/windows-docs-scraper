# MsiProvideQualifiedComponentExW function

## Description

The
**MsiProvideQualifiedComponentEx** function returns the full component path for a qualified component that is published by a product and performs any necessary installation. This function prompts for source if necessary and increments the usage count for the feature.

## Parameters

### `szCategory` [in]

Specifies the component ID that for the requested component. This may not be the GUID for the component itself but rather a server that provides the correct functionality, as in the ComponentId column of the
[PublishComponent table](https://learn.microsoft.com/windows/desktop/Msi/publishcomponent-table).

### `szQualifier` [in]

Specifies a qualifier into a list of advertising components (from
[PublishComponent Table](https://learn.microsoft.com/windows/desktop/Msi/publishcomponent-table)).

### `dwInstallMode` [in]

Defines the installation mode. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLMODE_DEFAULT** | Provide the component and perform any installation necessary to provide the component. If the key file of a component in the requested feature, or a feature parent, is missing, reinstall the feature using [MsiReinstallFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msireinstallfeaturea) with the following flag bits set: REINSTALLMODE_FILEMISSING, REINSTALLMODE_FILEOLDERVERSION, REINSTALLMODE_FILEVERIFY, REINSTALLMODE_MACHINEDATA, REINSTALLMODE_USERDATA and REINSTALLMODE_SHORTCUT. |
| **INSTALLMODE_EXISTING** | Provide the component only if the feature exists. Otherwise return ERROR_FILE_NOT_FOUND. <br><br>This mode verifies that the key file of the component exists. |
| **INSTALLMODE_NODETECTION** | Provide the component only if the feature exists. Otherwise return ERROR_FILE_NOT_FOUND. <br><br>This mode only checks that the component is registered and does not verify that the key file of the component exists. |
| **INSTALLMODE_EXISTING** | Provide the component only if the feature exists, else return ERROR_FILE_NOT_FOUND. |
| **combination of the REINSTALLMODE flags** | Call [MsiReinstallFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msireinstallfeaturea) to reinstall feature using this parameter for the *dwReinstallMode* parameter, and then provide the component. |
| **INSTALLMODE_NOSOURCERESOLUTION** | Provide the component only if the feature's installation state is INSTALLSTATE_LOCAL. If the feature's installation state is INSTALLSTATE_SOURCE, return ERROR_INSTALL_SOURCE_ABSENT. Otherwise return ERROR_FILE_NOT_FOUND. This mode only checks that the component is registered and does not verify that the key file exists. |

### `szProduct` [in]

Specifies the product to match that has published the qualified component. If this is null, then this API works the same as
[MsiProvideQualifiedComponent](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiprovidequalifiedcomponenta).

### `dwUnused1` [in]

Reserved. Must be zero.

### `dwUnused2` [in]

Reserved. Must be zero.

### `lpPathBuf` [out]

Pointer to a variable that receives the path to the component. This parameter can be null.

### `pcchPathBuf` [in, out]

Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the *lpPathBuf* parameter. On input, this is the full size of the buffer, including a space for a terminating null character. If the buffer passed in is too small, the count returned does not include the terminating null character.

If *lpPathBuf* is null, *pcchBuf* can be null.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_INDEX_ABSENT** | Component qualifier invalid or not present. |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_FILE_NOT_FOUND** | The feature is absent or broken. this error is returned for *dwInstallMode* = INSTALLMODE_EXISTING. |
| **ERROR_UNKNOWN_COMPONENT** | The specified component is unknown. |
| **An error relating to an action** | See [Error Codes](https://learn.microsoft.com/windows/desktop/Msi/error-codes). |
| **[Initialization Error](https://learn.microsoft.com/windows/desktop/Msi/initialization-errors)** | An error relating to initialization occurred. |

## Remarks

Upon success of the
**MsiProvideQualifiedComponentEx** function, the *pcchPathBuf* parameter contains the length of the string in *lpPathBuf*.

Features with components containing a corrupted file or the wrong version of a file must be explicitly reinstalled by the user or by having the application call
[MsiReinstallFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msireinstallfeaturea).

> [!NOTE]
> The msi.h header defines MsiProvideQualifiedComponentEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Component-Specific Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)

[Displayed Error Messages](https://learn.microsoft.com/windows/desktop/Msi/displayed-error-messages)

[Error Codes](https://learn.microsoft.com/windows/desktop/Msi/error-codes)

[Initialization Error](https://learn.microsoft.com/windows/desktop/Msi/initialization-errors)

[Multiple-Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)