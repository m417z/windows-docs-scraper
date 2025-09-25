# IMetaDataTables2::GetMetaDataStreamInfo

## Description

Gets the name, size, and contents of the metadata stream at the specified index.

## Parameters

### `ix` [in]

The index of the requested metadata stream.

### `ppchName` [out]

A pointer to the name of the stream.

### `ppv` [out]

 A pointer to the metadata stream.

### `pcb` [out]

The size, in bytes, of *ppv*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMetaDataTables2](https://learn.microsoft.com/windows/desktop/api/rometadataapi/nn-rometadataapi-imetadatatables2)