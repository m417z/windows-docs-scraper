# MsiRecordGetInteger function

## Description

The
**MsiRecordGetInteger** function returns the integer value from a record field.

## Parameters

### `hRecord` [in]

Handle to a record.

### `iField` [in]

Specifies the field of the record from which to obtain the value.

## Return value

If the function succeeds, the return value is the integer value of the field.

## Remarks

The
**MsiRecordGetInteger** function returns **MSI_NULL_INTEGER** if the field is null or if the field is a string that cannot be converted to an integer.

## See also

[Record Processing Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)