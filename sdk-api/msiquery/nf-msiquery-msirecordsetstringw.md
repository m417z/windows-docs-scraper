# MsiRecordSetStringW function

## Description

The
**MsiRecordSetString** function copies a string into the designated field.

## Parameters

### `hRecord` [in]

Handle to the record.

### `iField` [in]

Specifies the field of the record to set.

### `szValue` [in]

Specifies the string value of the field.

## Return value

This function returns UINT.

## Remarks

In the
**MsiRecordSetString** function, a null string pointer and an empty string both set the field to null. Attempting to store a value in a nonexistent field causes an error.

To set a record string field to null, set szValue to either a null string or an empty string.

> [!NOTE]
> The msiquery.h header defines MsiRecordSetString as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Record Processing Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)