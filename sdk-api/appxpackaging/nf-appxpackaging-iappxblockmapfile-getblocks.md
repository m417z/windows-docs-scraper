# IAppxBlockMapFile::GetBlocks

## Description

Retrieves an enumerator for traversing the blocks of a file listed in the block map.

## Parameters

### `blocks` [out, retval]

Type: **[IAppxBlockMapBlocksEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapblocksenumerator)****

The enumerator for traversing the blocks.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxBlockMapFile](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapfile)