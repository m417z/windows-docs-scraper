# IMFTransform::GetOutputStatus

## Description

Queries whether the Media Foundation transform (MFT) is ready to produce output data.

## Parameters

### `pdwFlags` [out]

Receives a member of the [_MFT_OUTPUT_STATUS_FLAGS](https://learn.microsoft.com/windows/win32/api/mftransform/ne-mftransform-_mft_output_status_flags) enumeration, or zero. If the value is **MFT_OUTPUT_STATUS_SAMPLE_READY**, the MFT can produce an output sample.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | Not implemented. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | The media type is not set on one or more streams. |

## Remarks

If the method returns the **MFT_OUTPUT_STATUS_SAMPLE_READY** flag, it means you can generate one or more output samples by calling [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput).

MFTs are not required to implement this method. If the method returns **E_NOTIMPL**, you must call [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) to determine whether the transform has output data.

If the MFT has more than one output stream, but it does not produce samples at the same time for each stream, it can set the **MFT_OUTPUT_STATUS_SAMPLE_READY** flag when just one stream is ready. However, if the MFT normally produces samples at the same time for each output stream, it should not set this flag until all streams are ready.

After the client has set valid media types on all of the streams, the MFT should always be in one of two states: Able to accept more input, or able to produce more output.

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTGetOutputStatus**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)