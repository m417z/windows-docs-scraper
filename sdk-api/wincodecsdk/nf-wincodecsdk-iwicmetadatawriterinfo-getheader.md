# IWICMetadataWriterInfo::GetHeader

## Description

Gets the metadata header for the metadata writer.

## Parameters

### `guidContainerFormat` [in]

Type: **REFGUID**

The format container GUID to obtain the header for.

### `cbSize` [in]

Type: **UINT**

The size of the *pHeader* buffer.

### `pHeader` [in, out]

Type: **[WICMetadataHeader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/ns-wincodecsdk-wicmetadataheader)***

Pointer that receives the [WICMetadataHeader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/ns-wincodecsdk-wicmetadataheader).

### `pcbActual` [in, out]

Type: **UINT***

The actual size of the header.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.