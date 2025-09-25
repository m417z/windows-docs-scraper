# IMFVideoMediaType::GetVideoRepresentation

## Description

[This API is not supported and may be altered or unavailable in the future. Instead, applications should set the [MF_MT_DEFAULT_STRIDE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-default-stride-attribute) attribute on the media type to specify the surface stride and then call [IMFMediaType::GetRepresentation](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediatype-getrepresentation).]

Retrieves an alternative representation of the media type.

## Parameters

### `guidRepresentation` [in]

GUID that specifies the representation to retrieve. For a list of values, see [IMFMediaType::GetRepresentation](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediatype-getrepresentation).

### `ppvRepresentation` [out]

Receives a pointer to a structure that contains the representation. The method allocates the memory for the structure. The caller must release the memory by calling [IMFMediaType::FreeRepresentation](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediatype-freerepresentation).

### `lStride` [in]

Stride of the video surface, in bytes. If the stride is unknown, set this value to 0. If the value is 0, the method computes the stride from the image width and assumes that there is no padding.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is equivalent to [IMFMediaType::GetRepresentation](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediatype-getrepresentation) but includes the *lStride* parameter.

Instead of calling this method, applications should set the [MF_MT_DEFAULT_STRIDE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-default-stride-attribute) attribute on the media type to specify the surface stride and then call [IMFMediaType::GetRepresentation](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediatype-getrepresentation).

## See also

[IMFVideoMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfvideomediatype)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)