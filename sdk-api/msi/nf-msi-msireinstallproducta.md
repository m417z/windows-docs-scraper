# MsiReinstallProductA function

## Description

The
**MsiReinstallProduct** function reinstalls products.

## Parameters

### `szProduct` [in]

Specifies the product code for the product to be reinstalled.

### `szReinstallMode` [in]

Specifies the reinstall mode. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **REINSTALLMODE_FILEMISSING** | Reinstall only if the file is missing. |
| **REINSTALLMODE_FILEOLDERVERSION** | Reinstall if the file is missing or is an older version. |
| **REINSTALLMODE_FILEEQUALVERSION** | Reinstall if the file is missing, or is an equal or older version. |
| **REINSTALLMODE_FILEEXACT** | Reinstall if the file is missing or is a different version. |
| **REINSTALLMODE_FILEVERIFY** | Verify the checksum values and reinstall the file if they are missing or corrupt. This flag only repairs files that have msidbFileAttributesChecksum in the Attributes column of the [File table](https://learn.microsoft.com/windows/desktop/Msi/file-table). |
| **REINSTALLMODE_FILEREPLACE** | Force all files to be reinstalled, regardless of checksum or version. |
| **REINSTALLMODE_USERDATA** | Rewrite all required registry entries from the [Registry Table](https://learn.microsoft.com/windows/desktop/Msi/registry-table) that go to the **HKEY_CURRENT_USER** or **HKEY_USERS** registry hive. |
| **REINSTALLMODE_MACHINEDATA** | Rewrite all required registry entries from the [Registry Table](https://learn.microsoft.com/windows/desktop/Msi/registry-table) that go to the **HKEY_LOCAL_MACHINE** or **HKEY_CLASSES_ROOT** registry hive. Rewrite all information from the [Class Table](https://learn.microsoft.com/windows/desktop/Msi/class-table), [Verb Table](https://learn.microsoft.com/windows/desktop/Msi/verb-table), [PublishComponent Table](https://learn.microsoft.com/windows/desktop/Msi/publishcomponent-table), [ProgID Table](https://learn.microsoft.com/windows/desktop/Msi/progid-table), [MIMET Table](https://learn.microsoft.com/windows/desktop/Msi/mime-table), [Icon Table](https://learn.microsoft.com/windows/desktop/Msi/icon-table), [Extension Table](https://learn.microsoft.com/windows/desktop/Msi/extension-table), and [AppID Table](https://learn.microsoft.com/windows/desktop/Msi/appid-table) regardless of machine or user assignment. Reinstall all [qualified components](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiprovidequalifiedcomponenta).<br><br>When reinstalling an application, this option runs the [RegisterTypeLibraries](https://learn.microsoft.com/windows/desktop/Msi/registertypelibraries-action) and [InstallODBC](https://learn.microsoft.com/windows/desktop/Msi/installodbc-action) actions. |
| **REINSTALLMODE_SHORTCUT** | Reinstall all shortcuts and re-cache all icons overwriting any existing shortcuts and icons. |
| **REINSTALLMODE_PACKAGE** | Use to run from the source package and re-cache the local package. Do not use for the first installation of an application or feature. |

## Return value

| Return code | Description |
| --- | --- |
| **ERROR_INSTALL_FAILURE** | The installation failed. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was passed to the function. |
| **ERROR_INSTALL_SERVICE_FAILURE** | The installation service could not be accessed. |
| **ERROR_INSTALL_SUSPEND** | The installation was suspended and is incomplete. |
| **ERROR_INSTALL_USEREXIT** | The user canceled the installation. |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_UNKNOWN_PRODUCT** | The product code does not identify a known product. |

For more information, see
[Displayed Error Messages](https://learn.microsoft.com/windows/desktop/Msi/displayed-error-messages).

## See also

[Installation and Configuration Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)

[Multiple Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)

[REINSTALLMODE Property](https://learn.microsoft.com/windows/desktop/Msi/reinstallmode)

## Remarks

> [!NOTE]
> The msi.h header defines MsiReinstallProduct as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).