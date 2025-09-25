# MFWrapMediaType function

## Description

Creates a media type that wraps another media type.

## Parameters

### `pOrig`

A pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type to wrap in a new media type.

### `MajorType`

A
GUID that specifies the major type for the new media type. For a list of possible values, see [Major Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-type-guids).

### `SubType`

A
GUID that specifies the subtype for the new media type. For possible values, see:

* [Audio Subtypes](https://learn.microsoft.com/windows/desktop/DirectShow/audio-subtypes)
* [Video Subtypes](https://learn.microsoft.com/windows/desktop/DirectShow/video-subtypes)

Applications can define custom subtype GUIDs.

### `ppWrap`

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the new media type that wraps the original media type. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The original media type (*pOrig*) is stored in the new media type under the [MF_MT_WRAPPED_TYPE](https://learn.microsoft.com/windows/desktop/medfound/mf-mt-wrapped-type-attribute) attribute. To extract the original media type, call [MFUnwrapMediaType](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mfunwrapmediatype).

This function is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)