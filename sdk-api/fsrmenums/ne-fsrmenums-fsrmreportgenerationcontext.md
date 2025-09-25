# FsrmReportGenerationContext enumeration

## Description

Defines the context in which the report is initiated.

## Constants

### `FsrmReportGenerationContext_Undefined:1`

The context is unknown. Do not use this flag.

### `FsrmReportGenerationContext_ScheduledReport:2`

The report will run as a scheduled report.

### `FsrmReportGenerationContext_InteractiveReport:3`

The report will run on demand.

### `FsrmReportGenerationContext_IncidentReport:4`

The report will run in response to a quota or file screen event.

## See also

[IFsrmReportJob::Run](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportjob-run)

[IFsrmReportManager::GetOutputDirectory](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-getoutputdirectory)

[IFsrmReportManager::SetOutputDirectory](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-setoutputdirectory)