# FILESHARE_CHANGE_ENUM enumeration

## Description

Contains the possible change events that are used by the
[FILESHARE_CHANGE](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-fileshare_change) structure to describe an entry in a
file share event notification list.

## Constants

### `FILESHARE_CHANGE_NONE`

This is a place holder value and is not a valid event.

### `FILESHARE_CHANGE_ADD`

A new file share resource has been created and will be included with the other file shares managed by the
File Server resource.

### `FILESHARE_CHANGE_DEL`

A file share resource has been deleted and will be removed from the file shares managed by the File Server
resource.

### `FILESHARE_CHANGE_MODIFY`

One or more properties of an existing file share resource have been changed.

## Remarks

**NNLEN** is defined by ClusAPI.h as follows.

``` syntax
#define NNLEN       80                  // Net name length (share name)
```

## See also

[FILESHARE_CHANGE](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-fileshare_change)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)