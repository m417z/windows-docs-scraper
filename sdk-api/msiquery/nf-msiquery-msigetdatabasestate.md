# MsiGetDatabaseState function

## Description

The
**MsiGetDatabaseState** function returns the state of the database.

## Parameters

### `hDatabase` [in]

Handle to the database obtained from [MsiOpenDatabase](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiopendatabasea).

## Return value

This function returns MSIDBSTATE.

## Remarks

The
**MsiGetDatabaseState** function returns the update state of the database.

## See also

[Database Management Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)