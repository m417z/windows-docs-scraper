# IFsrmFileGroupManager::GetFileGroup

## Description

[This method is supported for compatibility but it's recommended to use the
[FSRM WMI Classes](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-wmi-classes) to manage FSRM. Please see the
[MSFT_FSRMFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilegroup) class.]

Retrieves the specified file group from FSRM.

## Parameters

### `name` [in]

The name of the file group to retrieve. The string is limited to 4,000 characters.

### `fileGroup` [out]

An [IFsrmFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilegroup) interface to the retrieved file
group.

## Return value

The method returns the following return values.

## See also

[FsrmFileGroupManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmfilegroupmanager)

[IFsrmFileGroupManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilegroupmanager)

[MSFT_FSRMFileGroup](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmfilegroup)