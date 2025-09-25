# IFsrmFileScreenManager::CreateFileScreenCollection

## Description

Creates an empty collection to which you can add file screens.

## Parameters

### `collection` [out]

An [IFsrmCommittableCollection](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nn-fsrm-ifsrmcommittablecollection) interface to the newly created collection. To add an object to the collection, call the [IFsrmMutableCollection::Add](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmmutablecollection-add) method.

## Return value

The method returns the following return values.

## Remarks

After adding the file screens to the collection, call the [IFsrmCommittableCollection::Commit](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmcommittablecollection-commit) method.

## See also

[FsrmFileScreenManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmfilescreenmanager)

[IFsrmFileScreenManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreenmanager)