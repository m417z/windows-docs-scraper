# IWICComponentFactory::CreateMetadataReaderFromContainer

## Description

Creates an [IWICMetadataReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatareader) based on the given parameters.

## Parameters

### `guidContainerFormat` [in]

Type: **REFGUID**

The container format GUID to base the reader on.

### `pguidVendor` [in]

Type: **const GUID***

Pointer to the vendor GUID of the metadata reader.

### `dwOptions` [in]

Type: **DWORD**

The [WICPersistOptions](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/ne-wincodecsdk-wicpersistoptions) and [WICMetadataCreationOptions](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/ne-wincodecsdk-wicmetadatacreationoptions) options to use when creating the metadata reader.

### `pIStream` [in]

Type: **[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)***

Pointer to a stream in which to initialize the reader with. If **NULL**, the metadata reader will be empty.

### `ppIReader` [out]

Type: **[IWICMetadataReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatareader)****

A pointer that receives a pointer to the new metadata reader

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.