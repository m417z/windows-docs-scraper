# IFsrmReportJob::WaitForCompletion

## Description

Waits for the reports in the job to complete.

## Parameters

### `waitSeconds` [in]

The number of seconds to wait for the reports to complete. The method returns when the period expires or the reports complete. To wait indefinitely, set the value to –1.

### `completed` [out]

Is **VARIANT_TRUE** if the reports completed; otherwise, **VARIANT_FALSE**.

## Return value

The method returns the following return values.

## Remarks

To run the job, call the [IFsrmReportJob::Run](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportjob-run) method.

After **WaitForCompletion** returns, access the [IFsrmReportJob::LastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportjob-get_lasterror) property to determine if the reports completed successfully.

#### Examples

For an example, see [Running a Report Job](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/running-a-report-job).

## See also

[IFsrmReportJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportjob)

[IFsrmReportJob::Run](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportjob-run)