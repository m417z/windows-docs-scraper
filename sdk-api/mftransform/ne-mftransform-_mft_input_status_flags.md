# _MFT_INPUT_STATUS_FLAGS enumeration

## Description

Indicates the status of an input stream on a Media Foundation transform (MFT).

## Constants

### `MFT_INPUT_STATUS_ACCEPT_DATA:0x1`

The input stream can receive more data at this time. To deliver more input data, call [IMFTransform::ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput).

## See also

[IMFTransform::GetInputStatus](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getinputstatus)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)