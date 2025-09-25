# IFsrmQuotaTemplateManager::ImportTemplates

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota) class.]

Imports the specified quota templates from an XML string.

## Parameters

### `serializedQuotaTemplates` [in]

An XML string that represents one or more quota templates.

### `quotaTemplateNamesArray` [in]

A variant that contains the names of the templates to import. If **NULL**, the method
imports all templates.

### `quotaTemplates` [out]

An [IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection) interface
that contains a collection of quota templates.

Each item of the collection is a **VARIANT** of type
**VT_DISPATCH**. Query the **pdispVal** member of the variant for
the [IFsrmQuotaTemplateImported](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotatemplateimported) interface.

To add the templates to FSRM, call the
[IFsrmCommittableCollection::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmcommittablecollection-commit)
method. To add the templates to FSRM and propagate the changes to objects that were derived from the template,
call the
[IFsrmFileScreenTemplateImported::CommitAndUpdateDerived](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilescreentemplate-commitandupdatederived)
method on each item in the collection.

## Return value

The method returns the following return values.

## See also

[FsrmQuotaTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmquotatemplatemanager)

[IFsrmQuotaTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotatemplatemanager)

[MSFT_FSRMQuota](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmquota)