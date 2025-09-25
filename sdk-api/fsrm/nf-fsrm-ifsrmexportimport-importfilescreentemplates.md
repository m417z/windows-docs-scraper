# IFsrmExportImport::ImportFileScreenTemplates

## Description

Imports one or more file screen templates from the specified file.

## Parameters

### `filePath` [in]

The full path to the file from which to import the file screen templates. The string is limited to 260 characters.

### `templateNamesSafeArray` [in]

A variant that contains the names of the file screen templates to import. Set the variant to empty or **NULL** to import all templates.

Set the variant type to both **VT_ARRAY** and **VT_VARIANT** and the **parray** member to the **SAFEARRAY** of **BSTR**s.

### `remoteHost` [in]

The name of the remote server. To specify the local server, set to an empty string.

### `templates` [out]

An [IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection) interface that contains a collection of [IFsrmFileScreenTemplateImported](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreentemplateimported) interfaces. To complete the import, you must call the [IFsrmFileScreenTemplateImported::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method.

## Return value

The method returns the following return values.

## Remarks

You can also use the [IFsrmFileScreenTemplateManager::ImportTemplates](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilescreentemplatemanager-importtemplates) method to import the templates.

## See also

[FsrmExportImport](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmexportimport)

[IFsrmExportImport](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmexportimport)