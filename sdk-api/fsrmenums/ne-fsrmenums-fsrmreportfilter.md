# FsrmReportFilter enumeration

## Description

Defines the filters that you can use to limit the files that are included in a report.

## Constants

### `FsrmReportFilter_MinSize:1`

The report will show only files that meet a minimum size.

Applies to the **FsrmReportType_LargeFiles** report type.

### `FsrmReportFilter_MinAgeDays:2`

The report will show only files that were accessed more than a minimum number of days ago.

Applies to the **FsrmReportType_LeastRecentlyAccessed** and
**FsrmReportType_FileScreenAudit** report types.

### `FsrmReportFilter_MaxAgeDays:3`

The report will show only files that were accessed prior to a maximum number of days ago.

Applies to the **FsrmReportType_MostRecentlyAccessed** report type.

### `FsrmReportFilter_MinQuotaUsage:4`

The report will show only quotas that meet a certain disk space usage level.

Applies to the **FsrmReportType_QuotaUsage** report type.

### `FsrmReportFilter_FileGroups:5`

The report will show only files from a specified set of file groups.

Applies to the **FsrmReportType_FilesByType** report type.

### `FsrmReportFilter_Owners:6`

The report will show only files that belong to specified owners. The format of the owner string can be either
the user principal name
("*UserName*@*Domain*" or
"*Domain*\*UserName*") or a SID in string
format.

Applies to the **FsrmReportType_FilesByOwner** report type.

### `FsrmReportFilter_NamePattern:7`

The report will show only files with names that match the specified pattern.

Applies to the **FsrmReportType_LargeFiles**,
**FsrmReportType_MostRecentlyAccessed**,
**FsrmReportType_LeastRecentlyAccessed**,
**FsrmReportType_FilesByOwner**, and
**FsrmReportType_FilesByProperty** report types. For these report types, multiple
filters could exist. For example, for the **FsrmReportType_LargeFiles** report type,
both the **FsrmReportFilter_MinSize** and
**FsrmReportFilter_NamePattern** filters could exist.

### `FsrmReportFilter_Property:8`

The report will show only files that contain the specified property.

Applies to the **FsrmReportType_FilesByProperty** and
**FsrmReportType_FoldersByProperty** report types.

## Remarks

The value for the filter is specified when you call the
[IFsrmReport::SetFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreport-setfilter) or
[IFsrmReportManager::SetDefaultFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-setdefaultfilter)
method to specify the filter. For example, you set the *filterValue* parameter to the
filter's value when calling **SetFilter**.

## See also

[IFsrmReport::GetFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreport-getfilter)

[IFsrmReport::SetFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreport-setfilter)

[IFsrmReportManager::GetDefaultFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-getdefaultfilter)

[IFsrmReportManager::IsFilterValidForReportType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-isfiltervalidforreporttype)

[IFsrmReportManager::SetDefaultFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-setdefaultfilter)