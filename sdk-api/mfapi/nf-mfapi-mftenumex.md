# MFTEnumEx function

## Description

Gets a list of Microsoft Media Foundation transforms (MFTs) that match specified search criteria. This function extends the [MFTEnum](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenum) function.

## Parameters

### `guidCategory` [in]

A GUID that specifies the category of MFTs to enumerate. For a list of MFT categories, see [MFT_CATEGORY](https://learn.microsoft.com/windows/desktop/medfound/mft-category).

### `Flags` [in]

The bitwise **OR** of zero or more flags from the [_MFT_ENUM_FLAG](https://learn.microsoft.com/windows/win32/api/mfapi/ne-mfapi-_mft_enum_flag) enumeration.

### `pInputType` [in]

A pointer to an [MFT_REGISTER_TYPE_INFO](https://learn.microsoft.com/windows/win32/api/mfobjects/ns-mfobjects-mft_register_type_info) structure that specifies an input media type to match.

This parameter can be **NULL**. If **NULL**, all input types are matched.

### `pOutputType` [in]

A pointer to an [MFT_REGISTER_TYPE_INFO](https://learn.microsoft.com/windows/win32/api/mfobjects/ns-mfobjects-mft_register_type_info) structure that specifies an output media type to match.

This parameter can be **NULL**. If **NULL**, all output types are matched.

### `pppMFTActivate` [out]

Receives an array of [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface pointers. Each pointer represents an activation object for an MFT that matches the search criteria. The function allocates the memory for the array. The caller must release the pointers and call the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function to free the memory for the array.

### `pnumMFTActivate` [out]

Receives the number of elements in the *pppMFTActivate* array. If no MFTs match the search criteria, this parameter receives the value zero.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *Flags* parameter controls which MFTs are enumerated, and the order in which they are returned. The flags for this parameter fall into several groups.

The first set of flags specifies how an MFT processes data.

| Flag | Description |
| --- | --- |
| MFT_ENUM_FLAG_SYNCMFT | The MFT performs synchronous data processing in software. This is the original MFT processing model, and is compatible with Windows Vista. |
| MFT_ENUM_FLAG_ASYNCMFT | The MFT performs asynchronous data processing in software. This processing model requires Windows 7. For more information, see [Asynchronous MFTs](https://learn.microsoft.com/windows/desktop/medfound/asynchronous-mfts). |
| MFT_ENUM_FLAG_HARDWARE | The MFT performs hardware-based data processing, using either the AVStream driver or a GPU-based proxy MFT. MFTs in this category always process data asynchronously. For more information, see [Hardware MFTs](https://learn.microsoft.com/windows/desktop/medfound/hardware-mfts). |

Every MFT falls into exactly one of these categories. To enumerate a category, set the corresponding flag in the *Flags* parameter. You can combine these flags to enumerate more than one category. If none of these flags is specified, the default category is synchronous MFTs (**MFT_ENUM_FLAG_SYNCMFT**).

Next, the following flags include MFTs that are otherwise excluded from the results. By default, flags that match these criteria are excluded from the results. Use any these flags to include them.

| Flag | Description |
| --- | --- |
| **MFT_ENUM_FLAG_FIELDOFUSE** | Include MFTs that must be unlocked by the application. |
| **MFT_ENUM_FLAG_LOCALMFT** | Include MFTs that are registered in the caller's process through either the [MFTRegisterLocal](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregisterlocal) or [MFTRegisterLocalByCLSID](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregisterlocalbyclsid) function. |
| **MFT_ENUM_FLAG_TRANSCODE_ONLY** | Include MFTs that are optimized for transcoding rather than playback. |

The last flag is used to sort and filter the results:

| Flag | Description |
| --- | --- |
| **MFT_ENUM_FLAG_SORTANDFILTER** | Sort and filter the results. |

If the **MFT_ENUM_FLAG_SORTANDFILTER** flag is set, the **MFTEnumEx** function sorts the results as follows:

* Local: If the **MFT_ENUM_FLAG_LOCALMFT** flag is set, local MFTs appear first in the list. To register a local MFT, call the [MFTRegisterLocal](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregisterlocal) or [MFTRegisterLocalByCLSID](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregisterlocalbyclsid) function.
* Merit: MFTs with a merit value appear next on the list, in order of merit value (highest to lowest). For more information about merit, see [MFT_CODEC_MERIT_Attribute](https://learn.microsoft.com/windows/desktop/medfound/mft-codec-merit-attribute).
* Preferred: If an MFT is listed in the plug-in control's preferred list, it appears next in the list. For more information about the plug-in control, see [IMFPluginControl](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfplugincontrol).
* If an MFT appears on the blocked list, it is excluded from the results. For more information about the blocked list, see [IMFPluginControl::IsDisabled](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfplugincontrol-isdisabled).
* Any other MFTs that match the search criteria appear at the end of the list, unsorted.

If you do not set the **MFT_ENUM_FLAG_SORTANDFILTER** flag, the **MFTEnumEx** function returns an unsorted list.

Setting the *Flags* parameter to zero is equivalent to using the value **MFT_ENUM_FLAG_SYNCMFT** | **MFT_ENUM_FLAG_LOCALMFT** | **MFT_ENUM_FLAG_SORTANDFILTER**.

Setting *Flags* to **MFT_ENUM_FLAG_SYNCMFT** is equivalent to calling the [MFTEnum](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenum) function.

If no MFTs match the search criteria, the function returns **S_OK**, unless some other error occurs. Therefore, always check the count received in the *pcMFTActivate* parameter before you dereference the *pppMFTActivate* pointer.

**Note** There is no way to enumerate just local MFTs and nothing else. Setting *Flags* equal to **MFT_ENUM_FLAG_LOCALMFT** is equivalent to including the **MFT_ENUM_FLAG_SYNCMFT** flag. However, if you also sort the results by specifying the **MFT_ENUM_FLAG_SORTANDFILTER** flag, local MFTs appear first in the list.

### Creating the MFT

If at least one MFT matches the search criteria, the *pppMFTActivate* parameter receives an array of [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) pointers. One pointer is returned for each matching MFT. Each pointer represents an *activation object* for the MFT. For more information, see [Activation Objects](https://learn.microsoft.com/windows/desktop/medfound/activation-objects).

Additional information about each MFT is stored as attributes on the activation objects. For a list of the possible attributes, see [Transform Attributes](https://learn.microsoft.com/windows/desktop/medfound/transform-attributes).

To create an instance of the MFT, call [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject).

### Hardware Codecs

Hardware codecs are excluded from the enumeration results if the following registry keys are set to zero:

Decoders: **HKEY_LOCAL_MACHINE**\**SOFTWARE**\**Microsoft**\**Windows Media Foundation**\**HardwareMFT**\**EnableDecoders**

Encoders: **HKEY_LOCAL_MACHINE**\**SOFTWARE**\**Microsoft**\**Windows Media Foundation**\**HardwareMFT**\**EnableEncoders**

Video processors: **HKEY_LOCAL_MACHINE**\**SOFTWARE**\**Microsoft**\**Windows Media Foundation**\**HardwareMFT**\**EnableVideoProcessors**

These keys are intended for OEMs, and should not be used by applications.

For hardware codecs, the *guidCategory* parameter of **MFTEnumEx** can also specify one of the following kernel streaming (KS) device categories:

* **KSCATEGORY_DATACOMPRESSOR**
* **KSCATEGORY_DATADECOMPRESSOR**

Hardware codecs should also be registered under an [MFT_CATEGORY](https://learn.microsoft.com/windows/desktop/medfound/mft-category) GUID, so applications should generally use those categories instead of the KS device categories.

#### Examples

The following example searches for a video or audio decoder. Asynchronous, hardware, transcode, and field-of-use decoders are excluded. If a match is found, the code creates the first MFT in the list.

```cpp
HRESULT FindDecoderEx(
    const GUID& subtype,        // Subtype
    BOOL bAudio,                // TRUE for audio, FALSE for video
    IMFTransform **ppDecoder    // Receives a pointer to the decoder.
    )
{
    HRESULT hr = S_OK;
    UINT32 count = 0;

    IMFActivate **ppActivate = NULL;

    MFT_REGISTER_TYPE_INFO info = { 0 };

    info.guidMajorType = bAudio ? MFMediaType_Audio : MFMediaType_Video;
    info.guidSubtype = subtype;

    hr = MFTEnumEx(
        bAudio ? MFT_CATEGORY_AUDIO_DECODER : MFT_CATEGORY_VIDEO_DECODER,
        MFT_ENUM_FLAG_SYNCMFT | MFT_ENUM_FLAG_LOCALMFT | MFT_ENUM_FLAG_SORTANDFILTER,
        &info,      // Input type
        NULL,       // Output type
        &ppActivate,
        &count
        );

    if (SUCCEEDED(hr) && count == 0)
    {
        hr = MF_E_TOPO_CODEC_NOT_FOUND;
    }

    // Create the first decoder in the list.

    if (SUCCEEDED(hr))
    {
        hr = ppActivate[0]->ActivateObject(IID_PPV_ARGS(ppDecoder));
    }

    for (UINT32 i = 0; i < count; i++)
    {
        ppActivate[i]->Release();
    }
    CoTaskMemFree(ppActivate);

    return hr;
}

```

The next example searches for a video or audio encoder. Asynchronous, hardware, transcode, and field-of-use encoders are excluded.

```cpp
HRESULT FindEncoderEx(
    const GUID& subtype,        // Subtype
    BOOL bAudio,                // TRUE for audio, FALSE for video
    IMFTransform **ppEncoder    // Receives a pointer to the decoder.
    )
{
    HRESULT hr = S_OK;
    UINT32 count = 0;

    IMFActivate **ppActivate = NULL;

    MFT_REGISTER_TYPE_INFO info = { 0 };

    info.guidMajorType = bAudio ? MFMediaType_Audio : MFMediaType_Video;
    info.guidSubtype = subtype;

    hr = MFTEnumEx(
        bAudio ? MFT_CATEGORY_AUDIO_ENCODER : MFT_CATEGORY_VIDEO_ENCODER,
        MFT_ENUM_FLAG_SYNCMFT | MFT_ENUM_FLAG_LOCALMFT | MFT_ENUM_FLAG_SORTANDFILTER,
        NULL,       // Input type
        &info,      // Output type
        &ppActivate,
        &count
        );

    if (SUCCEEDED(hr) && count == 0)
    {
        hr = MF_E_TOPO_CODEC_NOT_FOUND;
    }

    // Create the first encoder in the list.

    if (SUCCEEDED(hr))
    {
        hr = ppActivate[0]->ActivateObject(IID_PPV_ARGS(ppEncoder));
    }

    for (UINT32 i = 0; i < count; i++)
    {
        ppActivate[i]->Release();
    }
    CoTaskMemFree(ppActivate);

    return hr;
}

```

The next example searches for a video decoder, with options to include asynchronous, hardware, or transcode decoders.

```cpp
HRESULT FindVideoDecoder(
    const GUID& subtype,
    BOOL bAllowAsync,
    BOOL bAllowHardware,
    BOOL bAllowTranscode,
    IMFTransform **ppDecoder
    )
{
    HRESULT hr = S_OK;
    UINT32 count = 0;

    IMFActivate **ppActivate = NULL;

    MFT_REGISTER_TYPE_INFO info = { MFMediaType_Video, subtype };

    UINT32 unFlags = MFT_ENUM_FLAG_SYNCMFT  | MFT_ENUM_FLAG_LOCALMFT |
                     MFT_ENUM_FLAG_SORTANDFILTER;

    if (bAllowAsync)
    {
        unFlags |= MFT_ENUM_FLAG_ASYNCMFT;
    }
    if (bAllowHardware)
    {
        unFlags |= MFT_ENUM_FLAG_HARDWARE;
    }
    if (bAllowTranscode)
    {
        unFlags |= MFT_ENUM_FLAG_TRANSCODE_ONLY;
    }

    hr = MFTEnumEx(MFT_CATEGORY_VIDEO_DECODER,
        unFlags,
        &info,      // Input type
        NULL,       // Output type
        &ppActivate,
        &count);

    if (SUCCEEDED(hr) && count == 0)
    {
        hr = MF_E_TOPO_CODEC_NOT_FOUND;
    }

    // Create the first decoder in the list.
    if (SUCCEEDED(hr))
    {
        hr = ppActivate[0]->ActivateObject(IID_PPV_ARGS(ppDecoder));
    }

    for (UINT32 i = 0; i < count; i++)
    {
        ppActivate[i]->Release();
    }
    CoTaskMemFree(ppActivate);

    return hr;
}

```

## See also

[Field of Use Restrictions](https://learn.microsoft.com/windows/desktop/medfound/field-of-use-restrictions)

[MFTRegister](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregister)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Registering and Enumerating MFTs](https://learn.microsoft.com/windows/desktop/medfound/registering-and-enumerating-mfts)