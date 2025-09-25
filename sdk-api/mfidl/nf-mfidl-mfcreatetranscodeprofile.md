# MFCreateTranscodeProfile function

## Description

Creates an empty transcode profile object.

The transcode profile stores configuration settings for the output file. These configuration settings are specified by the caller, and include audio and video stream properties, encoder settings, and container settings. To set these properties, the caller must call the appropriate [IMFTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodeprofile) methods.

The configured transcode profile is passed to the [MFCreateTranscodeTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatetranscodetopology) function. The underlying topology builder uses these settings to build the transcode topology.

## Parameters

### `ppTranscodeProfile` [out]

Receives a pointer to the [IMFTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodeprofile) interface of the transcode profile object. Caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **MFCreateTranscodeProfile** function creates an empty transcode profile. You must configure the transcode profile setting attributes that define the media types and the container properties. Use the following methods to configure the profile:

* [IMFTranscodeProfile::SetAudioAttributes](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftranscodeprofile-setaudioattributes)
* [IMFTranscodeProfile::SetVideoAttributes](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftranscodeprofile-setvideoattributes)
* [IMFTranscodeProfile::SetContainerAttributes](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imftranscodeprofile-setcontainerattributes)

For example code that uses this function, see the following topics:

* [Tutorial: Encoding an MP4 File](https://learn.microsoft.com/windows/desktop/medfound/tutorial--encoding-an-mp4-file-)
* [Tutorial: Encoding a WMA File](https://learn.microsoft.com/windows/desktop/medfound/tutorial--converting-an-mp3-file-to-a-wma-file)

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

[IMFTranscodeProfile](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imftranscodeprofile)

[MFTranscodeGetAudioOutputAvailableTypes](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mftranscodegetaudiooutputavailabletypes)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Transcode API](https://learn.microsoft.com/windows/desktop/medfound/transcode-api)