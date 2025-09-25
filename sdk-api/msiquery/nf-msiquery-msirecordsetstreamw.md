# MsiRecordSetStreamW function

## Description

The
**MsiRecordSetStream** function sets a record stream field from a file. Stream data cannot be inserted into temporary fields.

## Parameters

### `hRecord` [in]

Handle to the record.

### `iField` [in]

Specifies the field of the record to set.

### `szFilePath` [in]

Specifies the path to the file containing the stream.

## Return value

The
**MsiRecordSetStream** function returns the following values:

## Remarks

The contents of the file specified in the
**MsiRecordSetStream** function is read into a stream object. The stream persists if the record is inserted into the database and the database is committed.

To reset the stream to its beginning you must pass in a Null pointer for *szFilePath*. Do not pass a pointer to an empty string, "", to reset the stream.

See also
[OLE Limitations on Streams](https://learn.microsoft.com/windows/desktop/Msi/ole-limitations-on-streams).

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiRecordSetStream as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Record Processing Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)