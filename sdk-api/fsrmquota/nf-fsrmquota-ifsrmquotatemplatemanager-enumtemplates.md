# IFsrmQuotaTemplateManager::EnumTemplates

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Enumerates the quota templates on the server.

## Parameters

### `options` [in]

Options to use when enumerating the quota templates. For possible values, see the
[FsrmEnumOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmenumoptions) enumeration.

### `quotaTemplates` [out]

An [IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection) interface
that contains a collection of quota templates.

Each item of the collection is a **VARIANT** of type
**VT_DISPATCH**. Query the **pdispVal** member of the variant for
the [IFsrmQuotaTemplate](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotatemplate) interface.

## Return value

The method returns the following return values.

## See also

[FsrmQuotaTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmquotatemplatemanager)

[IFsrmQuotaTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotatemplatemanager)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)