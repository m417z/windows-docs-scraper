# DMOEnum function

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DMOEnum** function enumerates DMOs listed in the registry. The caller can search by category, media type, or both.

## Parameters

### `guidCategory`

GUID that specifies which category of DMO to search. Use GUID_NULL to search every category. See [DMO GUIDs](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-guids) for a list of category GUIDs.

### `dwFlags`

Bitwise combination of zero or more flags from the DMO_ENUM_FLAGS enumeration.

### `cInTypes`

Number of input media types to use in the search criteria. Use zero to match any input type.

### `pInTypes`

Pointer to an array of [DMO_PARTIAL_MEDIATYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/dmoreg/ns-dmoreg-dmo_partial_mediatype) structures that contain the input media types. Specify the size of the array in the cInTypes parameter.

### `cOutTypes`

Number of output media types to use in the search criteria. Use zero to match any output type.

### `pOutTypes`

Pointer to an array of DMO_PARTIAL_MEDIATYPE structures that contain the output media types. Specify the size of the array in the cOutTypes parameter.

### `ppEnum`

Address of a variable to receive the [IEnumDMO](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-ienumdmo) interface of the enumerator.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure |
| **E_OUTOFMEMORY** | Insufficient memory |
| **S_OK** | Success |

## Remarks

This method returns a pointer to an enumerator object that supports the [IEnumDMO](https://learn.microsoft.com/windows/desktop/api/mediaobj/nn-mediaobj-ienumdmo) interface. The application uses the **IEnumDMO** interface to enumerate over the set of DMOs that match the search criteria.

#### Examples

The following example enumerates all audio effect DMOs on the user's system, including keyed DMOs.

```
IEnumDMO* pEnum = NULL;
HRESULT hr = DMOEnum(
    DMOCATEGORY_AUDIO_EFFECT, // Category
    DMO_ENUMF_INCLUDE_KEYED,  // Included keyed DMOs
    0, NULL,                  // Input types (don't care)
    0, NULL,                  // Output types (don't care)
    &pEnum);

if (SUCCEEDED(hr))
{
    CLSID clsidDMO;
    WCHAR* wszName;
    do
    {
        hr = pEnum->Next(1, &clsidDMO, &wszName, NULL);
        if (hr == S_OK)
        {
            // Now wszName holds the friendly name of the DMO,
            // and clsidDMO holds the CLSID.

            // Remember to release wszName!
            CoTaskMemFree(wszName);
        }
    } while (hr == S_OK);
    pEnum->Release();
}

```

## See also

[DMO Functions](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-functions)