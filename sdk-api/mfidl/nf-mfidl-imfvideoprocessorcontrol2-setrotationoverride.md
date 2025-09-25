# IMFVideoProcessorControl2::SetRotationOverride

## Description

Overrides the rotation operation that is performed in the video processor.

## Parameters

### `uiRotation` [in]

Type: **UINT**

Rotation value in degrees. Typically, you can only use values from the [MFVideoRotationFormat](https://learn.microsoft.com/windows/desktop/api/mfapi/ne-mfapi-mfvideorotationformat) enumeration.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFVideoProcessorControl2](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideoprocessorcontrol2)