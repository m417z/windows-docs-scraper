# IMFVideoProcessorControl2::GetSupportedHardwareEffects

## Description

Returns the list of supported effects in the currently configured video processor.

## Parameters

### `puiSupport` [out]

Type: **UINT***

A combination of [D3D11_VIDEO_PROCESSOR_AUTO_STREAM_CAPS](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_video_processor_auto_stream_caps)-typed values that are combined by using a bitwise OR operation. The resulting value specifies the list of supported effect capabilities.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFVideoProcessorControl2](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideoprocessorcontrol2)