# _MFT_PROCESS_OUTPUT_STATUS enumeration

## Description

Indicates the status of a call to [IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput).

## Constants

### `MFT_PROCESS_OUTPUT_STATUS_NEW_STREAMS:0x100`

The Media Foundation transform (MFT) has created one or more new output streams.

## Remarks

If the MFT sets this flag, the [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) method returns MF_E_TRANSFORM_STREAM_CHANGE and no output data is produced. The client should respond as follows:

1. Call [IMFTransform::GetStreamCount](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamcount) to get the new number of streams.
2. Call [IMFTransform::GetStreamIDs](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamids) to get the new stream identifiers.
3. Call [IMFTransform::GetOutputAvailableType](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputavailabletype) and [IMFTransform::SetOutputType](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-setoutputtype) to set the media types on the new streams.

Until these steps are completed, all further calls to [ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput) return MF_E_TRANSFORM_STREAM_CHANGE.

## See also

[IMFTransform::ProcessOutput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processoutput)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)