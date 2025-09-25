# IFsrmQuotaTemplateManager::CreateTemplate

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Creates a quota template object.

## Parameters

### `quotaTemplate` [out]

An [IFsrmQuotaTemplate](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotatemplate) interface to the newly
create template. To add the template to FSRM, call
[IFsrmQuotaTemplate::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method.

## Return value

The method returns the following return values.

## See also

[FsrmQuotaTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmquotatemplatemanager)

[IFsrmQuotaTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotatemplatemanager)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)