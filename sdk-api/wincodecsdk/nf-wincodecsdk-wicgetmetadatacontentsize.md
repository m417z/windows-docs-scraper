# WICGetMetadataContentSize function

## Description

Returns the size of the metadata content contained by the specified [IWICMetadataWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatawriter). The returned size accounts for the header and the length of the metadata.

## Parameters

### `guidContainerFormat` [in]

Type: **REFGUID**

The container GUID.

### `pIWriter` [in]

Type: **[IWICMetadataWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatawriter)***

The [IWICMetadataWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatawriter) that contains the content.

### `pcbSize` [out]

Type: **ULARGE_INTEGER***

A pointer that receives the size of the metadata content.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.