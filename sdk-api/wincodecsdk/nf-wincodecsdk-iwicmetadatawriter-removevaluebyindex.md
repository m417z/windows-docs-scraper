# IWICMetadataWriter::RemoveValueByIndex

## Description

Removes the metadata item at the specified index.

## Parameters

### `nIndex` [in]

Type: **UINT**

The index of the metadata item to remove.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After removing an item, expect the remaining metadata items to move up to occupy the vacated metadata item location. Therefore indices for remaining metadata items as well as the count will change.