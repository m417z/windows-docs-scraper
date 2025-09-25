# IFsrmQuotaManager::Scan

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Starts a quota scan on the specified path.

## Parameters

### `strPath` [in]

The local directory path to scan.

## Return value

The method returns the following return values.

## Remarks

Although quota usage is monitored on an ongoing basis, there may be some instances in which the quota usage
may be out of sync with the actual usage, in which case you can call this method to refresh the quota usage. For
example, if an administrator disables a quota (to investigate or troubleshoot an issue) and later enables it, then
this method should be called to perform a manual scan.

## See also

[FsrmQuotaManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmquotamanager)

[IFsrmQuotaManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotamanager)

[IFsrmQuotaManagerEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotamanagerex)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)