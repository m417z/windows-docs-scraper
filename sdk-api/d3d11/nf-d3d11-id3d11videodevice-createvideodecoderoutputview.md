# ID3D11VideoDevice::CreateVideoDecoderOutputView

## Description

Creates a resource view for a video decoder, describing the output sample for the decoding operation.

## Parameters

### `pResource` [in]

A pointer to the [ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource) interface of the decoder surface. The resource must be created with the **D3D11_BIND_DECODER** flag. See [D3D11_BIND_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag).

### `pDesc` [in]

A pointer to a [D3D11_VIDEO_DECODER_OUTPUT_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_video_decoder_output_view_desc) structure that describes the view.

### `ppVDOVView` [out]

Receives a pointer to the [ID3D11VideoDecoderOutputView](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodecoderoutputview) interface. The caller must release the interface. If this parameter is **NULL**, the method checks whether the view is supported, but does not create the view.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Set the *ppVDOVView* parameter to **NULL** to test whether a view is supported.

## See also

[ID3D11VideoDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11videodevice)