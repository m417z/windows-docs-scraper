# CIBuildQueryTree function

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

Builds a query restriction tree for a Command object.

## Parameters

### `pExistingTree`

A pointer to a [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure representing the tree. This parameter can be **NULL**.

### `dbBoolOp`

The operation to be performed on the node. See [DBCOMMANDOP](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandop).

### `cSiblings`

The number of sibling nodes for this node.

### `ppSibsToCombine`

A pointer to the address that contains the array of [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structures for the siblings to be combined with this node using the operation in *dbBoolOp*.

### `ppTree`

The address of the location to receive a pointer to the [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure for the tree structure.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **E_ACCESSDENIED** | The function was denied access to the specified path. |
| **E_HANDLE** | The function encountered an invalid handle, probably due to a low-memory situation. |
| **E_INVALIDARG** | The number of operands (siblings) for the specified *dbBoolOp* is not correct. |
| **E_OUTOFMEMORY** | The function did not have sufficient memory or other resources to complete the operation. |
| **E_FAIL** | An unknown error has occurred. |

## See also

[CIBuildQueryNode](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-cibuildquerynode)

[CITextToFullTree](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-citexttofulltree)

[CITextToFullTreeEx](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-citexttofulltreeex)

[CITextToSelectTree](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-citexttoselecttree)

[CITextToSelectTreeEx](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-citexttoselecttreeex)

[DBCOMMANDOP](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandop)

[DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree)

