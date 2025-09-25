# IFsrmFileManagementJob::get_NamespaceRoots

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

An array of local directory paths that will be scanned when the file management job is
run.

This property is read/write.

## Parameters

## Remarks

All subdirectories under each specified path are also scanned (recursively).

If you schedule this job, specify the same namespaces when calling the
[IFsrmReportScheduler::CreateScheduleTask](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportscheduler-createscheduletask)
method.

This property calls the
[IFsrmReportScheduler::VerifyNamespaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportscheduler-verifynamespaces)
method to validate the paths. For validation details, see the Remarks section of
**VerifyNamespaces**.

Note that FSRM supports only NTFS file systems—you cannot specify paths on ReFS, FAT,
FAT32, UDF, or other non-NTFS file system.

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)