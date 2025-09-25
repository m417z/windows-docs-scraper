# MsiViewModify function

## Description

The
**MsiViewModify** function updates a fetched record.

## Parameters

### `hView` [in]

Handle to a view.

### `eModifyMode` [in]

Specifies the modify mode. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MSIMODIFY_SEEK**<br><br>-1 | Refreshes the information in the supplied record without changing the position in the result set and without affecting subsequent fetch operations. The record may then be used for subsequent Update, Delete, and Refresh. All primary key columns of the table must be in the query and the record must have at least as many fields as the query. Seek cannot be used with multi-table queries. This mode cannot be used with a view containing joins. See also the remarks. |
| **MSIMODIFY_REFRESH**<br><br>0 | Refreshes the information in the record. Must first call [MsiViewFetch](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewfetch) with the same record. Fails for a deleted row. Works with read-write and read-only records. |
| **MSIMODIFY_INSERT**<br><br>1 | Inserts a record. Fails if a row with the same primary keys exists. Fails with a read-only database. This mode cannot be used with a view containing joins. |
| **MSIMODIFY_UPDATE**<br><br>2 | Updates an existing record. Nonprimary keys only. Must first call [MsiViewFetch](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewfetch). Fails with a deleted record. Works only with read-write records. |
| **MSIMODIFY_ASSIGN**<br><br>3 | Writes current data in the cursor to a table row. Updates record if the primary keys match an existing row and inserts if they do not match. Fails with a read-only database. This mode cannot be used with a view containing joins. |
| **MSIMODIFY_REPLACE**<br><br>4 | Updates or deletes and inserts a record into a table. Must first call [MsiViewFetch](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewfetch) with the same record. Updates record if the primary keys are unchanged. Deletes old row and inserts new if primary keys have changed. Fails with a read-only database. This mode cannot be used with a view containing joins. |
| **MSIMODIFY_MERGE**<br><br>5 | Inserts or validates a record in a table. Inserts if primary keys do not match any row and validates if there is a match. Fails if the record does not match the data in the table. Fails if there is a record with a duplicate key that is not identical. Works only with read-write records. This mode cannot be used with a view containing joins. |
| **MSIMODIFY_DELETE**<br><br>6 | Remove a row from the table. You must first call the [MsiViewFetch](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewfetch) function with the same record. Fails if the row has been deleted. Works only with read-write records. This mode cannot be used with a view containing joins. |
| **MSIMODIFY_INSERT_TEMPORARY**<br><br>7 | Inserts a temporary record. The information is not persistent. Fails if a row with the same primary key exists. Works only with read-write records. This mode cannot be used with a view containing joins. |
| **MSIMODIFY_VALIDATE**<br><br>8 | Validates a record. Does not validate across joins. You must first call the [MsiViewFetch](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewfetch) function with the same record. Obtain validation errors with [MsiViewGetError](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewgeterrora). Works with read-write and read-only records. This mode cannot be used with a view containing joins. |
| **MSIMODIFY_VALIDATE_NEW**<br><br>9 | Validate a new record. Does not validate across joins. Checks for duplicate keys. Obtain validation errors by calling [MsiViewGetError](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewgeterrora). Works with read-write and read-only records. This mode cannot be used with a view containing joins. |
| **MSIMODIFY_VALIDATE_FIELD**<br><br>10 | Validates fields of a fetched or new record. Can validate one or more fields of an incomplete record. Obtain validation errors by calling [MsiViewGetError](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewgeterrora). Works with read-write and read-only records. This mode cannot be used with a view containing joins. |
| **MSIMODIFY_VALIDATE_DELETE**<br><br>11 | Validates a record that will be deleted later. You must first call [MsiViewFetch](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewfetch). Fails if another row refers to the primary keys of this row. Validation does not check for the existence of the primary keys of this row in properties or strings. Does not check if a column is a foreign key to multiple tables. Obtain validation errors by calling [MsiViewGetError](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewgeterrora). Works with read-write and read-only records. This mode cannot be used with a view that contains joins. |

### `hRecord` [in]

Handle to the record to modify.

## Return value

The
**MsiViewModify** function returns the following values:

Note that in low memory situations, this function can raise a STATUS_NO_MEMORY exception.

## Remarks

The MSIMODIFY_VALIDATE, MSIMODIFY_VALIDATE_NEW, MSIMODIFY_VALIDATE_FIELD, and MSIMODIFY_VALIDATE_DELETE values of the
**MsiViewModify** function do not perform actual updates; they ensure that the data in the record is valid. Use of these validation enumerations requires that the database contains the
[_Validation table](https://learn.microsoft.com/windows/desktop/Msi/-validation-table).

You can call MSIMODIFY_UPDATE or MSIMODIFY_DELETE with a record immediately after using MSIMODIFY_INSERT, MSIMODIFY_INSERT_TEMPORARY, or MSIMODIFY_SEEK provided you have NOT modified the 0th field of the inserted or sought record.

To execute any SQL statement, a view must be created. However, a view that does not create a result set, such as CREATE TABLE, or INSERT INTO, cannot be used with
**MsiViewModify** to update tables though the view.

You cannot fetch a record that contains binary data from one database and then use that record to insert the data into another database. To move binary data from one database to another, you should export the data to a file and then import it into the new database using a query and the
[MsiRecordSetStream](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msirecordsetstreama). This ensures that each database has its own copy of the binary data.

Note that custom actions can only add, modify, or remove temporary rows, columns, or tables from a database. Custom actions cannot modify persistent data in a database, such as data that is a part of the database stored on disk. For more information, see
[Accessing the Current Installer Session from Inside a Custom Action](https://learn.microsoft.com/windows/desktop/Msi/accessing-the-current-installer-session-from-inside-a-custom-action).

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

## See also

[General Database Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)