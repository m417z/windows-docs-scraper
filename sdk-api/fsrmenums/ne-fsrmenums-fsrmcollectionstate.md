# FsrmCollectionState enumeration

## Description

Defines the possible states of a collection object.

## Constants

### `FsrmCollectionState_Fetching:1`

The collection object is fetching data.

### `FsrmCollectionState_Committing:2`

The collection object is committing its data.

### `FsrmCollectionState_Complete:3`

The collection object is complete (has stopped fetching or committing data).

### `FsrmCollectionState_Cancelled:4`

The collection operation (fetching or committing) was canceled.

## See also

[IFsrmCollection::State](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmcollection-get_state)