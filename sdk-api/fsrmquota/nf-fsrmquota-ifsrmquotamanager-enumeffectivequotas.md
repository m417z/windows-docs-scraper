# IFsrmQuotaManager::EnumEffectiveQuotas

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Enumerates all the quotas that affect the specified path.

## Parameters

### `path` [in]

A local directory path. The string is limited to 260 characters.

### `options` [in]

Options to use when enumerating the quotas. For possible values, see the
[FsrmEnumOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmenumoptions) enumeration.

### `quotas` [out]

An [IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection) interface
that contains a collection of the quotas configured at or above the specified path.

Each item of the collection is a **VARIANT** of type
**VT_DISPATCH**. Query the **pdispVal** member of the variant for
the [IFsrmQuota](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquota) interface.

The collection is empty if the path does not contain quotas.

## Return value

The method returns the following return values.

## Remarks

Does not enumerate automatic quotas. To enumerate automatic quotas, call the
[IFsrmQuotaManager::EnumAutoApplyQuotas](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotamanager-enumautoapplyquotas)
method.

To enumerate all quotas, call the
[IFsrmQuotaManager::EnumQuotas](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotamanager-enumquotas) method.

## See also

[FsrmQuotaManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmquotamanager)

[IFsrmQuotaManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotamanager)

[IFsrmQuotaManagerEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotamanagerex)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)