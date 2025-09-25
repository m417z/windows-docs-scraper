# IFsrmFileManagementJob::put_OperationType

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

The type of file management job. The type determines the operation to perform on a file when all
conditions are met.

This property is read/write.

## Parameters

## Remarks

If the type is **FsrmFileManagementType_Expiration**, FSRM moves the files that meet
all the file management job's conditions to the path specified by the
[ExpirationDirectory](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_expirationdirectory) property
when the job is run.

If the type is **FsrmFileManagementType_Custom**, FSRM executes the custom action
specified in the [CustomAction](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_customaction)
property for every file that meets all the file management job's conditions when the file management job is
run.

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)