# FsrmReportLimit enumeration

## Description

Defines the limit used to limit the files included in a report.

## Constants

### `FsrmReportLimit_MaxFiles:1`

The report will list up to a maximum number of files. Applies to all report types.

### `FsrmReportLimit_MaxFileGroups:2`

A **FsrmReportType_FilesByType** report will list up to a maximum number of file
groups.

### `FsrmReportLimit_MaxOwners:3`

A **FsrmReportType_FilesByOwner** report will list up to a maximum number of
owners.

### `FsrmReportLimit_MaxFilesPerFileGroup:4`

A **FsrmReportType_FilesByProperty** report will list up to a maximum number of
files per file group.

### `FsrmReportLimit_MaxFilesPerOwner:5`

A **FsrmReportType_FilesByOwner** report will be limited to a maximum number of
files per owner.

### `FsrmReportLimit_MaxFilesPerDuplGroup:6`

A **FsrmReportType_DuplicateFiles** report will list up to a maximum number of
files per duplicated file group.

### `FsrmReportLimit_MaxDuplicateGroups:7`

A **FsrmReportType_DuplicateFiles** report will list up to a maximum number of
duplicated file groups.

### `FsrmReportLimit_MaxQuotas:8`

A **FsrmReportType_QuotaUsage** report will list up to a maximum number of
quotas.

### `FsrmReportLimit_MaxFileScreenEvents:9`

A **FsrmReportType_FileScreenAudit** report will list up to a maximum number of
file screen events.

### `FsrmReportLimit_MaxPropertyValues:10`

A **FsrmReportType_FilesByProperty** report will list up to a maximum number of
property values.

### `FsrmReportLimit_MaxFilesPerPropertyValue:11`

A **FsrmReportType_FilesByProperty** report will list up to a maximum number of
files per property value.

### `FsrmReportLimit_MaxFolders:12`

A **FsrmReportType_FolderByProperty** report will list up to a maximum number of
folders.

**Windows Server 2008 R2 and Windows Server 2008:** This report limit is not supported before Windows Server 2012.

## Remarks

You specify the value for the limit in the *limitValue* parameter when calling the
[IFsrmReportManager::SetReportSizeLimit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-setreportsizelimit)
method.

## See also

[FsrmReportType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreporttype)

[IFsrmReportManager::GetReportSizeLimit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-getreportsizelimit)

[IFsrmReportManager::SetReportSizeLimit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-setreportsizelimit)