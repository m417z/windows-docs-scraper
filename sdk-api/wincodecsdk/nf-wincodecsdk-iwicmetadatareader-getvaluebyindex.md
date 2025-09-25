# IWICMetadataReader::GetValueByIndex

## Description

Gets the metadata item at the given index.

## Parameters

### `nIndex` [in]

Type: **UINT**

The index of the metadata item to retrieve.

### `pvarSchema` [in, out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer that receives the schema property.

### `pvarId` [in, out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer that receives the id property.

### `pvarValue` [in, out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer that receives the metadata value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.