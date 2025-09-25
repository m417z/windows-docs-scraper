# IFsrmExportImport::ImportQuotaTemplates

## Description

Imports one or more quota templates from the specified file.

## Parameters

### `filePath` [in]

The full path to the file from which to import the quota templates. The string is limited to 260 characters.

### `templateNamesSafeArray` [in]

A variant that contains the names of the quota templates to import. Set the variant to empty or **NULL** to import all templates.

Set the variant type to both **VT_ARRAY** and **VT_VARIANT** and the **parray** member to the **SAFEARRAY** of **BSTR**s.

### `remoteHost` [in]

The name of the remote server. To specify the local server, set to an empty string.

### `templates` [out]

An [IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection) interface that contains a collection of [IFsrmQuotaTemplateImported](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nn-fsrmquota-ifsrmquotatemplateimported) interfaces. To complete the import, you must call the [IFsrmQuotaTemplateImported::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method.

## Return value

The method returns the following return values.

## Remarks

You can also use the [IFsrmQuotaTemplateManager::ImportTemplates](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmquota/nf-fsrmquota-ifsrmquotatemplatemanager-importtemplates) method to import the templates.

## See also

[FsrmExportImport](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmexportimport)

[IFsrmExportImport](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmexportimport)