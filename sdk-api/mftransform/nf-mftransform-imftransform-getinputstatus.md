# IMFTransform::GetInputStatus

## Description

Queries whether an input stream on this Media Foundation transform (MFT) can accept more data.

## Parameters

### `dwInputStreamID` [in]

Input stream identifier. To get the list of stream identifiers, call [IMFTransform::GetStreamIDs](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamids).

### `pdwFlags` [out]

Receives a member of the [_MFT_INPUT_STATUS_FLAGS](https://learn.microsoft.com/windows/win32/api/mftransform/ne-mftransform-_mft_input_status_flags) enumeration, or zero. If the value is **MFT_INPUT_STATUS_ACCEPT_DATA**, the stream specified in *dwInputStreamID* can accept more input data.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDSTREAMNUMBER** | Invalid stream identifier. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | The media type is not set on one or more streams. |

## Remarks

If the method returns the **MFT_INPUT_STATUS_ACCEPT_DATA** flag, you can deliver an input sample to the specified stream by calling [IMFTransform::ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput). If the method succeeds but does not return any flags in the *pdwFlags* parameter, it means the input stream already has as much data as it can accept.

Use this method to test whether the input stream is ready to accept more data, without incurring the overhead of allocating a new sample and calling [ProcessInput](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-processinput).

After the client has set valid media types on all of the streams, the MFT should always be in one of two states: Able to accept more input, or able to produce more output (or both).

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTGetInputStatus**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)