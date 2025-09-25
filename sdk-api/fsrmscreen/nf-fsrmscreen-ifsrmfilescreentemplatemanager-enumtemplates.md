# IFsrmFileScreenTemplateManager::EnumTemplates

## Description

Enumerates the file screen templates on the server.

## Parameters

### `options` [in]

The options to use when enumerating the file screen templates. For possible values, see the [FsrmEnumOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmenumoptions) enumeration.

### `fileScreenTemplates` [out]

An [IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection) interface that contains a collection of file screen templates.

Each item of the collection is a **VARIANT** of type **VT_DISPATCH**. Query the **pdispVal** member of the variant for the [IFsrmFileScreenTemplate](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreentemplate) interface.

## Return value

The method returns the following return values.

## See also

[FsrmFileScreenTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmfilescreentemplatemanager)

[IFsrmFileScreenTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreentemplatemanager)