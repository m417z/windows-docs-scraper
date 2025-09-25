# IWICDdsEncoder::SetParameters

## Description

Sets DDS-specific data.

## Parameters

### `pParameters` [out]

Type: **[WICDdsParameters](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicddsparameters)***

Points to the structure where the information is described.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You cannot call this method after you have started to write frame data, for example by calling [IWICDdsEncoder::CreateNewFrame](https://learn.microsoft.com/windows/desktop/api/wincodec/nf-wincodec-iwicddsencoder-createnewframe).

Setting DDS parameters using this method provides the DDS encoder with information about the expected number of frames and the dimensions and other parameters of each frame. The DDS encoder will fail if you do not set frame data that matches these expectations. For example, if you set [WICDdsParameters::Width](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicddsparameters) and **Height** to 32, and **MipLevels** to 6, the DDS encoder will expect 6 frames with the following dimensions:

* 32x32 pixels.
* 16x16 pixels.
* 8x8 pixels.
* 4x4 pixels.
* 2x2 pixels.
* 1x1 pixels.

## See also

[IWICDdsEncoder](https://learn.microsoft.com/windows/desktop/api/wincodec/nn-wincodec-iwicddsencoder)

[WICDdsParameters](https://learn.microsoft.com/windows/desktop/api/wincodec/ns-wincodec-wicddsparameters)