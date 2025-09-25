# IWICMetadataWriter::SetValueByIndex

## Description

Sets the metadata item to the specified index.

## Parameters

### `nIndex` [in]

Type: **UINT**

The index to place the metadata item.

### `pvarSchema` [in]

Type: **const [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer to the schema property of the metadata item.

### `pvarId` [in]

Type: **const [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer to the id property of the metadata item.

### `pvarValue` [in]

Type: **const [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer to the metadata value to set at the given index.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

After removing an item, expect the remaining metadata items to move up to occupy the vacated metadata item location. Therefore indices for remaining metadata items as well as the count will change.