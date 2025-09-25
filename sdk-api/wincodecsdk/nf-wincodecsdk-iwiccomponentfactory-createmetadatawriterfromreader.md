# IWICComponentFactory::CreateMetadataWriterFromReader

## Description

Creates an [IWICMetadataWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatawriter) from the given [IWICMetadataReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatareader).

## Parameters

### `pIReader` [in]

Type: **[IWICMetadataReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatareader)***

Pointer to the metadata reader to base the metadata writer on.

### `pguidVendor` [in]

Type: **const GUID***

Pointer to the GUID of the desired metadata reader vendor.

### `ppIWriter` [out]

Type: **[IWICMetadataWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatawriter)****

A pointer that receives a pointer to the new metadata writer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.