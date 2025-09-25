# MsiInstallProductA function

## Description

The
**MsiInstallProduct** function installs or uninstalls a product.

## Parameters

### `szPackagePath` [in]

A null-terminated string that specifies the path to the location of the Windows Installer package. The string value can contain a URL (e.g. `http://packageLocation/package/package.msi`), a network path (e.g. \\packageLocation\package.msi), a file path (e.g. file://packageLocation/package.msi), or a local path (e.g. D:\packageLocation\package.msi).

### `szCommandLine` [in]

A null-terminated string that specifies the command line property settings. This should be a list of the format *Property=Setting Property=Setting*. For more information, see
[About Properties](https://learn.microsoft.com/windows/desktop/Msi/about-properties).

To perform an administrative installation, include ACTION=ADMIN in *szCommandLine*. For more information, see the
[ACTION](https://learn.microsoft.com/windows/desktop/Msi/action) property.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_SUCCESS** | The function completes successfully. |
| **An error relating to an action** | For more information, see [Error Codes](https://learn.microsoft.com/windows/desktop/Msi/error-codes). |
| **[Initialization Error](https://learn.microsoft.com/windows/desktop/Msi/initialization-errors)** | An error that relates to initialization occurred. |

For more information, see
[Displayed Error Messages](https://learn.microsoft.com/windows/desktop/Msi/displayed-error-messages).

## Remarks

The
**MsiInstallProduct** function displays the user interface with the current settings and log mode.

* You can change user interface settings by using the
  [MsiSetInternalUI](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetinternalui),
  [MsiSetExternalUI](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetexternaluia), or [MsiSetExternalUIRecord](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msisetexternaluirecord) functions.
* You can set the log mode by using the
  [MsiEnableLog](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msienableloga) function.
* You can completely remove a product by setting REMOVE=ALL in *szCommandLine*.

For more information, see
[REMOVE](https://learn.microsoft.com/windows/desktop/Msi/remove) Property.

> [!NOTE]
> The msi.h header defines MsiInstallProduct as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Displayed Error Messages](https://learn.microsoft.com/windows/desktop/Msi/displayed-error-messages)

[Error Codes](https://learn.microsoft.com/windows/desktop/Msi/error-codes)

[Initialization Error](https://learn.microsoft.com/windows/desktop/Msi/initialization-errors)

[Installation and Configuration Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)

[Multiple-Package Installations](https://learn.microsoft.com/windows/desktop/Msi/multiple-package-installations)