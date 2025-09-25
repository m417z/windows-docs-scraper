# MsiDatabaseGetPrimaryKeysW function

## Description

The
**MsiDatabaseGetPrimaryKeys** function returns a record containing the names of all the primary key columns for a specified table. This function returns a handle that should be closed using
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle).

## Parameters

### `hDatabase` [in]

Handle to the database. See
[Obtaining a Database Handle](https://learn.microsoft.com/windows/desktop/Msi/obtaining-a-database-handle).

### `szTableName` [in]

Specifies the name of the table from which to obtain primary key names.

### `phRecord` [out]

Pointer to the handle of the record that holds the primary key names.

## Return value

This function returns UINT.

## Remarks

The field count of the returned record is the count of primary key columns returned by the
**MsiDatabaseGetPrimaryKeys** function. The returned record contains the table name in Field (0) and the column names that make up the primary key names in succeeding fields. These primary key names correspond to the column numbers for the fields.

This function cannot be used with the
[_Tables table](https://learn.microsoft.com/windows/desktop/Msi/-tables-table) or the
[_Columns table](https://learn.microsoft.com/windows/desktop/Msi/-columns-table).

Note that it is recommended to use variables of type PMSIHANDLE because the installer closes PMSIHANDLE objects as they go out of scope, whereas you must close MSIHANDLE objects by calling
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle). For more information see [Use PMSIHANDLE instead of HANDLE](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices) section in the [Windows Installer Best Practices](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices).

> [!NOTE]
> The msiquery.h header defines MsiDatabaseGetPrimaryKeys as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[General Database Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)