# IFsrmExportImport::ImportFileGroups

## Description

Imports one or more file groups from the specified file.

## Parameters

### `filePath` [in]

The full path to the file from which to import the file groups. The string is limited to 260 characters.

### `fileGroupNamesSafeArray` [in]

A variant that contains the names of the file groups to import. Set the variant to empty or **NULL** to import all file groups.

Set the variant type to both **VT_ARRAY** and **VT_VARIANT** and the **parray** member to the **SAFEARRAY** of **BSTR**s.

### `remoteHost` [in]

The name of the remote server. To specify the local server, set to an empty string.

### `fileGroups` [out]

An [IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection) interface that contains a collection of [IFsrmFileGroupImported](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilegroupimported) interfaces. To complete the import, you must call the [IFsrmFileGroupImported::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method.

## Return value

The method returns the following return values.

## Remarks

You can also use the [IFsrmFileGroupManager::ImportFileGroups](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilegroupmanager-importfilegroups) method to import the templates.

## See also

[FsrmExportImport](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmexportimport)

[IFsrmExportImport](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmexportimport)