# IAppxBlockMapBlock::GetCompressedSize

## Description

Retrieves compressed size of the block.

## Parameters

### `size` [out, retval]

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The compressed size of the block, in bytes.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This size corresponds to the compressed size of the block.

The *size* value corresponds to the **Size** attribute of the [Block](https://learn.microsoft.com/uwp/schemas/blockmapschema/element-block) element in the block map.

## See also

[IAppxBlockMapBlock](https://learn.microsoft.com/windows/desktop/api/appxpackaging/nn-appxpackaging-iappxblockmapblock)