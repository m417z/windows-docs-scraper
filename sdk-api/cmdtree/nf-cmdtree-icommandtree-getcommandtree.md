# ICommandTree::GetCommandTree

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **ICommandTree::GetCommandTree** method echoes the current command as a tree, including all post-processing operations that have been added.

## Parameters

### `ppRoot` [out]

The command object allocates memory for the command tree and returns the address to this memory; the consumer releases this memory with [IMalloc::Free](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-free), one node at a time, when it no longer needs the command tree. The provider sets *ppRoot* to a null pointer if an error occurs.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **DB_S_ERRORSINTREE** | The provider discovered nonfatal errors in the command text previously set by [ICommandText::SetCommandText](https://learn.microsoft.com/previous-versions/windows/desktop/ms709757(v=vs.85)) while building the command tree. |
| **E_FAIL** | A provider-specific error occurred. |
| **E_INVALIDARG** | The *ppRoot* parameter was a null pointer. |
| **E_OUTOFMEMORY** | The provider was unable to allocate sufficient memory in which to return the command tree. |
| **DB_E_CANTTRANSLATE** | The provider cannot represent the command text previously set by [ICommandText::SetCommandText](https://learn.microsoft.com/previous-versions/windows/desktop/ms709757(v=vs.85)) as a tree. |

## Remarks

The returned tree reflects exactly the command set by the last invocation of [ICommandTree::SetCommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nf-cmdtree-icommandtree-setcommandtree) or [ICommandText::SetCommandText](https://learn.microsoft.com/previous-versions/windows/desktop/ms709757(v=vs.85)), as modified by subsequent calls to **IQuery::AddPostProcessing**. If the command is stored as a tree, the returned tree is a copy of the one stored in the command object. If a tree node was passed with text, it is also echoed as text. If the command is stored as text, the provider should return a "navigable" command-tree representation of the text, which is not necessarily in optimized form. If the provider cannot create a full representation, the command tree can consist of a single text node. For example, if the tree can be represented as a DBOP_SQL_select node, and the provider supports that node, it must be returned in that format. However, if the tree cannot be represented as a DBOP_SQL_select node, but can be represented in a nontrivial command tree (that is, in a type other than DBOP_text_command), the provider must return it as that nontrivial tree. The provider may only return the tree as the trivial DBOP_text_command node, if that is the only command node it supports. Otherwise, it must return a valid, non-trivial navigable tree or return DB_E_CANTTRANSLATE if the text cannot be represented in such a tree. At this time, the provider should not make any unnecessary validation, such as binding, but if in the course of parsing the provider discovers nonfatal errors in building the tree, it should put the error information in the tree and return DB_S_ERRORSINTREE.

This method does not reveal a provider's internal, optimized translation (which may be different from a [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure) of text to (non-text) tree operations.

## See also

[ICommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nn-cmdtree-icommandtree)