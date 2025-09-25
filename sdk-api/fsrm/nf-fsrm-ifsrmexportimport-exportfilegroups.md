# IFsrmExportImport::ExportFileGroups

## Description

Exports one or more file groups to the specified file.

## Parameters

### `filePath` [in]

The full path to the export file that will contain the file groups in XML format. The string is limited to
260 characters.

### `fileGroupNamesSafeArray` [in]

A variant that contains the names of the file groups to export. Set the variant to empty or
**NULL** to export all file groups.

Set the variant type to both
**VT_ARRAY** and **VT_VARIANT** and the
**parray** member to the **SAFEARRAY** of
**BSTR**s.

### `remoteHost` [in]

The name of the remote server. To specify the local server, set to an empty string.

## Return value

This method can return the following error codes.

## Remarks

The file group name is specified when you call the
[IFsrmFileGroupManager::CreateFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilegroupmanager-createfilegroup)
method. To enumerate the file groups, call the
[IFsrmFileGroupManager::EnumFileGroups](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilegroupmanager-enumfilegroups)
method.

You can also use the
[IFsrmFileGroupManager::ExportFileGroups](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilegroupmanager-exportfilegroups)
method to export the templates.

## See also

[FsrmExportImport](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmexportimport)

[IFsrmExportImport](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmexportimport)