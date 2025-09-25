# IFsrmReportManager::SetOutputDirectory

## Description

Sets the local directory path where reports are stored.

## Parameters

### `context` [in]

The report context (for example, if the report is scheduled or runs on demand). For possible values, see
the [FsrmReportGenerationContext](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmreportgenerationcontext)
enumeration.

### `path` [in]

The full path to the local directory where the reports are stored. The path can contain environment
variables. The path is limited to 150 characters.

## Return value

The method returns the following return values.

## Remarks

The reports are stored in the following folders under the given path.

| Context | Folder |
| --- | --- |
| **FsrmReportGenerationContext_ScheduledReport** | Scheduled |
| **FsrmReportGenerationContext_InteractiveReport** | Interactive |
| **FsrmReportGenerationContext_IncidentReport** | Incident |

For example, if *path* is set to "C:\StorageReports" and
*context* is set to
**FsrmReportGenerationContext_ScheduledReport**, the path for the scheduled reports would
be "C:\StorageReports\Scheduled".

The default output directories are:

* "%systemdrive%\StorageReports\Scheduled"
* "%systemdrive%\StorageReports\Incident"
* "%systemdrive%\StorageReports\Interactive"

## See also

[FsrmReportManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmreportmanager)

[IFsrmReportManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportmanager)