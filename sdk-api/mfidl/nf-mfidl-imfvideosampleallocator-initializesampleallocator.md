# IMFVideoSampleAllocator::InitializeSampleAllocator

## Description

Specifies the number of samples to allocate and the media type for the samples.

## Parameters

### `cRequestedFrames` [in]

Number of samples to allocate.

### `pMediaType` [in]

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of a media type that describes the video format.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDMEDIATYPE** | Invalid media type. |

## See also

[IMFVideoSampleAllocator](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideosampleallocator)