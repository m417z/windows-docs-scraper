# MsiSetTargetPathW function

## Description

The
**MsiSetTargetPath** function sets the full target path for a folder in the
[Directory table](https://learn.microsoft.com/windows/desktop/Msi/directory-table).

## Parameters

### `hInstall` [in]

Handle to the installation provided to a DLL custom action or obtained through [MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea), [MsiOpenPackageEx](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackageexa), or [MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta).

### `szFolder` [in]

Specifies the folder identifier. This is a primary key in the Directory table.

### `szFolderPath` [in]

Specifies the full path for the folder, ending in a directory separator.

## Return value

The
**MsiSetTargetPath** function returns the following values:

## Remarks

The
**MsiSetTargetPath** function changes the path specification for the target directory named in the in-memory
[Directory table](https://learn.microsoft.com/windows/desktop/Msi/directory-table). Also, the path specifications of all other path objects in the table that are either subordinate or equivalent to the changed path are updated to reflect the change. The properties for each affected path are also updated.

**MsiSetTargetPath** fails if the selected directory is read only.

If an error occurs in this function, all updated paths and properties revert to their previous values. Therefore, it is safe to treat errors returned by this function as nonfatal.

Do not attempt to configure the target path if the components using those paths are already installed for the current user or for a different user. Check the
[ProductState](https://learn.microsoft.com/windows/desktop/Msi/productstate) property before calling
**MsiSetTargetPath** to determine if the product containing this component is installed.

See
[Calling Database Functions From Programs](https://learn.microsoft.com/windows/desktop/Msi/calling-database-functions-from-programs).

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiSetTargetPath as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Installer Location Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)