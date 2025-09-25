# MsiDatabaseGenerateTransformW function

## Description

The
**MsiDatabaseGenerateTransform** function generates a transform file of differences between two databases. A transform is a way of recording changes to a database without altering the original database. You can also use
**MsiDatabaseGenerateTransform** to test whether two databases are identical without creating a transform.

## Parameters

### `hDatabase` [in]

Handle to the database obtained from [MsiOpenDatabase](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiopendatabasea) that includes the changes.

### `hDatabaseReference` [in]

Handle to the database obtained from [MsiOpenDatabase](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiopendatabasea) that does not include the changes.

### `szTransformFile` [in]

A null-terminated string that specifies the name of the transform file being generated. This parameter can be null. If *szTransformFile* is null, you can use
**MsiDatabaseGenerateTransform** to test whether two databases are identical without creating a transform. If the databases are identical, the function returns ERROR_NO_DATA. If the databases are different the function returns NOERROR.

### `iReserved1` [in]

This is a reserved argument and must be set to 0.

### `iReserved2` [in]

This is a reserved argument and must be set to 0.

## Return value

The
**MsiDatabaseGenerateTransform** function returns one of the following values:

## Remarks

To generate a difference file between two databases, use the
**MsiDatabaseGenerateTransform** function. A transform contains information regarding insertion and deletion of columns and rows. The validation flags are stored in the summary information stream of the transform file.

For tables that exist in both databases, the only difference between the two schemas that is allowed is the addition of columns to the end of the reference table. You cannot add primary key columns to a table or change the order or names or column definitions of the existing columns as defined in the base table. In other words, if neither table contains data and columns are removed from the reference table, the resulting table is identical to the base table.

Because the list delimiter for transforms, sources and patches is a semicolon, this character should not be used for filenames or paths.

This function does not generate a Summary Information stream. Use
[MsiCreateTransformSummaryInfo](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msicreatetransformsummaryinfoa) to create the stream for an existing transform.

If *szTransformFile* is null, you can test whether two databases are identical without creating a transform. If the databases are identical, ERROR_NO_DATA is returned, NOERROR is returned if differences are found.

This function cannot be called from custom actions. A call to this function from a custom action causes the function to fail.

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiDatabaseGenerateTransform as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Database Management Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Database Transforms](https://learn.microsoft.com/windows/desktop/Msi/database-transforms)