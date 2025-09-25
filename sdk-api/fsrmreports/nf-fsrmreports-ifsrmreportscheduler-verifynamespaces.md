# IFsrmReportScheduler::VerifyNamespaces

## Description

[Starting with Windows Server 2012 this method is not supported; use the
[MSFT_FSRMScheduledTask](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmscheduledtask) WMI class to manage
scheduled tasks.]

Verifies that the specified local directory paths that are used as the source for the reports are
valid.

## Parameters

### `namespacesSafeArray` [in]

A **VARIANT** that contains a **SAFEARRAY** of local
directory paths. Each element of the array is a variant of type **VT_BSTR**. Use the
**bstrVal** member of the variant to set the path.

## Return value

The method returns the following return values.

## Remarks

If the paths are valid, you can use them when calling the
[IFsrmReportScheduler::CreateScheduleTask](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nf-fsrmreports-ifsrmreportscheduler-createscheduletask)
method.

The paths are valid if:

* All paths in the array are on NTFS volumes.
* All paths in the array are on volumes that are online accessible.
* For clusters, all paths are on volumes that are in the same failover group.

If one of the paths fails to validate, there is no indication of which path failed. To determine which path
failed, you need to call this method for each path separately. For clusters, if all paths validate, you need to
verify the cluster groups using the cluster APIs.

## See also

[FsrmReportScheduler](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmreportscheduler)

[IFsrmReportScheduler](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmreports/nn-fsrmreports-ifsrmreportscheduler)