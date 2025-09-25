# MsiViewGetColumnInfo function

## Description

The
**MsiViewGetColumnInfo** function returns a record containing column names or definitions. This function returns a handle that should be closed using
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle).

## Parameters

### `hView` [in]

Handle to the view from which to obtain column information.

### `eColumnInfo` [in]

Specifies a flag indicating what type of information is needed. This parameter must be one of the following values.

| Value | Meaning |
| --- | --- |
| **MSICOLINFO_NAMES** | Column names are returned. |
| **MSICOLINFO_TYPES** | Definitions are returned. |

### `phRecord` [out]

Pointer to a handle to receive the column information data record.

## Return value

Note that in low memory situations, this function can raise a STATUS_NO_MEMORY exception.

## Remarks

The column description returned by
**MsiViewGetColumnInfo** is in the format described in the section:
[Column Definition Format](https://learn.microsoft.com/windows/desktop/Msi/column-definition-format). Each column is described by a string in the corresponding record field. The definition string consists of a single letter representing the data type followed by the width of the column (in characters when applicable, bytes otherwise). A width of zero designates an unbounded width (for example, long text fields and streams). An uppercase letter indicates that null values are allowed in the column.

Note that it is recommended to use variables of type PMSIHANDLE because the installer closes PMSIHANDLE objects as they go out of scope, whereas you must close MSIHANDLE objects by calling
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle). For more information see [Use PMSIHANDLE instead of HANDLE](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices) section in the [Windows Installer Best Practices](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices).