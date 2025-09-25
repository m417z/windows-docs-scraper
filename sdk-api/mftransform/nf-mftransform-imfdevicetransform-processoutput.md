# IMFDeviceTransform::ProcessOutput

## Description

The **ProcessOutput** method gets the processed output from the Device MFT output streams.

## Parameters

### `dwFlags` [in]

Bitwise OR of zero or more flags from the [_MFT_PROCESS_OUTPUT_FLAGS](https://learn.microsoft.com/windows/win32/api/mftransform/ne-mftransform-_mft_process_output_flags) enumeration.

### `cOutputBufferCount` [in]

Number of elements in the *pOutputSamples* array. The value must be at least 1.

### `pOutputSample` [in]

Pointer to an array of [MFT_OUTPUT_DATA_BUFFER](https://learn.microsoft.com/windows/desktop/api/mftransform/ns-mftransform-mft_output_data_buffer) structures, allocated by the caller. The MFT uses this array to return output data to the caller.

### `pdwStatus` [in]

Receives a bitwise OR of zero or more flags from the [_MFT_PROCESS_OUTPUT_STATUS](https://learn.microsoft.com/windows/win32/api/mftransform/ne-mftransform-_mft_process_output_status) enumeration.

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

In most cases, if the method succeeds, the Media Foundation transform (MFT) stores the sample and holds a reference count on the [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) pointer. When the MFT is done using the sample, it must release it to avoid memory leaks.

After the device transform manager (DTM) has set valid media types on all of the streams, the MFT should always be able to accept more input and be able to produce more output.

If an MFT encounters a non-fatal error in the input data, it can simply drop the data and attempt to recover when it gets the more input data. If the MFT drops any data, it should set the [MFSampleExtension_Discontinuity](https://learn.microsoft.com/windows/desktop/medfound/mfsampleextension-discontinuity-attribute) attribute on the next output sample, to notify the caller that there is a gap in the data stream.

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)