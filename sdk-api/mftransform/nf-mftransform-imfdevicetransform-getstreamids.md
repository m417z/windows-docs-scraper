# IMFDeviceTransform::GetStreamIDs

## Description

The **GetStreamIDs** method gets the stream identifiers for the input and output streams on this Media Foundation transform (MFT).

## Parameters

### `dwInputIDArraySize` [in]

The number of elements in *pdwInputStreamIDs*

### `pdwInputStreamIds` [out]

 A pointer to an array allocated by the caller. The method fills the array with the input stream identifiers. The array size must be at least equal to the number of input streams. To get the number of input streams, call [IMFDeviceTransform::GetStreamCount](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imfdevicetransform-getstreamcount).

If the caller passes an array that is larger than the number of input streams, the MFT must not write values into the extra array entries.

### `dwOutputIDArraySize` [out]

The number of elements in *pdwOutputStreamIDs*.

### `pdwOutputStreamIds`

A pointer to an array allocated by the caller. The method fills the array with the output stream identifiers. The array size must be at least equal to the number of output streams. To get the number of output streams, call [IMFDeviceTransform::GetStreamCount](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imfdevicetransform-getstreamcount).

## Return value

The method returns an **HRESULT**. Possible values include but not limited to values given in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | Transitioning the stream state succeeded. |
| **E_POINTER** | Invalid pointer passed. |
| **MF_E_BUFFERTOOSMALL** | The buffer coming in does not have enough space to fill in the stream IDs. |

## Remarks

Stream identifiers are necessary because some MFTs can add or remove streams, so the index of a stream may not be unique. Therefore, [IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform) methods that operate on streams take stream identifiers.

All input stream identifiers must be unique within an MFT, and all output stream identifiers must be unique. However, an input stream and an output stream can share the same identifier.
I

If the client adds an input stream, the client assigns the identifier, so the MFT must allow arbitrary identifiers, as long as they are unique. If the MFT creates an output stream, the MFT assigns the identifier.

By convention, if an MFT has exactly one fixed input stream and one fixed output stream, it should assign the identifier 0 to both streams.

## See also

[IMFDeviceTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imfdevicetransform)