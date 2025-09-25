# IWICMetadataWriter::RemoveValue

## Description

Removes the metadata item that matches the given parameters.

## Parameters

### `pvarSchema` [in]

Type: **const [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer to the metadata schema property.

### `pvarId` [in]

Type: **const [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer to the metadata id property.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.