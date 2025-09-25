# IFsrmReportJob::get_LastGeneratedInDirectory

## Description

Retrieves the local directory path where the reports were stored the last time the reports were run.

This property is read-only.

## Parameters

## Remarks

If the reports failed, this is the path where the reports would have been stored. The directory may contain reports that completed successfully before the failure occurred.

#### Examples

For an example, see [Running a Report Job](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/running-a-report-job).

## See also

[IFsrmReportJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportjob)

[IFsrmReportManager::SetOutputDirectory](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportmanager-setoutputdirectory)