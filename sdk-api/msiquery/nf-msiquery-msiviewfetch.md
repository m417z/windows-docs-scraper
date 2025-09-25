# MsiViewFetch function

## Description

The
**MsiViewFetch** function fetches the next sequential record from the view. This function returns a handle that should be closed using
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle).

## Parameters

### `hView` [in]

Handle to the view to fetch from.

### `phRecord` [out]

Pointer to the handle for the fetched record.

## Return value

Note that in low memory situations, this function can raise a STATUS_NO_MEMORY exception.

## Remarks

If the
**MsiViewFetch** function returns ERROR_FUNCTION_FAILED, it is possible that the
[MsiViewExecute](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewexecute) function was not called first. If more rows are available in the result set,
**MsiViewFetch** returns *phRecord* as a handle to a record containing the requested column data, or *phRecord* is 0. For maximum performance, the same record should be used for all retrievals, or the record should be released by going out of scope.

Note that it is recommended to use variables of type PMSIHANDLE because the installer closes PMSIHANDLE objects as they go out of scope, whereas you must close MSIHANDLE objects by calling
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle). For more information see [Use PMSIHANDLE instead of HANDLE](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices) section in the [Windows Installer Best Practices](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices).

## See also

[General Database Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Working with Queries](https://learn.microsoft.com/windows/desktop/Msi/working-with-queries)