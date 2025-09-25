# IFsrmFileManagementJob::WaitForCompletion

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

Waits for the specified period of time or until the job has finished running.

## Parameters

### `waitSeconds` [in]

The number of seconds to wait for the job to complete. The method returns when the period expires or the
job complete. To wait indefinitely, set the value to –1.

### `completed` [out]

Is **VARIANT_TRUE** if the job completed; otherwise,
**VARIANT_FALSE**.

## Return value

The method returns the following return values.

## Remarks

To run the job, call the
[IFsrmFileManagementJob::Run](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-run) method. Jobs run
asynchronously, calling this method blocks your thread until the job completes or the timeout period
expires.

After **WaitForCompletion**
returns, access the
[IFsrmFileManagementJob::LastError](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_lasterror)
property to determine if the reports completed successfully.

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)