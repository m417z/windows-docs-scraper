# MFTranscodeGetAudioOutputAvailableTypes function

## Description

Gets a list of output formats from an audio encoder.

## Parameters

### `guidSubType` [in]

Specifies the subtype of the output media. The encoder uses this value as a filter when it is enumerating the available output types. For information about the audio subtypes, see [Audio Subtype GUIDs](https://learn.microsoft.com/windows/desktop/medfound/audio-subtype-guids).

### `dwMFTFlags` [in]

Bitwise **OR** of zero or more flags from the [_MFT_ENUM_FLAG](https://learn.microsoft.com/windows/win32/api/mfapi/ne-mfapi-_mft_enum_flag) enumeration.

### `pCodecConfig` [in]

A pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of an attribute store. The attribute store specifies the encoder configuration settings. This parameter can be **NULL**. The attribute store can hold any of the following attributes.

| Value | Meaning |
| --- | --- |
| **[MFT_FIELDOFUSE_UNLOCK_Attribute](https://learn.microsoft.com/windows/desktop/medfound/mft-fieldofuse-unlock-attribute)** | Set this attribute to unlock an encoder that has field-of-use descriptions. |
| **[MF_TRANSCODE_ENCODINGPROFILE](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-encodingprofile)** | Specifies a device conformance profile for a Windows Media encoder. |
| **[MF_TRANSCODE_QUALITYVSSPEED](https://learn.microsoft.com/windows/desktop/medfound/mf-transcode-qualityvsspeed)** | Sets the tradeoff between encoding quality and encoding speed. |

### `ppAvailableTypes` [out]

Receives a pointer to the [IMFCollection](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfcollection) interface of a collection object that contains a list of preferred audio media types. The collection contains [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) pointers. The caller must release the interface pointer.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function call succeeded. |
| **MF_E_TRANSCODE_NO_MATCHING_ENCODER** | Failed to find an encoder that matches the specified configuration settings. |

## Remarks

This function assumes the encoder will be used in its default encoding mode, which is typically constant bit-rate (CBR) encoding. Therefore, the types returned by the function might not work with other modes, such as variable bit-rate (VBR) encoding.

Internally, this function works by calling [MFTEnumEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenumex) to find a matching encoder, and then calling [IMFTransform::GetOutputAvailableType](https://learn.microsoft.com/windows/desktop/api/mftransform/nf-mftransform-imftransform-getoutputavailabletype) to get the encoder's output types.

#### Examples

The following example creates a transcode profile for Windows Media Audio (WMA).

```cpp
template <class Q>
HRESULT GetCollectionObject(IMFCollection *pCollection, DWORD index, Q **ppObj)
{
    IUnknown *pUnk;
    HRESULT hr = pCollection->GetElement(index, &pUnk);
    if (SUCCEEDED(hr))
    {
        hr = pUnk->QueryInterface(IID_PPV_ARGS(ppObj));
        pUnk->Release();
    }
    return hr;
}

HRESULT CreateTranscodeProfile(IMFTranscodeProfile **ppProfile)
{
    IMFTranscodeProfile *pProfile = NULL;     // Transcode profile.
    IMFCollection   *pAvailableTypes = NULL;  // List of audio media types.
    IMFMediaType    *pAudioType = NULL;       // Audio media type.
    IMFAttributes   *pAudioAttrs = NULL;      // Copy of the audio media type.
    IMFAttributes   *pContainer = NULL;       // Container attributes.

    DWORD dwMTCount = 0;

    // Create an empty transcode profile.
    HRESULT hr = MFCreateTranscodeProfile(&pProfile);
    if (FAILED(hr))
    {
        goto done;
    }

    // Get output media types for the Windows Media audio encoder.

    // Enumerate all codecs except for codecs with field-of-use restrictions.
    // Sort the results.

    DWORD dwFlags =
        (MFT_ENUM_FLAG_ALL & (~MFT_ENUM_FLAG_FIELDOFUSE)) |
        MFT_ENUM_FLAG_SORTANDFILTER;

    hr = MFTranscodeGetAudioOutputAvailableTypes(MFAudioFormat_WMAudioV9,
        dwFlags, NULL, &pAvailableTypes);
    if (FAILED(hr))
    {
        goto done;
    }

    hr = pAvailableTypes->GetElementCount(&dwMTCount);
    if (FAILED(hr))
    {
        goto done;
    }
    if (dwMTCount == 0)
    {
        hr = E_FAIL;
        goto done;
    }

    // Get the first audio type in the collection and make a copy.
    hr = GetCollectionObject(pAvailableTypes, 0, &pAudioType);
    if (FAILED(hr))
    {
        goto done;
    }

    hr = MFCreateAttributes(&pAudioAttrs, 0);
    if (FAILED(hr))
    {
        goto done;
    }

    hr = pAudioType->CopyAllItems(pAudioAttrs);
    if (FAILED(hr))
    {
        goto done;
    }

    // Set the audio attributes on the profile.
    hr = pProfile->SetAudioAttributes(pAudioAttrs);
    if (FAILED(hr))
    {
        goto done;
    }

    // Set the container attributes.
    hr = MFCreateAttributes(&pContainer, 1);
    if (FAILED(hr))
    {
        goto done;
    }

    hr = pContainer->SetGUID(MF_TRANSCODE_CONTAINERTYPE, MFTranscodeContainerType_ASF);
    if (FAILED(hr))
    {
        goto done;
    }

    hr = pProfile->SetContainerAttributes(pContainer);
    if (FAILED(hr))
    {
        goto done;
    }

    *ppProfile = pProfile;
    (*ppProfile)->AddRef();

done:
    SafeRelease(&pProfile);
    SafeRelease(&pAvailableTypes);
    SafeRelease(&pAudioType);
    SafeRelease(&pAudioAttrs);
    SafeRelease(&pContainer);
    return hr;
}

```

## See also

[IMFCollection::GetElement](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfcollection-getelement)

[MFCreateTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatetranscodeprofile)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Tutorial: Encoding a WMA File](https://learn.microsoft.com/windows/desktop/medfound/tutorial--converting-an-mp3-file-to-a-wma-file)