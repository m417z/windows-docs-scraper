# FsrmReportType enumeration

## Description

Defines the types of reports that you can generate.

## Constants

### `FsrmReportType_Unknown:0`

The report type is unknown. Do not use this flag.

### `FsrmReportType_LargeFiles:1`

Lists files that are larger than a specified size. Set the filter value to the size, in bytes.

### `FsrmReportType_FilesByType:2`

Lists groups of files. Create a file group and use file name patterns to specify the members of the group.
Set the filter value to the name of the file group.

### `FsrmReportType_LeastRecentlyAccessed:3`

Lists files that have not been accessed in the last *n* days. Specify the filter
value in days.

### `FsrmReportType_MostRecentlyAccessed:4`

Lists files that have been accessed in the last *n* days. Specify the filter value
in days.

### `FsrmReportType_QuotaUsage:5`

Lists quotas that exceed the specified threshold. Set the filter value to the threshold.

### `FsrmReportType_FilesByOwner:6`

Lists files grouped by their owner. Set the filter value to the list of owners whose files you want
included in the report.

### `FsrmReportType_ExportReport:7`

Lists all files in the scope of the report job; there is no filtering. You can specify the XML or CSV file
formats only for this report type. This report cannot be sent through email.

For an action report, the scope is based on the quota or file screen event that initiated the report.

### `FsrmReportType_DuplicateFiles:8`

Lists duplicate files. All files with the same file name, file size, and last modify time under the scope
of the report job are considered duplicates. For example, if the scope of the report is C:\ and
D:\ and file file1.txt exists in C:\*folder1*\,
C:\*folder2*\ and D:\*folder1*\ with
the same modify time and file size, then the files are considered duplicates.

### `FsrmReportType_FileScreenAudit:9`

Lists file screening events that have occurred.

### `FsrmReportType_FilesByProperty:10`

Lists files, grouped by property value, that contain the specified property (you can specify only one
property on which to report).

**Windows Server 2008:** This report type is not supported before Windows Server 2008 R2.

### `FsrmReportType_AutomaticClassification:11`

For internal use only; do not specify.

**Windows Server 2008:** This report type is not supported before Windows Server 2008 R2.

### `FsrmReportType_Expiration:12`

For internal use only; do not specify.

**Windows Server 2008:** This report type is not supported before Windows Server 2008 R2.

### `FsrmReportType_FoldersByProperty:13`

Lists folders, grouped by property value, that contain the specified property (you can specify only one
property on which to report).

**Windows Server 2008 R2 and Windows Server 2008:** This report type is not supported before Windows Server 2012.

## Remarks

To specify the values for report types that require a filter (for example, listing files over a specified
size), call the
[IFsrmReportManager::SetDefaultFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-setdefaultfilter)
method.

## See also

[FSRM Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-enumerations)

[IFsrmActionReport::ReportTypes](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmactionreport-get_reporttypes)

[IFsrmReport::Type](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreport-get_type)

[IFsrmReportJob::CreateReportCreateReport](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportjob-createreport)

[IFsrmReportManager::GetDefaultFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-getdefaultfilter)

[IFsrmReportManager::IsFilterValidForReportType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-isfiltervalidforreporttype)

[IFsrmReportManager::SetDefaultFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-setdefaultfilter)

[MSFT_FSRMAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmaction)