# IWICDdsEncoder::CreateNewFrame

## Description

Creates a new frame to encode.

## Parameters

### `ppIFrameEncode` [out]

A pointer to the newly created frame object.

### `pArrayIndex` [out, optional]

Points to the location where the array index is returned.

### `pMipLevel` [out, optional]

Points to the location where the mip level index is returned.

### `pSliceIndex` [out, optional]

Points to the location where the slice index is returned.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This is equivalent to [IWICBitmapEncoder::CreateNewFrame](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicbitmapencoder-createnewframe), but returns additional information about the array index, mip level and slice of the newly created frame. In contrast to **IWICBitmapEncoder::CreateNewFrame**, there is no [IPropertyBag2](https://learn.microsoft.com/windows/desktop/wic/-wic-codec-ipropertybag2-write-proxy)* parameter because individual DDS frames do not have separate properties.

## See also

[IWICDdsEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicddsencoder)

[WICDdsParameters](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicddsparameters)