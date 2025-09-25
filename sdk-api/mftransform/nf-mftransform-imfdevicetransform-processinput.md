# IMFDeviceTransform::ProcessInput

## Description

The **ProcessInput** method delivers data to an input stream on this Media Foundation transform (MFT).

## Parameters

### `dwInputStreamID` [in]

Input stream identifier.

### `pSample` [in]

Pointer to the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface of the input sample. The sample must contain at least one media buffer that contains valid input data.

### `dwFlags` [in]

Must be zero.

## Return value

The method returns an **HRESULT**. Possible values include but not limited to values given in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | Invalid argument passed. |
| **MF_E_INVALIDREQUEST** | Device MFT could not support the request at this time. |
| **MF_E_INVAILIDSTREAMNUMBER** | An invalid stream ID was passed. |
| **MF_E_INVALID_STREAM_STATE** | The requested stream transition is not possible. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | Input media type has not been set. |

## Remarks

In most cases, if the method succeeds, the MFT stores the sample and holds a reference count on the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) pointer. When the MFT is done using the sample it must release it to avoid a memory leak.

After the DTM has set valid media types on all of the streams, the MFT should always be able to accept more input and be able to produce more output.

If an MFT encounters a non-fatal error in the input data, it can simply drop the data and attempt to recover when it gets the more input data. If the MFT drops any data, it should set the [MFSampleExtension_Discontinuity](https://learn.microsoft.com/windows/desktop/medfound/mfsampleextension-discontinuity-attribute) attribute on the next output sample, to notify the caller that there is a gap in the data stream.

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)