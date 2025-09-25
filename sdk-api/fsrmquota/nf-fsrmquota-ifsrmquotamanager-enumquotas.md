# IFsrmQuotaManager::EnumQuotas

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Enumerates the quotas for the specified directory and any quotas associated with its subdirectories
(recursively).

## Parameters

### `path` [in]

The local directory path that is associated with the quota that you want to enumerate. The string is limited
to 260 characters.

If the path ends with "\*", retrieve all quotas associated with the immediate subdirectories
of the path (does not include the quota associated with the path).

If the path ends with "\...", retrieve the quota for the path and all quotas associated with
the immediate subdirectories of the path (recursively).

If the path does not end in "\*" or "\...", retrieve the quota for the path
only.

If path is null or empty, the method returns all quotas.

### `options` [in]

Options to use when enumerating the quotas. For possible values, see the
[FsrmEnumOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmenumoptions) enumeration.

### `quotas` [out]

An [IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection) interface
that contains a collection of the quotas.

Each item of the collection is a **VARIANT** of type
**VT_DISPATCH**. Query the **pdispVal** member of the variant for
the [IFsrmQuota](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquota) interface.

The collection is empty if the path does not contain quotas.

## Return value

The method returns the following return values.

## Remarks

To enumerate quotas that apply automatically to the path's subdirectories, call the
[IFsrmQuotaManager::EnumAutoApplyQuotas](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotamanager-enumautoapplyquotas)
method.

## See also

[FsrmQuotaManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmquotamanager)

[IFsrmQuotaManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotamanager)

[IFsrmQuotaManagerEx](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotamanagerex)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)