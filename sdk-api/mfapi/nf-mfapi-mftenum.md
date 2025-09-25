# MFTEnum function

## Description

Enumerates Media Foundation transforms (MFTs) in the registry.

Starting in Windows 7, applications should use the [MFTEnumEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenumex) function instead.

## Parameters

### `guidCategory` [in]

GUID that specifies the category of MFTs to enumerate. For a list of MFT categories, see [MFT_CATEGORY](https://learn.microsoft.com/windows/desktop/medfound/mft-category).

### `Flags` [in]

Reserved. Must be zero.

### `pInputType` [in]

Pointer to an [MFT_REGISTER_TYPE_INFO](https://learn.microsoft.com/windows/win32/api/mfobjects/ns-mfobjects-mft_register_type_info) structure that specifies an input media type to match.

This parameter can be **NULL**. If **NULL**, all input types are matched.

### `pOutputType` [in]

Pointer to an [MFT_REGISTER_TYPE_INFO](https://learn.microsoft.com/windows/win32/api/mfobjects/ns-mfobjects-mft_register_type_info) structure that specifies an output media type to match.

This parameter can be **NULL**.
If **NULL**, all output types are matched.

### `pAttributes` [in]

Reserved. Set to **NULL**.

**Note** Windows Vista and Windows Server 2008: This parameter can specify a pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of an attribute store. The **MFTEnum** function matches the attributes in this object against the attributes stored in the registry. (Registry attributes are specified in the *pAttributes* parameter of the [MFTRegister](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregister) function.) Only MFTs with matching attributes are returned in the enumeration results.

**Note** Windows 7 and later: This parameter is ignored.

### `ppclsidMFT` [out]

Receives a pointer to an array of CLSIDs. To create an MFT from this list, call **CoCreateInstance** with one of the CLSIDs. To get information about a particular MFT from its CLSID, call [MFTGetInfo](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftgetinfo). The caller must free the memory for the array by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pcMFTs` [out]

Receives the number of elements in the *ppclsidMFT* array. The value can be zero.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function returns a list of all the MFTs in the specified category that match the search criteria given by the *pInputType*, *pOutputType*, and *pAttributes* parameters. Any of those parameters can be **NULL**.

If no MFTs match the criteria, the method succeeds but returns the value zero in *pcMFTs*.

#### Examples

To find a decoder, set *guidCategory* to **MFT_CATEGORY_AUDIO_DECODER** or **MFT_CATEGORY_VIDEO_DECODER** and specify the encoding format in *pInputType*. You would typically set *pOutputType* to **NULL** in this case.

```cpp
HRESULT FindDecoder(
    const GUID& subtype,        // Subtype
    BOOL bAudio,                // TRUE for audio, FALSE for video
    IMFTransform **ppDecoder    // Receives a pointer to the decoder.
    )
{
    HRESULT hr = S_OK;
    UINT32 count = 0;

    CLSID *ppCLSIDs = NULL;

    MFT_REGISTER_TYPE_INFO info = { 0 };

    info.guidMajorType = bAudio ? MFMediaType_Audio : MFMediaType_Video;
    info.guidSubtype = subtype;

    hr = MFTEnum(
        bAudio ? MFT_CATEGORY_AUDIO_DECODER : MFT_CATEGORY_VIDEO_DECODER,
        0,      // Reserved
        &info,  // Input type
        NULL,   // Output type
        NULL,   // Reserved
        &ppCLSIDs,
        &count
        );

    if (SUCCEEDED(hr) && count == 0)
    {
        hr = MF_E_TOPO_CODEC_NOT_FOUND;
    }

    // Create the first decoder in the list.

    if (SUCCEEDED(hr))
    {
        hr = CoCreateInstance(ppCLSIDs[0], NULL,
            CLSCTX_INPROC_SERVER, IID_PPV_ARGS(ppDecoder));
    }

    CoTaskMemFree(ppCLSIDs);
    return hr;
}

```

To find an encoder, set *guidCategory* to **MFT_CATEGORY_AUDIO_ENCODER** or **MFT_CATEGORY_VIDEO_ENCODER** and specify the encoding format in *pOutputType*. You would typically set *pInputType* to **NULL** in this case.

```cpp
HRESULT FindEncoder(
    const GUID& subtype,
    BOOL bAudio,
    IMFTransform **ppEncoder
    )
{
    HRESULT hr = S_OK;
    UINT32 count = 0;

    CLSID *ppCLSIDs = NULL;

    MFT_REGISTER_TYPE_INFO info = { 0 };

    info.guidMajorType = bAudio ? MFMediaType_Audio : MFMediaType_Video;
    info.guidSubtype = subtype;

    hr = MFTEnum(
        bAudio ? MFT_CATEGORY_AUDIO_ENCODER : MFT_CATEGORY_VIDEO_ENCODER,
        0,          // Reserved
        NULL,       // Input type
        &info,      // Output type
        NULL,       // Reserved
        &ppCLSIDs,
        &count
        );

    if (SUCCEEDED(hr) && count == 0)
    {
        hr = MF_E_TOPO_CODEC_NOT_FOUND;
    }

    // Create the first encoder in the list.

    if (SUCCEEDED(hr))
    {
        hr = CoCreateInstance(ppCLSIDs[0], NULL,
            CLSCTX_INPROC_SERVER, IID_PPV_ARGS(ppEncoder));
    }

    CoTaskMemFree(ppCLSIDs);
    return hr;
}

```

## See also

[Adding a Decoder to a Topology](https://learn.microsoft.com/windows/desktop/medfound/adding-a-decoder-to-a-topology)

[MFTEnumEx](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenumex)

[MFTRegister](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregister)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)

[Registering and Enumerating MFTs](https://learn.microsoft.com/windows/desktop/medfound/registering-and-enumerating-mfts)