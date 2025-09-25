# MsiDatabaseCommit function

## Description

The
**MsiDatabaseCommit** function commits changes to a database.

## Parameters

### `hDatabase` [in]

Handle to the database obtained from [MsiOpenDatabase](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiopendatabasea).

## Return value

The
**MsiDatabaseCommit** function returns one of the following values:

## Remarks

The
**MsiDatabaseCommit** function finalizes the persistent form of the database. All persistent data is then written to the writable database. No temporary columns or rows are written. The
**MsiDatabaseCommit** function has no effect on a database that is opened as read-only. You can call this function multiple times to save the current state of tables loaded into memory. When the database is finally closed, any changes made after the database is committed are rolled back. This function is normally called prior to shutdown when all database changes have been finalized.

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

## See also

[General Database Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)