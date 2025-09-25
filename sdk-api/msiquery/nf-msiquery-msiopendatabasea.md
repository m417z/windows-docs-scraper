# MsiOpenDatabaseA function

## Description

The
**MsiOpenDatabase** function opens a database file for data access. This function returns a handle that should be closed using
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle).

## Parameters

### `szDatabasePath` [in]

Specifies the full path or relative path to the database file.

### `szPersist` [in]

Receives the full path to the file or the persistence mode. You can use the *szPersist* parameter to direct the persistent output to a new file or to specify one of the following predefined persistence modes.

| Value | Meaning |
| --- | --- |
| **MSIDBOPEN_CREATEDIRECT** | Create a new database, direct mode read/write. |
| **MSIDBOPEN_CREATE** | Create a new database, transact mode read/write. |
| **MSIDBOPEN_DIRECT** | Open a database direct read/write without transaction. |
| **MSIDBOPEN_READONLY** | Open a database read-only, no persistent changes. |
| **MSIDBOPEN_TRANSACT** | Open a database read/write in transaction mode. |
| **MSIDBOPEN_PATCHFILE** | Add this flag to indicate a patch file. |

### `phDatabase` [out]

Pointer to the location of the returned database handle.

## Return value

The
**MsiOpenDatabase** function returns the following values:

## Remarks

To make and save changes to a database first open the database in transaction (MSIDBOPEN_TRANSACT), create (MSIDBOPEN_CREATE or MSIDBOPEN_CREATEDIRECT), or direct (MSIDBOPEN_DIRECT) mode. After making the changes, always call
[MsiDatabaseCommit](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msidatabasecommit) before closing the database handle.
**MsiDatabaseCommit** flushes all buffers.

Always call
[MsiDatabaseCommit](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msidatabasecommit) on a database that has been opened in direct mode (MSIDBOPEN_DIRECT or MSIDBOPEN_CREATEDIRECT) before closing the database's handle. Failure to do this may corrupt the database.

Because
**MsiOpenDatabase** initiates database access, it cannot be used with a running installation.

Note that it is recommended to use variables of type PMSIHANDLE because the installer closes PMSIHANDLE objects as they go out of scope, whereas you must close MSIHANDLE objects by calling
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle). For more information see [Use PMSIHANDLE instead of HANDLE](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices) section in the [Windows Installer Best Practices](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices).

**Note** When a database is opened as the output of another database, the summary information stream of the output database is actually a read-only mirror of the original database, and, thus, cannot be changed. Additionally, it is not persisted with the database. To create or modify the summary information for the output database, it must be closed and reopened.

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiOpenDatabase as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[A Database and Patch Example](https://learn.microsoft.com/windows/desktop/Msi/a-database-and-patch-example)

[General Database Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)