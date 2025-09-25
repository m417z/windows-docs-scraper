# CLS_ARCHIVE_DESCRIPTOR structure

## Description

Used by the [GetNextLogArchiveExtent](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-getnextlogarchiveextent) function to return information about log archive extents.

## Members

### `coffLow`

The offset in the container to the first byte of the archive extent.

### `coffHigh`

The offset in the container to the last byte of the archive extent.

### `infoContainer`

The container information structure that describes the container associated with the archive extent. For more information, see [CLFS_CONTAINER_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_container_information).

## See also

[CLFS_CONTAINER_INFORMATION](https://learn.microsoft.com/windows/desktop/api/clfs/ns-clfs-cls_container_information)

[GetNextLogArchiveExtent](https://learn.microsoft.com/windows/desktop/api/clfsw32/nf-clfsw32-getnextlogarchiveextent)