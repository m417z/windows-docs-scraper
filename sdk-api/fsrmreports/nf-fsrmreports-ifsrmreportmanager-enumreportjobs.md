# IFsrmReportManager::EnumReportJobs

## Description

Enumerates the report jobs.

## Parameters

### `options` [in]

The options to use when enumerating the report jobs. For possible values, see the
[FsrmEnumOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmenumoptions) enumeration.

**Note** The **FsrmEnumOptions_Asynchronous** option is not supported for this
method.

### `reportJobs` [out]

An [IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection) interface that contains a
collection of the report jobs. The collection is empty if no report jobs.

Each item of the collection is a **VARIANT** of type
**VT_DISPATCH**. Query the **pdispVal** member to get the
[IFsrmReportJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportjob) interface.

The collection can contain committed and uncommitted report jobs. For an uncommitted report job to be
included in the collection, the running status of the job must be
**FsrmReportRunningStatus_Queued** or
**FsrmReportRunningStatus_Running**.

## Return value

The method returns the following return values.

## See also

[FsrmReportManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmreportmanager)

[IFsrmReportManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportmanager)