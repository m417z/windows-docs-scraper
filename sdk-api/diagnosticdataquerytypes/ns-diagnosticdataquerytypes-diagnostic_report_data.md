## Description

This resource contains information about a diagnostic report.

## Members

### `signature`

Type: **[DIAGNOSTIC_DATA_REPORT_SIGNATURE](https://learn.microsoft.com/windows/win32/api/diagnosticdataquerytypes/ns-diagnosticdataquerytypes-diagnostic_report_data)**
The signature for this report.

### `bucketId`

Type: **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**
A hash of the signature. Can be used to cross reference with other crash reports with the same signature (currently not implemented).

### `reportId`

Type: **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**
A locally unique identifier for the report.

### `creationTime`

Type: **[FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime)**
A UTC time stamp of when the report was created.

### `sizeInBytes`

Type: **[ULONGLONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
The size (on disk) of the individual report and its constituent files. This value only counts files directly contained in a report.

### `cabId`

Type: **[LPWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
The ID for the cab.

### `reportStatus`

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
The detailed status of the report. Use the ReportStatus decoder to track this bit-field.

### `reportIntegratorId`

Type: **[GUID](https://learn.microsoft.com/windows/win32/api/guiddef/ns-guiddef-guid)**
The integrator ID of the report.

### `fileNames`

Type: **[LPWSTR\*](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
A pointer to hold the names of the files included in the report.

### `fileCount`

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
The number of data files included in the report.

### `friendlyEventName`

Type: **[LPWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
The display name of the application event.

### `applicationName`

Type: **[LPWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
The name of the application.

### `applicationPath`

Type: **[LPWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
The file path of the application.

### `description`

Type: **[LPWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
The description of the problem.

### `bucketIdString`

Type: **[LPWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
The bucket ID as a string (possibly truncated).

### `legacyBucketId`

Type: **[UINT64](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
The legacy bucket ID.

### `reportKey`

Type: **[LPWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**
The report key.

## Remarks

For general questions about Windows Error Reporting, see the [**WER APIS**](https://learn.microsoft.com/windows/win32/api/_wer/).
For report keys, see the [**WER APIs**](https://learn.microsoft.com/windows/win32/api/werapi/nf-werapi-werstoregetnextreportkey).

## See also