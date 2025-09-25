# IFsrmQuotaTemplateManager::GetTemplate

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Retrieves the specified quota template.

## Parameters

### `name` [in]

The name of the quota template to retrieve. The string is limited to 4,000 characters.

### `quotaTemplate` [out]

An [IFsrmQuotaTemplate](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotatemplate) interface to the retrieved
template object.

## Return value

The method returns the following return values.

## See also

[FsrmQuotaTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmquotatemplatemanager)

[IFsrmQuotaTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotatemplatemanager)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)