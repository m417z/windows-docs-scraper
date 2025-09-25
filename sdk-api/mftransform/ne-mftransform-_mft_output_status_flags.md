# _MFT_OUTPUT_STATUS_FLAGS enumeration

## Description

Indicates whether a Media Foundation transform (MFT) can produce output data.

## Constants

### `MFT_OUTPUT_STATUS_SAMPLE_READY:0x1`

There is a sample available for at least one output stream. To retrieve the available output samples, call [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput).

## See also

[IMFTransform::GetOutputStatus](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputstatus)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)