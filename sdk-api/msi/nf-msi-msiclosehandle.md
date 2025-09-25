# MsiCloseHandle function

## Description

The
**MsiCloseHandle** function closes an open installation handle.

## Parameters

### `hAny` [in]

Specifies any open installation handle.

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_HANDLE** | An invalid handle was passed to the function. |
| **ERROR_SUCCESS** | The function succeeded. |

## Remarks

**MsiCloseHandle** must be called from the same thread that requested the creation of the handle.

The following functions supply handles that should be closed after use by calling
**MsiCloseHandle**:

[MsiCreateRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msicreaterecord)
[MsiGetActiveDatabase](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetactivedatabase)
[MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord)
[MsiOpenPackage](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenpackagea)
[MsiOpenProduct](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiopenproducta)
[MsiOpenDatabase](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiopendatabasea)
[MsiDatabaseOpenView](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msidatabaseopenviewa)
[MsiViewFetch](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewfetch)
[MsiViewGetColumnInfo](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewgetcolumninfo)
[MsiDatabaseGetPrimaryKeys](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msidatabasegetprimarykeysa)
[MsiGetSummaryInformation](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetsummaryinformationa)
[MsiEnableUIPreview](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msienableuipreview)
Note that when writing custom actions, it is recommended to use variables of type PMSIHANDLE because the installer closes PMSIHANDLE objects as they go out of scope, whereas you must close MSIHANDLE objects by calling
**MsiCloseHandle**.

For example, if you use code like this:

MSIHANDLE hRec = MsiCreateRecord(3);

Change it to:

PMSIHANDLE hRec = MsiCreateRecord(3);

## See also

[Handle Management Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)