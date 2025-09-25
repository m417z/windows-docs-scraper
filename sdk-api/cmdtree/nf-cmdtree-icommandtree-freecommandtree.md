# ICommandTree::FreeCommandTree

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **ICommandTree::FreeCommandTree** method traverses a command tree and deallocates all [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) node structures, as well as all variants in those structures. It then sets the root pointer to a **NULL** pointer.

## Parameters

### `ppRoot` [in]

Pointer to a variable that receives the pointer to the root of the command tree on successful exit.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | A provider-specific error occurred. |
| **E_INVALIDARG** | The *ppRoot* parameter was a **NULL** pointer. |
| **DB_E_CANNOTFREE** | The consumer called the [ICommandTree::SetCommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nf-cmdtree-icommandtree-setcommandtree) method with *fCopy* = **FALSE**, thereby relinquishing ownership of the memory to the provider. |

## Remarks

The **FreeCommandTree** method can be used by a consumer to free its copy of the command tree constructed locally or obtained by [ICommandTree::GetCommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nf-cmdtree-icommandtree-getcommandtree). It does not free the copy of the tree owned by the command object. When a consumer calls [SetCommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nf-cmdtree-icommandtree-setcommandtree) with *fCopy* = **FALSE**, the consumer relinquishes ownership of the memory to the provider. Therefore, if the consumer calls **FreeCommandTree** after having called **SetCommandTree** with *fCopy* = **FALSE**, **FreeCommandTree** returns a DB_E_CANNOTFREE error code, meaning the consumer does not have ownership of the tree and is unable to free it.

## See also

[ICommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nn-cmdtree-icommandtree)