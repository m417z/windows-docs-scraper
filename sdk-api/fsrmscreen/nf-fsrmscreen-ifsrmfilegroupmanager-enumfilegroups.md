# IFsrmFileGroupManager::EnumFileGroups

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilegroup) class.]

Enumerates the file groups in FSRM.

## Parameters

### `options` [in]

One or more options for enumerating the file groups. For possible values, see the
[FsrmEnumOptions](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmenumoptions) enumeration.

### `fileGroups` [out]

An [IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection) interface
that contains a collection of file groups. Each item of the collection is a
**VARIANT** of type **VT_DISPATCH**. Query the
**pdispVal** member of the variant for the
[IFsrmFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilegroup) interface.

The collection contains only committed file groups; the collection will not contain newly created file groups
that have not been committed.

## Return value

The method returns the following return values.

## See also

[FsrmFileGroupManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmfilegroupmanager)

[IFsrmFileGroupManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilegroupmanager)

[MSFT_FSRMFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilegroup)