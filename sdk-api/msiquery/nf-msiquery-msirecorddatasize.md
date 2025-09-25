# MsiRecordDataSize function

## Description

The
**MsiRecordDataSize** function returns the length of a record field. The count does not include the terminating null character.

## Parameters

### `hRecord` [in]

Handle to the record.

### `iField` [in]

Specifies a field of the record.

## Return value

The
**MsiRecordDataSize** function returns 0 if the field is null, nonexistent, or an internal object pointer. The function also returns 0 if the handle is not a valid record handle.

If the data is in integer format, the function returns sizeof(int).

If the data is in string format, the function returns the character count (not including the null character).

If the data is in stream format, the function returns the byte count.

## See also

[Record Processing Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)