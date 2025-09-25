# IFsrmFileManagementJob::get_Logging

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

The types of logging to perform.

This property is read/write.

## Parameters

## Remarks

The log files are stored in the reports directory. The name of the
**FsrmFileManagementLoggingFlags_ClassificationsInLogFile** log file is
"FileManagement-*FsrmServerName(FQDN)*-*FileManagementJobName*-*NotificationPeriod*-*TimeStamp*.xml".
The log file contains one entry for each file processed. Each log entry specifies the following items:

* File name (full path)
* Owner
* Command type
* Command parameters
* Error value

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)