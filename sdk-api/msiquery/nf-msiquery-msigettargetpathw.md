# MsiGetTargetPathW function

## Description

The
**MsiGetTargetPath** function returns the full target path for a folder in the
[Directory table](https://learn.microsoft.com/windows/desktop/Msi/directory-table).

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szFolder` [in]

A null-terminated string that specifies a record of the
[Directory table](https://learn.microsoft.com/windows/desktop/Msi/directory-table). If the directory is a root directory, this can be a value from the DefaultDir column. Otherwise it must be a value from the Directory column.

### `szPathBuf` [out]

Pointer to the buffer that receives the null terminated full target path. Do not attempt to determine the size of the buffer by passing in a null (value=0) for *szPathBuf*. You can get the size of the buffer by passing in an empty string (for example ""). The function then returns ERROR_MORE_DATA and *pcchPathBuf* contains the required buffer size in TCHARs, not including the terminating null character. On return of ERROR_SUCCESS, *pcchPathBuf* contains the number of TCHARs written to the buffer, not including the terminating null character.

### `pcchPathBuf` [in, out]

Pointer to the variable that specifies the size, in **TCHARs**, of the buffer pointed to by the variable *szPathBuf* When the function returns ERROR_SUCCESS, this variable contains the size of the data copied to *szPathBuf*, not including the terminating null character. If *szPathBuf* is not large enough, the function returns ERROR_MORE_DATA and stores the required size, not including the terminating null character, in the variable pointed to by *pcchPathBuf*.

## Return value

The
**MsiGetTargetPath** function returns the following values:

## Remarks

If ERROR_MORE_DATA is returned, the parameter which is a pointer gives the size of the buffer required to hold the string. If ERROR_SUCCESS is returned, it gives the number of characters written to the string buffer. Therefore you can get the size of the buffer by passing in an empty string (for example "") for the parameter that specifies the buffer. Do not attempt to determine the size of the buffer by passing in a Null (value=0).

Before calling this function, the installer must first run the
[CostInitialize action](https://learn.microsoft.com/windows/desktop/Msi/costinitialize-action),
[FileCost action](https://learn.microsoft.com/windows/desktop/Msi/filecost-action), and
[CostFinalize action](https://learn.microsoft.com/windows/desktop/Msi/costfinalize-action). For more information, see [Calling Database Functions from Programs](https://learn.microsoft.com/windows/desktop/Msi/calling-database-functions-from-programs).

**MsiGetTargetPath** returns the default path of the target directory authored in the package if the target's current location is unavailable for an installation. For example, if during a
[Maintenance Installation](https://learn.microsoft.com/windows/desktop/Msi/maintenance-installation) a target directory at a network location is unavailable, the installer resets the target directory paths back to their defaults. To get the actual path of the target directory in this case call
[MsiProvideComponent](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiprovidecomponenta) for a component that is known to have been previously installed into the searched for directory and set *dwInstallMode* to INSTALLMODE_NODETECTION.

For more information, see
[Calling Database Functions From Programs](https://learn.microsoft.com/windows/desktop/Msi/calling-database-functions-from-programs).

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiGetTargetPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installer Location Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Passing Null as the Argument of Windows Installer Functions](https://learn.microsoft.com/windows/desktop/Msi/passing-null-as-the-argument-of-windows-installer-functions)