# IMFTransform::GetStreamIDs

## Description

Gets the stream identifiers for the input and output streams on this Media Foundation transform (MFT).

## Parameters

### `dwInputIDArraySize` [in]

Number of elements in the *pdwInputIDs* array.

### `pdwInputIDs` [out]

Pointer to an array allocated by the caller. The method fills the array with the input stream identifiers. The array size must be at least equal to the number of input streams. To get the number of input streams, call [IMFTransform::GetStreamCount](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamcount).

If the caller passes an array that is larger than the number of input streams, the MFT must not write values into the extra array entries.

### `dwOutputIDArraySize` [in]

Number of elements in the *pdwOutputIDs* array.

### `pdwOutputIDs` [out]

Pointer to an array allocated by the caller. The method fills the array with the output stream identifiers. The array size must be at least equal to the number of output streams. To get the number of output streams, call [GetStreamCount](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getstreamcount).

If the caller passes an array that is larger than the number of output streams, the MFT must not write values into the extra array entries.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOTIMPL** | Not implemented. See Remarks. |
| **MF_E_BUFFERTOOSMALL** | One or both of the arrays is too small. |

## Remarks

Stream identifiers are necessary because some MFTs can add or remove streams, so the index of a stream may not be unique. Therefore, [IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform) methods that operate on streams take stream identifiers.

This method can return **E_NOTIMPL** if both of the following conditions are true:

* The transform has a fixed number of streams.
* The streams are numbered consecutively from 0 to n – 1, where n is the number of input streams or output streams. In other words, the first input stream is 0, the second is 1, and so on; and the first output stream is 0, the second is 1, and so on.

This method must be implemented if any of the following conditions is true:

* The MFT can add or remove output streams.
* The MFT allows the client to add or remove input streams.
* The stream identifiers are not consecutive.

All input stream identifiers must be unique within an MFT, and all output stream identifiers must be unique. However, an input stream and an output stream can share the same identifier.

If the client adds an input stream, the client assigns the identifier, so the MFT must allow arbitrary identifiers, as long as they are unique. If the MFT creates an output stream, the MFT assigns the identifier.

By convention, if an MFT has exactly one fixed input stream and one fixed output stream, it should assign the identifier 0 to both streams.

If **MFT_UNIQUE_METHOD_NAMES** is defined before including mftransform.h, this method is renamed **MFTGetStreamIDs**. See [Creating Hybrid DMO/MFT Objects](https://learn.microsoft.com/windows/desktop/medfound/comparison-of-mfts-and-dmos).

## See also

[IMFTransform](https://learn.microsoft.com/windows/desktop/api/mftransform/nn-mftransform-imftransform)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)