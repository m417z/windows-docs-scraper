# IFsrmExportImport::ExportFileScreenTemplates

## Description

Exports one or more file screen templates to the specified file.

## Parameters

### `filePath` [in]

The full path to the export file that will contain the file screen templates in XML format. The string is limited to 260 characters.

### `templateNamesSafeArray` [in]

A variant that contains the names of the file screen templates to export. Set the variant to empty or **NULL** to export all templates.

Set the variant type to both **VT_ARRAY** and **VT_VARIANT** and the **parray** member to the **SAFEARRAY** of **BSTR**s.

### `remoteHost` [in]

The name of the remote server. To specify the local server, set to an empty string.

## Return value

This method can return the following error codes.

## Remarks

The file screen template name is specified when you call the [IFsrmFileScreenTemplateManager::CreateTemplate](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilescreentemplatemanager-createtemplate) method. To enumerate the templates, call the [IFsrmFileScreenTemplateManager::EnumTemplates](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilescreentemplatemanager-enumtemplates) method.

You can also use the [IFsrmFileScreenTemplateManager::ExportTemplates](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilescreentemplatemanager-exporttemplates) method to export the templates.

## See also

[FsrmExportImport](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmexportimport)

[IFsrmExportImport](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmexportimport)