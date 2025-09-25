# MsiInstallMissingFileW function

## Description

The
**MsiInstallMissingFile** function installs files that are unexpectedly missing.

## Parameters

### `szProduct` [in]

Specifies the product code for the product that owns the file to be installed.

### `szFile` [in]

Specifies the file to be installed.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_BAD_CONFIGURATION** | The configuration information is corrupt. |
| **ERROR_INSTALL_FAILURE** | The installation failed. |
| **ERROR_INSTALL_SOURCE_ABSENT** | The source was unavailable. |
| **ERROR_INSTALL_SUSPEND** | The installation was suspended. |
| **ERROR_INSTALL_USEREXIT** | The user exited the installation. |
| **ERROR_INVALID_PARAMETER** | A parameter was invalid. |
| **ERROR_SUCCESS** | The function completed successfully. |
| **ERROR_UNKNOWN_PRODUCT** | The product code is unrecognized. |

For more information about error messages, see
[Displayed Error Messages](https://learn.microsoft.com/windows/desktop/Msi/displayed-error-messages).

## Remarks

The
**MsiInstallMissingFile** function obtains the component that the file belongs to from the file table. Then, the product feature that requires the least additional disk space is installed.

> [!NOTE]
> The msi.h header defines MsiInstallMissingFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installation and Configuration Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)

[Multiple-Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)