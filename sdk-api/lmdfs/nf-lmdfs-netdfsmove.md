# NetDfsMove function

## Description

Renames or moves a DFS link.

## Parameters

### `OldDfsEntryPath` [in]

Pointer to a string that specifies the source path for the move operation. This value must be a DFS link or
the path prefix of any DFS link in the DFS namespace.

### `NewDfsEntryPath` [in]

Pointer to a string that specifies the destination path for the move operation. This value must be a path or
a DFS link in the same DFS namespace.

### `Flags` [in]

A set of flags that describe actions to take when moving the link.

#### DFS_MOVE_FLAG_REPLACE_IF_EXISTS (0x00000001)

If the destination path is already an existing DFS link, replace it as part of the move operation.

## Return value

If the function succeeds, the return value is **NERR_Success**.

If the function fails, the return value is a system error code. For a list of error codes, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The **NetDfsMove** function conveniently moves a link from an
old name to a new one. In the past, it has been necessary to perform the non-trivial action of deleting an
incorrect or old link and creating a new one, which becomes cumbersome when the link has a significant number of
targets or has per-target properties (like priority) set. It is also common for administrators to regularly
rename or move links.

DFS paths supplied to **NetDfsMove** can be either an actual
DFS link or just a DFS link path prefix. Wildcards are not allowed and only absolute paths can be specified.
Relative paths and special path name syntax (such as "." or "..") are not allowed.

When a DFS link path prefix is specified instead of a complete DFS path, the move operation is performed on all
DFS links which contain that prefix. Therefore, a single call to
**NetDfsMove** can "move" multiple links. However, the path
prefix must resolve to at least one valid DFS link or the move operation will fail.

The following examples demonstrate different move operations and the results.

1. * Old path: \\MyDfsServer\MyDfsShare\dir1\dir2\link1
   * New path: \\MyDfsServer\MyDfsShare\dir1\dir2\link2After the move, \\MyDfsServer\MyDfsShare\dir1\dir2\link1 is replaced with
   \\MyDfsServer\MyDfsShare\dir1\dir2\link2.
2. * Old path: \\MyDfsServer\MyDfsShare\dir1\dir2\link1
   * New path: \\MyDfsServer\MyDfsShare\dir3\dir4\dir5\link2After the move, \\MyDfsServer\MyDfsShare\dir1\dir2\link1 is replaced with
   \\MyDfsServer\MyDfsShare\dir3\dir4\dir5\link2. Note that both the leaf and non-leaf components
   have been renamed, and that the number of components in the new path has changed.
3. * Old path: \\MyDfsServer\MyDfsShare\dir1
   * New path: \\MyDfsServer\MyDfsShare\dir3After the move, all links prefixed with \\MyDfsServer\MyDfsShare\dir1 have that prefix replaced
   with \\MyDfsServer\MyDfsShare\dir3. Therefore,
   \\MyDfsServer\MyDfsShare\dir1\dir2\link1 and \\MyDfsServer\MyDfsShare\dir1\dir2\link2
   are now \\MyDfsServer\MyDfsShare\dir3\dir2\link1 and
   \\MyDfsServer\MyDfsShare\dir3\dir2\link1, respectively.
4. * Old path: \\MyDfsServer\MyDfsShare\dir1
   * New path: \\MyDfsServer\MyDfsShareAfter the move, all links prefixed with \\MyDfsServer\MyDfsShare\dir1 have that prefix replaced
   with \\MyDfsServer\MyDfsShare. Therefore, \\MyDfsServer\MyDfsShare\dir1\dir2\link1
   and \\MyDfsServer\MyDfsShare\dir1\dir2\link2 are now
   \\MyDfsServer\MyDfsShare\dir2\link1 and \\MyDfsServer\MyDfsShare\dir2\link1,
   respectively.

If the new path already has an existing entry, **DFS_MOVE_FLAG_REPLACE_IF_EXISTS** must
be specified if the new path should overwrite the old one. When this flag is set, the collided path is deleted
and replaced by the new link. Note that any operation which can potentially result in DFS links that completely
overlap will fail, whether or not **DFS_MOVE_FLAG_REPLACE_IF_EXISTS** is specified. For
example:

* Existing links: \\MyDfsServer\MyDfsShare\dir1\link1,
  \\MyDfsServer\MyDfsShare\link3
* Old path:\\MyDfsServer\MyDfsShare\dir1
* New path: \\MyDfsServer\MyDfsShare\link3

If the move operation were allowed to succeed, the result would be two completely overlapping links:
\\MyDfsServer\MyDfsShare\link3\link1 and \\MyDfsServer\MyDfsShare\link3. Therefore, the
move operation must fail.

With domain-based DFS servers, the move operation is atomic; that is, either the whole operation is performed
or it fails. However, with stand-alone DFS servers, the move operation is not guaranteed to be atomic. In this
situation, a failure may result in a partially completed move operation and will require cleanup on behalf of the
calling application.

When the move operation succeeds, it is guaranteed that the DFS metadata was successfully modified. This does
not guarantee that the DFS links were actually created on the root targets or that DFS links can be created on
the root targets' storage.

## See also

[Distributed File System (DFS) Functions](https://learn.microsoft.com/previous-versions/windows/desktop/dfs/distributed-file-system-dfs-functions)

[Network Management Functions](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management-functions)

[Network Management Overview](https://learn.microsoft.com/windows/desktop/NetMgmt/network-management)