# IFsrmQuotaManager::EnumAutoApplyQuotas

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Enumerates the automatic quotas that are associated with the specified directory. The
enumeration can also include automatic quotas associated with subdirectories (recursively).

## Parameters

### `path` [in]

The local directory path that is associated with the automatic quota that you want to enumerate. The string
is limited to 260 characters.

If the path ends with "\*", retrieve all automatic quotas associated with the immediate
subdirectories of the path (does not include the quota associated with the path).

If the path ends with "\...", retrieve the automatic quota for the path and all automatic
quotas associated with the immediate subdirectories of the path (recursively).

If the path does not end in "\*" or "\...", retrieve the automatic quota
for the path only.

If path is null or empty, the method returns all quotas.

### `options` [in]

Options to use when enumerating the quotas. For possible values, see the
[FsrmEnumOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmenumoptions) enumeration.

### `quotas` [out]

An [IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection) interface
that contains a collection of the automatic quotas.

Each item of the collection is a **VARIANT** of type
**VT_DISPATCH**. Query the **pdispVal** member of the variant for
the [IFsrmAutoApplyQuota](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmautoapplyquota) interface.

The collection is empty if the path does not contain quotas.

## Return value

The method returns the following return values.

## Remarks

To enumerate quotas that do not automatically apply to the path's subdirectories, call the
[IFsrmQuotaManager::EnumQuotas](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotamanager-enumquotas)
method.

## See also

[FsrmQuotaManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmquotamanager)

[IFsrmQuotaManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotamanager)

[IFsrmQuotaManagerEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotamanagerex)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)