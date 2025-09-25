# IMFMediaType::GetRepresentation

## Description

Retrieves an alternative representation of the media type. Currently only the DirectShow **AM_MEDIA_TYPE** structure is supported.

## Parameters

### `guidRepresentation` [in]

GUID that specifies the representation to retrieve. The following values are defined.

| Value | Meaning |
| --- | --- |
| **AM_MEDIA_TYPE_REPRESENTATION** | Convert the media type to a DirectShow **AM_MEDIA_TYPE** structure. The method selects the most appropriate format structure (**pbFormat**). |
| **FORMAT_MFVideoFormat** | Convert the media type to a DirectShow **AM_MEDIA_TYPE** structure with an [MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat) format structure. |
| **FORMAT_VideoInfo** | Convert the media type to a DirectShow **AM_MEDIA_TYPE** structure with a **VIDEOINFOHEADER** format structure. |
| **FORMAT_VideoInfo2** | Convert the media type to a DirectShow **AM_MEDIA_TYPE** structure with a **VIDEOINFOHEADER2** format structure. |

### `ppvRepresentation` [out]

Receives a pointer to a structure that contains the representation. The method allocates the memory for the structure. The caller must release the memory by calling [IMFMediaType::FreeRepresentation](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfmediatype-freerepresentation).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_ATTRIBUTENOTFOUND** | The details of the media type do not match the requested representation. |
| **MF_E_INVALIDMEDIATYPE** | The media type is not valid. |
| **MF_E_UNSUPPORTED_REPRESENTATION** | The media type does not support the requested representation. |

## Remarks

If you request a specific format structure in the *guidRepresentation* parameter, such as **VIDEOINFOHEADER**, you might lose some of the format information.

You can also use the [MFInitAMMediaTypeFromMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfinitammediatypefrommfmediatype) function to convert a Media Foundation media type into a DirectShow media type.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype)

[MFVIDEOFORMAT](https://learn.microsoft.com/windows/desktop/api/mfobjects/ns-mfobjects-mfvideoformat)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)