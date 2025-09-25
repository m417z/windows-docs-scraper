# IFsrmFileGroupManager::ExportFileGroups

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilegroup) class.]

Exports the specified file groups as an XML string.

## Parameters

### `fileGroupNamesArray` [in]

A **VARIANT** that contains a **SAFEARRAY** of the names
of the file groups to export. If **NULL**, the method exports all file groups.

### `serializedFileGroups` [out]

The specified file groups in XML format.

## Return value

The method returns the following return values.

## Remarks

Typically, you use this method to save the file groups information to a file. You can then copy the file to
another computer and call the
[IFsrmFileGroupManager::ImportFileGroups](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilegroupmanager-importfilegroups)
method to import the file groups.

## See also

[FsrmFileGroupManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmfilegroupmanager)

[IFsrmFileGroupManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilegroupmanager)

[MSFT_FSRMFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilegroup)