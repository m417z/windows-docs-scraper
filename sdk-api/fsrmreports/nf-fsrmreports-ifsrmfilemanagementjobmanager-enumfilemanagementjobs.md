# IFsrmFileManagementJobManager::EnumFileManagementJobs

## Description

Enumerates the list of existing file management jobs.

## Parameters

### `options` [in]

One or more options to use when enumerating the management jobs. For possible values, see the [FsrmEnumOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmenumoptions) enumeration.

**Note** This parameter must be set to either **FsrmEnumOptions_IncludeClusterNodes** or **FsrmEnumOptions_None** for this method.

### `fileManagementJobs` [out]

An [IFsrmCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcollection) interface that contains a collection of file management jobs. The variant type of each item in the collection is **VT_DISPATCH**. Query the **pdispVal** member of the variant to get an [IFsrmFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjob) interface to the job.

## Return value

The method returns the following return values.

## See also

[FsrmFileManagementJobManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmfilemanagementjobmanager)

[IFsrmFileManagementJobManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmfilemanagementjobmanager)

[IFsrmFileManagementJobManager::GetFileManagementJob](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmfilemanagementjobmanager-getfilemanagementjob)