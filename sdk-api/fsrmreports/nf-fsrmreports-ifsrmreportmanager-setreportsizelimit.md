# IFsrmReportManager::SetReportSizeLimit

## Description

Sets the current value of the specified report size limit.

## Parameters

### `limit` [in]

Identifies the limit which is used to limit the files listed in a report. For possible values, see the
[FsrmReportLimit](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreportlimit) enumeration.

### `limitValue` [in]

The limit. Must be greater than zero. You can specify the variant as a short, int, or long that is either
signed or unsigned. The method will also accept a string value. The method must be able to convert the value to
a positive, long number. For example, to pass the value as a long, set the variant type to
**VT_I4** and then set the **lVal** member of the variant to the
limit value.

## Return value

The method returns the following return values.

## Remarks

The following list lists the default limits for the
[FsrmReportLimit](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreportlimit) enumeration values used for
the *limit* parameter.

| Limit | Default value |
| --- | --- |
| **FsrmReportLimit_MaxDuplicateGroups** | 100 duplicate groups |
| **FsrmReportLimit_MaxFiles** | 1,000 files |
| **FsrmReportLimit_MaxFileGroups** | 10 groups |
| **FsrmReportLimit_MaxFileScreenEvents** | 1,000 file screen events |
| **FsrmReportLimit_MaxFilesPerDuplGroup** | 10 files per duplicate group |
| **FsrmReportLimit_MaxFilesPerFileGroup** | 100 files per group |
| **FsrmReportLimit_MaxFilesPerOwner** | 100 files per owner |
| **FsrmReportLimit_MaxFilesPerPropertyValue** | 100 files per property |
| **FsrmReportLimit_MaxOwners** | 10 owners |
| **FsrmReportLimit_MaxPropertyValues** | 10 properties |
| **FsrmReportLimit_MaxQuotas** | 1,000 quotas |
| **FsrmReportLimit_MaxFolders** | 1,000 folders |

## See also

[FsrmReportManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmreportmanager)

[IFsrmReportManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportmanager)