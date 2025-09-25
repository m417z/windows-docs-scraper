# IFsrmQuotaManagerEx::IsAffectedByQuota

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Retrieves a value that determines whether a specified path is subject to a quota.

## Parameters

### `path` [in]

The local directory path to determine whether a quota applies.

### `options` [in]

The options to use when checking for a quota. For possible values, see the
[FsrmEnumOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmenumoptions) enumeration.

### `affected` [out]

Is **VARIANT_TRUE** if the path referred to by the
*path* parameter is subject to a quota, otherwise it is
**VARIANT_FALSE**.

## Return value

The method returns the following return values.

## See also

[IFsrmQuotaManagerEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotamanagerex)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)