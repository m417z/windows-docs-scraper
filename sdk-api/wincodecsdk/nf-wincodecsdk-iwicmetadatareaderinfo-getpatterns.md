# IWICMetadataReaderInfo::GetPatterns

## Description

Gets the metadata patterns associated with the metadata reader.

## Parameters

### `guidContainerFormat` [in]

Type: **REFGUID**

The cointainer format GUID.

### `cbSize` [in]

Type: **UINT**

The size, in bytes, of the *pPattern* buffer.

### `pPattern` [in, out]

Type: **[WICMetadataPattern](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/ns-wincodecsdk-wicmetadatapattern)***

Pointer that receives the metadata patterns.

### `pcCount` [in, out]

Type: **UINT***

Pointer that receives the number of metadata patterns.

### `pcbActual` [in, out]

Type: **UINT***

Pointer that receives the size, in bytes, needed to obtain the metadata patterns.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.