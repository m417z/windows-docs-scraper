# ICommandTree::FindErrorNodes

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

The **ICommandTree::FindErrorNodes** method traverses a command tree and returns an array of nodes with errors in them.

## Parameters

### `pRoot` [in]

A pointer to the root of the command tree.

### `pcErrorNodes` [out]

A pointer to memory in which to return the number of nodes containing errors.

### `prgErrorNodes` [out]

A pointer to memory in which to return an array of pointers to nodes that contain errors. The command object allocates memory for this array and returns the address to this memory; the consumer releases this memory with [IMalloc::Free](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-free) when it no longer needs the array. If **pcErrorNodes* is 0 on output, the provider does not allocate any memory and thus ensures that **prgErrorNodes* is a null pointer on output.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_FAIL** | A provider-specific error occurred. |
| **E_INVALIDARG** | *pRoots*, *pcErrorNodes*, or *prgErrorNodes* was a null pointer. |
| **E_OUTOFMEMORY** | The provider was unable to allocate sufficient memory in which to return the array of pointers to nodes containing errors. |

## See also

[ICommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nn-cmdtree-icommandtree)