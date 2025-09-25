# IWICComponentFactory::CreateQueryWriterFromBlockWriter

## Description

Creates a [IWICMetadataQueryWriter](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicmetadataquerywriter) from the given [IWICMetadataBlockWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatablockwriter).

## Parameters

### `pIBlockWriter` [in]

Type: **[IWICMetadataBlockWriter](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatablockwriter)***

Pointer to the metadata block reader to base the metadata query writer on.

### `ppIQueryWriter` [out]

Type: **[IWICMetadataQueryWriter](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicmetadataquerywriter)****

A pointer that receives a pointer to the new metadata query writer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.