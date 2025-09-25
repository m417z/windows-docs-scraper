# TXFS_GET_TRANSACTED_VERSION structure

## Description

[Microsoft strongly recommends developers utilize alternative means to achieve your
application’s needs. Many scenarios that TxF was developed for can be achieved through simpler and more readily
available techniques. Furthermore, TxF may not be available in future versions of Microsoft Windows. For more
information, and alternatives to TxF, please see
[Alternatives to using Transactional NTFS](https://learn.microsoft.com/windows/desktop/FileIO/deprecation-of-txf).]

Contains the information about the base and latest versions of the specified file.

## Members

### `ThisBaseVersion`

The version of the file that this handle is opened with. This member can be one of the following
values.

| Value | Meaning |
| --- | --- |
| **TXFS_TRANSACTED_VERSION_NONTRANSACTED**<br><br>0xFFFFFFFE | The file is not a transacted file. |
| **TXFS_TRANSACTED_VERSION_UNCOMMITTED**<br><br>0xFFFFFFFF | The file has been opened as a transacted writer. |

If the handle has been opened as a transacted reader, the value returned for this member is a positive
integer that represents the version number of the file the handle is associated with.

### `LatestVersion`

The most recently committed version of the file.

### `ThisMiniVersion`

If the handle to a miniversion is open, this member contains the ID of the miniversion. If the handle is
not open, this member is zero (0).

### `FirstMiniVersion`

 The first available miniversion for this file. If there are no miniversions, or they are not visible to
the transaction bound to the file handle, this field is zero (0).

### `LatestMiniVersion`

The latest available miniversion for this file. If there are no miniversions, or they are not visible to
the transaction bound to the file handle, this field is zero (0).

## Remarks

The base version number remains the same for the lifetime of a handle. The latest version number increases as
long as a handle is still open to a file and a change is committed. When the handle is closed, the version number
is reset to zero.

## See also

[FSCTL_TXFS_GET_TRANSACTED_VERSION](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-fsctl_txfs_get_transacted_version)