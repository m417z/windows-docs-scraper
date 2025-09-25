# MsiDatabaseMergeW function

## Description

The
**MsiDatabaseMerge** function merges two databases together, which allows duplicate rows.

## Parameters

### `hDatabase` [in]

The handle to the database obtained from [MsiOpenDatabase](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiopendatabasea).

### `hDatabaseMerge` [in]

The handle to the database obtained from [MsiOpenDatabase](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiopendatabasea) to merge into the base database.

### `szTableName` [in]

The name of the table to receive merge conflict information.

## Return value

The
**MsiDatabaseMerge** function returns one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_FUNCTION_FAILED** | Row merge conflicts were reported. |
| **ERROR_INVALID_HANDLE** | An invalid or inactive handle was supplied. |
| **ERROR_INVALID_TABLE** | An invalid table was supplied. |
| **ERROR_SUCCESS** | The function succeeded. |
| **ERROR_DATATYPE_MISMATCH** | Schema difference between the two databases. |

## Remarks

The **MsiDatabaseMerge** function and the [Merge](https://learn.microsoft.com/windows/desktop/Msi/database-merge) method of the
[Database](https://learn.microsoft.com/windows/desktop/Msi/database-object) object cannot be used to merge a module that is included in the installation package. They should not be used to merge
[Merge Modules](https://learn.microsoft.com/windows/desktop/Msi/merge-modules) into a Windows Installer package. To include a merge module in an installation package, authors of installation packages should follow the guidelines that are described in the [Applying Merge Modules](https://learn.microsoft.com/windows/desktop/Msi/applying-merge-modules) topic.

**MsiDatabaseMerge** does not copy over embedded
[Cabinet Files](https://learn.microsoft.com/windows/desktop/Msi/cabinet-files) or
[embedded transforms](https://learn.microsoft.com/windows/desktop/Msi/embedded-transforms) from the reference database into the target database. Embedded data streams that are listed in the
[Binary Table](https://learn.microsoft.com/windows/desktop/Msi/binary-table) or
[Icon Table](https://learn.microsoft.com/windows/desktop/Msi/icon-table) are copied from the reference database to the target database. Storage embedded in the reference database are not copied to the target database.

The
**MsiDatabaseMerge** function merges the data of two databases. These databases must have the same code page.
**MsiDatabaseMerge** fails if any tables or rows in the databases conflict. A conflict exists if the data in any row in the first database differs from the data in the corresponding row of the second database. Corresponding rows are in the same table of both databases and have the same primary key in both databases. The tables of non-conflicting databases must have the same number of primary keys, same number of columns, same column types, same column names, and the same data in rows with identical primary keys. Temporary columns however don't matter in the column count and corresponding tables can have a different number of temporary columns without creating conflict as long as the persistent columns match.

If the number, type, or name of columns in corresponding tables are different, the schema of the two databases are incompatible and the installer stops processing tables and the merge fails. The installer checks that the two databases have the same schema before checking for row merge conflicts. If ERROR_DATATYPE_MISMATCH is returned, you are guaranteed that the databases have not been changed.

If the data in particular rows differ, this is a row merge conflict, the installer returns ERROR_FUNCTION_FAILED and creates a new table named *szTableName*. The first column of this table is the name of the table having the conflict. The second column gives the number of rows in the table having the conflict. The table that reports conflicts appears as follows.

| Column | Type | Key | Nullable |
| --- | --- | --- | --- |
| Table | [Text](https://learn.microsoft.com/windows/desktop/Msi/text) | Y | N |
| NumRowMergeConflicts | [Integer](https://learn.microsoft.com/windows/desktop/Msi/integer) |  | N |

This function cannot be called from custom actions. A call to this function from a custom action causes the function to fail.

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiDatabaseMerge as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Column Definition Format](https://learn.microsoft.com/windows/desktop/Msi/column-definition-format)

[Database Management Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)