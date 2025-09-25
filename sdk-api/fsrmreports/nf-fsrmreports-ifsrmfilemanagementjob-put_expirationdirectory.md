# IFsrmFileManagementJob::put_ExpirationDirectory

## Description

[This property is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob) class.]

The root directory that will contain the expired files.

This property is read/write.

## Parameters

## Remarks

FSRM moves the files that meet all of the file management job's conditions to this directory when the job is
run, therefore the running process must have write permission. The directory must also be located on an NTFS
volume.

FSRM maintains the file's current directory structure in the expired directory so you can determine its
previous location. For example, if FSRM expired the file,
"C:\TestExpired\Test1.txt", the expired root directory would contain:

"*FsrmServer(FQDN)*\*JobName*_*TimeStamp*\C$\TestExpired\Test1.txt"

The expired file's ACLs are maintained with the file.

If the expiration directory does not exist, FSRM creates the directory (with administrator access rights
only).

Do not specify an expiration directory that is in the
[NamespaceRoots](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_namespaceroots) path.

Specify only if [OperationType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjob-get_operationtype)
is **FsrmFileManagementType_Expiration**.

## See also

[IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob)

[MSFT_FSRMFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilemanagementjob)