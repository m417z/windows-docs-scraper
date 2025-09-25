# MsiViewExecute function

## Description

The
**MsiViewExecute** function executes a SQL view query and supplies any required parameters. The query uses the question mark token to represent parameters as described in
[SQL Syntax](https://learn.microsoft.com/windows/desktop/Msi/sql-syntax). The values of these parameters are passed in as the corresponding fields of a parameter record.

## Parameters

### `hView` [in]

Handle to the view upon which to execute the query.

### `hRecord` [in]

Handle to a record that supplies the parameters. This parameter contains values to replace the parameter tokens in the SQL query. It is optional, so *hRecord* can be zero. For a reference on syntax, see
[SQL Syntax](https://learn.microsoft.com/windows/desktop/Msi/sql-syntax).

## Return value

Note that in low memory situations, this function can raise a STATUS_NO_MEMORY exception.

## Remarks

The
**MsiViewExecute** function must be called before any calls to
[MsiViewFetch](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiviewfetch).

If the SQL query specifies values with parameter markers (?), a record must be supplied that contains all of the replacement values in the exact order and of compatible data types. When used with INSERT and UPDATE queries all the parameterized values must precede all nonparameterized values.

For example, these queries are valid.

UPDATE {table-list} SET {column}= ? , {column}= {constant}

INSERT INTO {table} ({column-list}) VALUES (?, {constant-list})

However these queries are invalid.

UPDATE {table-list} SET {column}= {constant}, {column}=?

INSERT INTO {table} ({column-list}) VALUES ({constant-list}, ? )

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

## See also

[General Database Access Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)