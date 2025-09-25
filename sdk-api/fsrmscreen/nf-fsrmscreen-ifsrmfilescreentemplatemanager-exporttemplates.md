# IFsrmFileScreenTemplateManager::ExportTemplates

## Description

Exports the templates as an XML string.

## Parameters

### `fileScreenTemplateNamesArray` [in]

A variant that contains the names of the file screen templates to export. If **NULL**, the method exports all file screens.

### `serializedFileScreenTemplates` [out]

The specified templates in XML format.

## Return value

The method returns the following return values.

## Remarks

Typically, you use this method to save the templates to a file. You can then copy the file to another computer and call the [IFsrmFileScreenTemplateManager::ImportTemplates](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilescreentemplatemanager-importtemplates) method to import the templates.

## See also

[FsrmFileScreenTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmfilescreentemplatemanager)

[IFsrmFileScreenTemplateManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreentemplatemanager)