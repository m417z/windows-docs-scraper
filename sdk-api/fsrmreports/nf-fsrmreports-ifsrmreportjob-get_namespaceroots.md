# IFsrmReportJob::get_NamespaceRoots

## Description

Retrieves or sets an array of local directory paths that will be scanned when the report job is
run.

This property is read/write.

## Parameters

## Remarks

All subdirectories under the specified path are also scanned (recursively).

If you schedule this job, specify the same namespaces when calling the
[IFsrmReportScheduler::CreateScheduleTask](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportscheduler-createscheduletask)
method.

This property calls the
[IFsrmReportScheduler::VerifyNamespaces](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportscheduler-verifynamespaces)
method to validate the paths. For validation details, see the Remarks section of
**VerifyNamespaces**.

Note that FSRM supports only NTFS file systems—you cannot specify paths on ReFS, FAT,
FAT32, UDF, or other non-NTFS file system.

#### Examples

For an example, see [Defining a Report Job](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/defining-a-report-job).

## See also

[IFsrmReportJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportjob)