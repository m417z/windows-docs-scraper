# IAppxBlockMapBlock::GetHash

## Description

Retrieves the hash value of the block.

## Parameters

### `bufferSize` [out]

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The length of *buffer*.

### `buffer` [out, retval]

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)****

The byte sequence representing the hash value of the block.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *buffer* value corresponds to the **Hash** attribute of the **Block** element.

The caller is responsible for deallocating the memory used for *buffer*. Use the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to deallocate the memory.

## See also

[IAppxBlockMapBlock](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapblock)