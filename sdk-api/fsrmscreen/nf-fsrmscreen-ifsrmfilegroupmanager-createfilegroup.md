# IFsrmFileGroupManager::CreateFileGroup

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilegroup) class.]

Creates a file group object.

## Parameters

### `fileGroup` [out]

An [IFsrmFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilegroup) interface to the new file group. To
add the file group to FSRM, call
[IFsrmFileGroup::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmobject-commit) method.

## Return value

The method returns the following return values.

## See also

[FsrmFileGroupManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmfilegroupmanager)

[IFsrmFileGroupManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilegroupmanager)

[MSFT_FSRMFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilegroup)