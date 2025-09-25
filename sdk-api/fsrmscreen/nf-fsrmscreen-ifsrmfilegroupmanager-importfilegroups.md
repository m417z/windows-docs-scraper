# IFsrmFileGroupManager::ImportFileGroups

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilegroup) class.]

Imports the specified file groups from an XML string.

## Parameters

### `serializedFileGroups` [in]

An XML string that represents one or more file groups.

### `fileGroupNamesArray` [in]

A **VARIANT** that contains a **SAFEARRAY** of the names
of the file groups to import. If **NULL**, the method imports all file groups.

### `fileGroups` [out]

An [IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection) interface
that contains a collection of file groups.

Each item of the collection is a **VARIANT** of type
**VT_DISPATCH**. Query the **pdispVal** member of the variant for
the [IFsrmFileGroupImported](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilegroupimported) interface.

To add the file groups to FSRM, call the
[IFsrmCommittableCollection::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmcommittablecollection-commit)
method.

## Return value

The method returns the following return values.

## See also

[FsrmFileGroupManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmfilegroupmanager)

[IFsrmFileGroupManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilegroupmanager)

[MSFT_FSRMFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilegroup)