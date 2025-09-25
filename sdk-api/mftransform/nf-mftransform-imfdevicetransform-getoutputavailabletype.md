# IMFDeviceTransform::GetOutputAvailableType

## Description

The **GetOutputAvailableType** method gets an available media type for an output stream on this Media Foundation transform (MFT).

## Parameters

### `dwOutputStreamID` [in]

Output stream identifier. To get the list of stream identifiers, call [IMFDeviceTransform::GetStreamIDs](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imfdevicetransform-getstreamids).

### `dwTypeIndex` [in]

Index of the media type to retrieve. Media types are indexed from zero and returned in approximate order of preference.

### `pMediaType` [out]

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface.

## Return value

The method returns an **HRESULT**. Possible values include but not limited to values given in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Initialization succeeded |
| **MF_E_INVALIDREQUEST** | Device MFT could not support the request at this time. |
| **MF_E_INVALIDSTREAMNUMBER** | The stream ID is not valid. |
| **MF_E_NO_MORE_TYPES** | There is no media type available with the specified index. |

## Remarks

The MFT defines a list of available media types for each output stream and orders them by preference.

This method enumerates the available media types for an output stream. To enumerate the available types, increment *dwTypeIndex* until the method returns **MF_E_NO_MORE_TYPES**.

### Implementation notes

If the MFT stores a media type internally, the MFT should return a clone of the media type, not a pointer to the original type. Otherwise, the caller might modify the type and alter the internal state of the MFT.

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)