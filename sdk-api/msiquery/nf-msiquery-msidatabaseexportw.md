# MsiDatabaseExportW function

## Description

The
**MsiDatabaseExport** function exports a Microsoft Installer table from an open database to a [Text Archive File](https://learn.microsoft.com/windows/desktop/Msi/text-archive-files).

## Parameters

### `hDatabase` [in]

The handle to a database from [MsiOpenDatabase](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiopendatabasea).

### `szTableName` [in]

The name of the table to export.

### `szFolderPath` [in]

The name of the folder that contains archive files.

### `szFileName` [in]

The name of the exported table archive file.

## Return value

The
**MsiDatabaseExport** function returns one of the following values:

| Return code | Description |
| --- | --- |
| **ERROR_BAD_PATHNAME** | An invalid path is passed to the function. |
| **ERROR_FUNCTION_FAILED** | The function fails. |
| **ERROR_INVALID_HANDLE** | An invalid or inactive handle is supplied. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter is passed to the function. |
| **ERROR_SUCCESS** | The function succeeds. |

## Remarks

If a table contains streams,
**MsiDatabaseExport** exports each stream to a separate file.

For more information, see
[MsiDatabaseImport](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msidatabaseimporta).

This function cannot be called from custom actions. A call to this function from a custom action causes the function to fail.

If the function fails, you can get extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiDatabaseExport as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Database Management Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Text Archive Files](https://learn.microsoft.com/windows/desktop/Msi/text-archive-files)