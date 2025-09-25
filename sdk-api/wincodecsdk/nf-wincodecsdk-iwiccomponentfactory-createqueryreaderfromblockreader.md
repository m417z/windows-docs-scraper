# IWICComponentFactory::CreateQueryReaderFromBlockReader

## Description

Creates a [IWICMetadataQueryReader](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicmetadataqueryreader) from the given [IWICMetadataBlockReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatablockreader).

## Parameters

### `pIBlockReader` [in]

Type: **[IWICMetadataBlockReader](https://learn.microsoft.com/windows/desktop/api/wincodecsdk/nn-wincodecsdk-iwicmetadatablockreader)***

Pointer to the block reader to base the query reader on.

### `ppIQueryReader` [out]

Type: **[IWICMetadataQueryReader](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicmetadataqueryreader)****

A pointer that receives a pointer to the new metadata query reader.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.