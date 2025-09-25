# IWICComponentFactory::CreateMetadataWriter

## Description

Creates an [IWICMetadataWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatawriter) based on the given parameters.

## Parameters

### `guidMetadataFormat` [in]

Type: **REFGUID**

The GUID of the desired metadata format.

### `pguidVendor` [in]

Type: **const GUID***

Pointer to the GUID of the desired metadata reader vendor.

### `dwMetadataOptions` [in]

Type: **DWORD**

The [WICPersistOptions](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/ne-wincodecsdk-wicpersistoptions) and [WICMetadataCreationOptions](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/ne-wincodecsdk-wicmetadatacreationoptions) options to use when creating the metadata reader.

### `ppIWriter` [out]

Type: **[IWICMetadataWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatawriter)****

A pointer that receives a pointer to the new metadata writer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.