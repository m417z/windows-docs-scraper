# TXFS_CREATE_MINIVERSION_INFO structure

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Contains the version information about the miniversion created by [FSCTL_TXFS_CREATE_MINIVERSION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_create_miniversion).

## Members

### `StructureVersion`

The version number of this **TXFS_CREATE_MINIVERSION_INFO** structure.

### `StructureLength`

The length of this **TXFS_CREATE_MINIVERSION_INFO** structure.

### `BaseVersion`

The identifier of the most recently committed version of the file.

### `MiniVersion`

The identifier of the newly-created miniversion.

## See also

[CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea)

[FSCTL_TXFS_CREATE_MINIVERSION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_create_miniversion)