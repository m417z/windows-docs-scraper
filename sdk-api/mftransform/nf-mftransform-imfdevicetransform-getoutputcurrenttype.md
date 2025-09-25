# IMFDeviceTransform::GetOutputCurrentType

## Description

The **GetOutputCurrentType** method gets the current media type for an output stream on this Media Foundation transform (MFT).

## Parameters

### `dwOutputStreamID` [in]

Output stream identifier. To get the list of stream identifiers, call [IMFDeviceTransform::GetStreamIDs](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imfdevicetransform-getstreamids).

### `pMediaType` [out]

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface that represents the current type used by that stream.

## Return value

The method returns an **HRESULT**. Possible values include but not limited to values given in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Initialization succeeded |
| **MF_E_INVALIDREQUEST** | Device MFT could not support the request at this time. |
| **MF_E_INVALIDSTREAMNUMBER** | The stream ID is not valid. |
| **MF_E_NO_MORE_TYPES** | There is no media type available with the specified index. |
| **MF_E_TRANSFORM_TYPE_NOT_SET** | No media type has been set yet. |

## Remarks

If the specified output stream does not yet have a media type, the method returns **MF_E_TRANSFORM_TYPE_NOT_SET**.

### Implementation notes

The MFT should return a clone of the media type, not a pointer to the original type. Otherwise, the caller might modify the type and alter the internal state of the MFT.

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)