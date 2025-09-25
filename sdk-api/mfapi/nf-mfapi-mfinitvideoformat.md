# MFInitVideoFormat function

## Description

[This API is not supported and may be altered or unavailable in the future. Applications should avoid using the [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure, and use media type attributes instead. For more information, see [Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types).]

Initializes an [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure for a standard video format such as DVD, analog television, or ATSC digital television.

## Parameters

### `pVideoFormat` [out]

A pointer to an [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) structure. The function fills in the structure members based on the video format specified in the type parameter.

### `type` [in]

The video format, specified as a member of the [MFStandardVideoFormat](https://learn.microsoft.com/windows/desktop/api/mfobjects/ne-mfobjects-mfstandardvideoformat) enumeration.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** Prior to Windows 7, this function was exported from evr.dll. Starting in Windows 7, this function is exported from mfplat.dll, and evr.dll exports a stub function that calls into mfplat.dll. For more information, see [Library Changes in Windows 7](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-headers-and-libraries).

#### Examples

The following example creates a media type object for a standard video format.

```cpp
// Creates a media type for a standard video format.
HRESULT CreateStandardVideoMediaType(MFStandardVideoFormat type, IMFMediaType **ppMediaType)
{
    IMFMediaType *pMediaType = NULL;

    MFVIDEOFORMAT format;

    // Fill in the MFVIDEOFORMAT structure for the video format.
    HRESULT hr = MFInitVideoFormat(&format, type);
    if (FAILED(hr))
    {
        goto done;
    }

    // Create a new (empty) media type.
    hr = MFCreateMediaType(&pMediaType);
    if (FAILED(hr))
    {
        goto done;
    }

    // Initialize the media type from the MFVIDEOFORMAT structure.
    hr = MFInitMediaTypeFromMFVideoFormat(pMediaType, &format, sizeof(format));
    if (FAILED(hr))
    {
        goto done;
    }

    // Return the pointer to the caller.
    *ppMediaType = pMediaType;
    (*ppMediaType)->AddRef();

done:
    SafeRelease(&pMediaType);
    return hr;
}

```

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)

[Video Media Types](https://learn.microsoft.com/windows/desktop/medfound/video-media-types)