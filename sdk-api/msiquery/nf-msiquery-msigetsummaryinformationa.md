# MsiGetSummaryInformationA function

## Description

The
**MsiGetSummaryInformation** function obtains a handle to the _SummaryInformation stream for an installer database. This function returns a handle that should be closed using
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle).

## Parameters

### `hDatabase` [in]

Handle to the database.

### `szDatabasePath` [in]

Specifies the path to the database.

### `uiUpdateCount` [in]

Specifies the maximum number of updated values.

### `phSummaryInfo` [out]

Pointer to the location from which to receive the summary information handle.

## Return value

The
**MsiGetSummaryInformation** function returns the following values:

## Remarks

If the database specified by the
**MsiGetSummaryInformation** function is not open, you must specify 0 for *hDatabase* and specify the path to the database in *szDatabasePath*. If the database is open, you must set *szDatabasePath* to 0.

If a value of *uiUpdateCount* greater than 0 is used to open an existing summary information stream,
[MsiSummaryInfoPersist](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msisummaryinfopersist) must be called before closing the *phSummaryInfo* handle. Failing to do this will lose the existing stream information.

To view the summary information of a patch using **MsiGetSummaryInformation**, set *szDatabasePath* to the path to the patch. Alternately, you can create a handle to the patch using
[MsiOpenDatabase](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msiopendatabasea) and then pass that handle to
**MsiGetSummaryInformation** as the *hDatabase* parameter.

Note that it is recommended to use variables of type PMSIHANDLE because the installer closes PMSIHANDLE objects as they go out of scope, whereas you must close MSIHANDLE objects by calling
[MsiCloseHandle](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiclosehandle). For more information see [Use PMSIHANDLE instead of HANDLE](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices) section in the [Windows Installer Best Practices](https://learn.microsoft.com/windows/desktop/Msi/windows-installer-best-practices).

If the function fails, you can obtain extended error information by using [MsiGetLastErrorRecord](https://learn.microsoft.com/windows/desktop/api/msiquery/nf-msiquery-msigetlasterrorrecord).

> [!NOTE]
> The msiquery.h header defines MsiGetSummaryInformation as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Summary Information Property Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions)

[Summary Information Stream Property Set](https://learn.microsoft.com/windows/desktop/Msi/summary-information-stream-property-set)