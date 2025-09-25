# ICommandTree::SetCommandTree

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **ICommandTree::SetCommandTree** method sets a command object's command tree, replacing the existing one or replacing a text command specified with the [ICommandText](https://learn.microsoft.com/previous-versions/windows/desktop/ms709737(v=vs.85)) interface. The provided command tree is copied into or transferred to, depending on the *fCopy* parameter, the command object. Thus, the consumer may delete the original tree or text without affecting the command object. Most error checking is deferred until one of the validation methods, optimization (see [ICommandPrepare](https://learn.microsoft.com/previous-versions/windows/desktop/ms713621(v=vs.85))), or the [ICommand::Execute](https://learn.microsoft.com/previous-versions/windows/desktop/ms718095(v=vs.85)) method is invoked. This method only verifies that the command tree can indeed be copied into the command object's space.

## Parameters

### `ppRoot` [in]

Pointer to the address of the root of the command tree.

### `dwCommandReuse` [in]

A mask of type [DBCOMMANDREUSE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandreuse) from the [DBCOMMANDREUSEENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/ne-cmdtree-dbcommandreuseenum) enumeration that specifies whether a state from the previous command is retained. If a state that was not previously specified is marked for reuse, the flag is ignored and no error occurs. Only DBCOMMANDREUSE_NONE is currently supported.

### `fCopy` [in]

If **TRUE**, the command tree is copied, and the caller retains ownership of the command tree's memory. If **FALSE**, the provider takes the entire tree, without copying, and sets the caller's root pointer to a **NULL** pointer. When the command object needs to deallocate the tree, it will call [IMalloc::Free](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-free) once for each node in the tree.

If *fCopy* is **FALSE**, the consumer must not change the command tree without another call to the **SetCommandTree** method. The effect of any such change is undefined. In particular, the provider can assume that the command tree has not changed between the calls that use the tree, such as **SetCommandTree**, [ICommandPrepare::Prepare](https://learn.microsoft.com/previous-versions/windows/desktop/ms718370(v=vs.85)), and [ICommand::Execute](https://learn.microsoft.com/previous-versions/windows/desktop/ms718095(v=vs.85)).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | A provider-specific error occurred. |
| **E_INVALIDARG** | Either the *pRoot* parameter was a NULL pointer or the *dwCommandReuse* parameter was invalid. |
| **DB_E_OBJECTOPEN** | A rowset was open on the command object. |

## See also

[ICommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nn-cmdtree-icommandtree)