# MsiCreateRecord function

## Description

The
**MsiCreateRecord** function creates a new record object with the specified number of fields. This function returns a handle that should be closed using
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle).

## Parameters

### `cParams` [in]

Specifies the number of fields the record will have. The maximum number of fields in a record is limited to 65535.

## Return value

If the function succeeds, the return value is handle to a new record object.

If the function fails, the return value is null.

## Remarks

Field 0 of the record object created by the
**MsiCreateRecord** function is used for format strings and operation codes and is not included in the count specified by *cParams*. All fields are initialized to null.

Note that it is recommended to use variables of type PMSIHANDLE because the installer closes PMSIHANDLE objects as they go out of scope, whereas you must close MSIHANDLE objects by calling
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle). For more information see [Use PMSIHANDLE instead of HANDLE](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices) section in the [Windows Installer Best Practices](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices).

## See also

[Database Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Record Processing Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)