# MsiRecordGetFieldCount function

## Description

The
**MsiRecordGetFieldCount** function returns the number of fields in a record.

## Parameters

### `hRecord` [in]

Handle to a record.

## Return value

If the function succeeds, the return value is the number of fields in the record.

## Remarks

The count returned by the
**MsiRecordGetFieldCount** parameter does not include field 0. Read access to fields beyond this count returns null values. Write access fails.

## See also

[Record Processing Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)