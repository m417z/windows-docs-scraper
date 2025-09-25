# IFsrmQuotaManager::GetRestrictiveQuota

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Retrieves the most restrictive quota for the specified path.

## Parameters

### `path` [in]

The local directory path. The string is limited to 260 characters.

### `quota` [out]

An [IFsrmQuota](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquota) interface to the quota object.

## Return value

The method returns the following return values.

## Remarks

The most restrictive quota is the one with the lowest quota limit. If a quota higher in the directory tree
has a lower limit than the quota associated with the specified path, the former quota is returned. If two quotas
have the same limit, the quota that is higher in the directory tree is returned.

## See also

[FsrmQuotaManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmquotamanager)

[IFsrmQuotaManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotamanager)

[IFsrmQuotaManagerEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotamanagerex)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)