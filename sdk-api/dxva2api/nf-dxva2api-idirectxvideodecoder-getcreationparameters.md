# IDirectXVideoDecoder::GetCreationParameters

## Description

Retrieves the parameters that were used to create this device.

## Parameters

### `pDeviceGuid` [out]

Receives the device GUID. This parameter can be **NULL**.

### `pVideoDesc` [out]

Pointer to a [DXVA2_VideoDesc](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_videodesc) structure that receives a description of the video format. This parameter can be **NULL**.

### `pConfig` [out]

Pointer to a [DXVA2_ConfigPictureDecode](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_configpicturedecode) structure that receives the decoder configuration. This parameter can be **NULL**.

### `pDecoderRenderTargets` [out]

Receives an array of **IDirect3DSurface9** interface pointers. These pointers represent the decoder render targets. The method allocates the memory for the array and calls **AddRef** on each of the pointers. The caller must release the pointers and call [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to free the memory for the array. This parameter can be **NULL**.

### `pNumSurfaces` [out]

Receives the number of elements in the *pppDecoderRenderTargets* array. This parameter can be **NULL**.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | Invalid argument. At least one parameter must be non-**NULL**. |

## Remarks

You can set any parameter to **NULL** if you are not interested in the result. At least one parameter must be non-**NULL**.

If you specify a non-**NULL** value for *pppDecoderRenderTargets* (to receive the render target surfaces), then *pNumSurfaces* cannot be **NULL**, because it receives the size of the array returned in *pppDecoderRenderTargets*.

## See also

[DirectX Video Acceleration 2.0](https://learn.microsoft.com/windows/desktop/medfound/directx-video-acceleration-2-0)

[IDirectXVideoDecoder](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideodecoder)