# IFsrmFileScreenTemplateManager::ImportTemplates

## Description

Imports the specified file screen templates from an XML string.

## Parameters

### `serializedFileScreenTemplates` [in]

An XML string that represents one or more file screen templates.

### `fileScreenTemplateNamesArray` [in]

A **VARIANT** that contains a **SAFEARRAY** of the names of the templates to import. If **NULL**, the method imports all templates.

### `fileScreenTemplates` [out]

An [IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection) interface that contains a collection of file screen templates.

Each item of the collection is a **VARIANT** of type **VT_DISPATCH**. Query the **pdispVal** member of the variant for the [IFsrmFileScreenTemplateImported](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreentemplateimported) interface.

To add the templates to FSRM, call the [IFsrmCommittableCollection::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmcommittablecollection-commit) method. To add the templates to FSRM and propagate the changes to objects that were derived from the template, call the [IFsrmFileScreenTemplateImported::CommitAndUpdateDerived](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilescreentemplate-commitandupdatederived) method on each item in the collection.

## Return value

The method returns the following return values.

## See also

[FsrmFileScreenTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmfilescreentemplatemanager)

[IFsrmFileScreenTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreentemplatemanager)