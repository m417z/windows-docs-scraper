# MsiDatabaseOpenViewW function

## Description

The
**MsiDatabaseOpenView** function prepares a database query and creates a view object. This function returns a handle that should be closed using
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle).

## Parameters

### `hDatabase` [in]

Handle to the database to which you want to open a view object. You can get the handle as described in [Obtaining a Database Handle](https://learn.microsoft.com/windows/desktop/Msi/obtaining-a-database-handle).

### `szQuery` [in]

Specifies a SQL query string for querying the database. For correct syntax, see
[SQL Syntax](https://learn.microsoft.com/windows/desktop/Msi/sql-syntax).

### `phView` [out]

Pointer to a handle for the returned view.

## Return value

The
**MsiDatabaseOpenView** function returns one of the following values:

## Remarks

The
**MsiDatabaseOpenView** function opens a view object for a database. You must open a view object for a database before performing any execution or fetching.

If an error occurs, you can call
[MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord) for more information.

Note that it is recommended to use variables of type PMSIHANDLE because the installer closes PMSIHANDLE objects as they go out of scope, whereas you must close MSIHANDLE objects by calling
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle). For more information see [Use PMSIHANDLE instead of HANDLE](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices) section in the [Windows Installer Best Practices](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices).

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiDatabaseOpenView as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[General Database Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)