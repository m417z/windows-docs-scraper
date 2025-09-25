# DMORegister function

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **DMORegister** function registers a DMO.

## Parameters

### `szName`

NULL-terminated string that contains a descriptive name for the DMO. Names longer than 79 characters might be truncated.

### `clsidDMO`

Class identifier (CLSID) of the DMO.

### `guidCategory`

GUID that specifies the category of the DMO. See [DMO GUIDs](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-guids) for a list of category GUIDs.

### `dwFlags`

Bitwise combination of zero or more flags from the [DMO_REGISTER_FLAGS](https://learn.microsoft.com/windows/desktop/api/dmoreg/ne-dmoreg-dmo_register_flags) enumeration.

### `cInTypes`

Number of input media types to register. Can be zero.

### `pInTypes`

Pointer to an array of [DMO_PARTIAL_MEDIATYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/dmoreg/ns-dmoreg-dmo_partial_mediatype) structures that specify the input media types. The size of the array is specified in the cInTypes parameter

### `cOutTypes`

Number of output media types to register.

### `pOutTypes`

Pointer to an array of DMO_PARTIAL_MEDIATYPE structures that specify the output media types. The size of the array is specified in the cOutTypes parameter. Can be zero.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure |
| **E_INVALIDARG** | Invalid argument |
| **S_OK** | Success |

## Remarks

This function adds information about a DMO to the registry. Applications or software components can use this information to locate the DMOs they need to use, by calling the [DMOEnum](https://learn.microsoft.com/windows/desktop/api/dmoreg/nf-dmoreg-dmoenum) function. For example, to encode a video stream, you would search in the DMOCATEGORY_VIDEO_ENCODER category for a DMO whose media types matched your requirements.

The media types registered by this function are only for the purpose of finding the DMO. They do not necessarily match the types returned by the [IMediaObject::GetInputType](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-getinputtype) and [IMediaObject::GetOutputType](https://learn.microsoft.com/windows/desktop/api/mediaobj/nf-mediaobj-imediaobject-getoutputtype) methods. For example, a decoder might register just its main input types. After the DMO is created and its input type has been set, its **GetOutputType** method will return all of the decompressed types it can generate.

## See also

[DMO Functions](https://learn.microsoft.com/windows/desktop/DirectShow/dmo-functions)