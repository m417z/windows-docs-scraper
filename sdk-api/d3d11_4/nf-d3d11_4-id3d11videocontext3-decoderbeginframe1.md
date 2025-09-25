## Description

Starts a decoding operation to decode a video frame.

## Parameters

### `pDecoder`

A pointer to the [ID3D11VideoDecoder](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11videodecoder) interface. To get this pointer, call [ID3D11VideoDevice::CreateVideoDecoder](https://learn.microsoft.com/windows/win32/api/d3d11/nf-d3d11-id3d11videodevice-createvideodecoder)

### `pView`

A pointer to a [ID3D11VideoDecoderOutputView](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11videodecoderoutputview) interface. This interface describes the resource that will receive the decoded frame. To get this pointer, call [ID3D11VideoDevice::CreateVideoDecoderOutputView](https://learn.microsoft.com/windows/win32/api/d3d11/nf-d3d11-id3d11videodevice-createvideodecoderoutputview).

### `ContentKeySize`

The size of the content key that is specified in *pContentKey*. If *pContentKey* is NULL, set *ContentKeySize* to zero.

### `pContentKey`

An optional pointer to a content key that was used to encrypt the frame data. If no content key was used, set this parameter to NULL. If the caller provides a content key, the caller must use the session key to encrypt the content key.

### `NumComponentHistograms`

The number of components to record a histograms for. Use [D3D11_FEATURE_VIDEO_DECODE_HISTOGRAM](https://learn.microsoft.com/windows/win32/api/d3d11_4/ne-d3d11_4-d3d11_feature_video) to check for support. Use zero when not recording histograms or when the feature is not supported. Specifying fewer components than are in the format implies that those components do not have histogram recording enabled. The maximum number of components is defined as **D3D11_4_VIDEO_DECODER_MAX_HISTOGRAM_COMPONENTS**.

### `pHistogramOffsets`

An array of starting buffer offset locations within the *ppHistogramBuffers* parallel array. Use [D3D11_VIDEO_DECODE_HISTOGRAM_COMPONENT](https://learn.microsoft.com/windows/win32/api/d3d11_4/ne-d3d11_4-d3d11_video_decoder_histogram_component) to index the array. If a component is not requested, specify an offset of zero. The offsets must be 256-byte aligned.

### `ppHistogramBuffers`

An array of target buffers for hardware to write the components histogram. Use [D3D11_VIDEO_DECODE_HISTOGRAM_COMPONENT](https://learn.microsoft.com/windows/win32/api/d3d11_4/ne-d3d11_4-d3d11_video_decoder_histogram_component) to index the array. Set this parameter to **nullptr** when the component histogram is disabled or unsupported

## Return value

Returns **S\_OK** if successful.

## Remarks

The following [D3D11_RESOURCE_MISC](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flags are allowed when allocating resources for video decode histograms.

- D3D11_RESOURCE_MISC_SHARED
- D3D11_RESOURCE_MISC_DRAWINDIRECT_ARGS
- D3D11_RESOURCE_MISC_BUFFER_ALLOW_RAW_VIEWS
- D3D11_RESOURCE_MISC_BUFFER_STRUCTURED
- D3D11_RESOURCE_MISC_SHARED_KEYEDMUTEX
- D3D11_RESOURCE_MISC_SHARED_NTHANDLE
- D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE
- D3D11_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE_DRIVER

All other D3D11_RESOURCE_MISC flags are disallowed.

## See also