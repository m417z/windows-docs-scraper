# MsiDatabaseImportW function

## Description

The
**MsiDatabaseImport** function imports an installer [text archive file](https://learn.microsoft.com/windows/desktop/Msi/text-archive-files) into an open database table.

## Parameters

### `hDatabase` [in]

Handle to the database obtained from [MsiOpenDatabase](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiopendatabasea).

### `szFolderPath` [in]

Specifies the path to the folder that contains archive files.

### `szFileName` [in]

Specifies the name of the file to import.

## Return value

The
**MsiDatabaseImport** function returns one of the following values:

## Remarks

When you use the
**MsiDatabaseImport** function to import a text archive table named _SummaryInformation into an installer database, you write the "05SummaryInformation" stream. This stream contains standard properties that can be viewed using Windows Explorer and are defined by COM. The rows of the table are written to the property stream as pairs of property ID numbers and corresponding data values. See
[Summary Information Stream Property Set](https://learn.microsoft.com/windows/desktop/Msi/summary-information-stream-property-set). Date and time in _SummaryInformation are in the format: YYYY/MM/DD hh::mm::ss. For example, 1999/03/22 15:25:45. If the table contains binary streams, the name of the stream is in the data field, and the actual stream is retrieved from a file of that name in a subfolder with the same name as the table.

Text archive files that are exported from a database by
[MsiDatabaseExport](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msidatabaseexporta) are intended for use with version control systems, and are not intended to be used as a means of editing data. Use the database API functions and tools designed for that purpose. Note that control characters in text archive files are translated to avoid conflicts with file delimiters. If a text archive file contains non-ASCII data, it is stamped with the code page of the data, and can only be imported into a database of that exact code page, or into a neutral database. Neutral databases are set to the code page of the imported file. A database can be unconditionally set to a particular code page by importing a pseudo table named: _ForceCodepage. The format of such a file is: Two blank lines, followed by a line that contains the numeric code page, a tab delimiter and the exact string: _ForceCodepage

This function cannot be called from custom actions. A call to this function from a custom action causes the function to fail.

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiDatabaseImport as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Database Management Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Text Archive Files](https://learn.microsoft.com/windows/desktop/Msi/text-archive-files)