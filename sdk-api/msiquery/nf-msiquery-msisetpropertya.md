# MsiSetPropertyA function

## Description

The
**MsiSetProperty** function sets the value for an installation property.

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szName` [in]

Specifies the name of the property.

### `szValue` [in]

Specifies the value of the property.

## Return value

This function returns UINT.

## Remarks

If the property is not defined, it is created by the
**MsiSetProperty** function. If the value is null or an empty string, the property is removed.

> [!NOTE]
> The msiquery.h header defines MsiSetProperty as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installer State Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)