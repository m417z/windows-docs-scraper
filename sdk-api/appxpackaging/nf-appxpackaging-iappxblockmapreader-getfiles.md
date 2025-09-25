# IAppxBlockMapReader::GetFiles

## Description

Retrieves an enumerator for traversing the files listed in the block map.

## Parameters

### `enumerator` [out, retval]

Type: **[IAppxBlockMapFilesEnumerator](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapfilesenumerator)****

The enumerator of all the files listed in the block map.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IAppxBlockMapReader](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapreader)