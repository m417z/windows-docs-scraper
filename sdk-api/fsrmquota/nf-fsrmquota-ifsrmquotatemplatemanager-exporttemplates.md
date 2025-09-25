# IFsrmQuotaTemplateManager::ExportTemplates

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Exports the quota templates as an XML string.

## Parameters

### `quotaTemplateNamesArray` [in]

A variant that contains the names of the quota templates to export. If
**NULL**, the method exports all quotas.

### `serializedQuotaTemplates` [out]

The specified templates in XML format.

## Return value

The method returns the following return values.

## Remarks

Typically, you use this method to save the templates to a file. You can then copy the file to another computer
and call the
[IFsrmQuotaTemplateManager::ImportTemplates](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotatemplatemanager-importtemplates)
method to import the templates.

## See also

[FsrmQuotaTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmquotatemplatemanager)

[IFsrmQuotaTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotatemplatemanager)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)