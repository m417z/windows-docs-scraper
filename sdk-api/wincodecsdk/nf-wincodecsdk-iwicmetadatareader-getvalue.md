# IWICMetadataReader::GetValue

## Description

Gets the metadata item value.

## Parameters

### `pvarSchema` [in]

Type: **const [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer to the metadata item's schema property.

### `pvarId` [in]

Type: **const [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer to the metadata item's id.

### `pvarValue` [in, out]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer that receives the metadata value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.