# MFT_REGISTER_TYPE_INFO structure

## Description

Contains media type information for registering a Media Foundation transform (MFT).

## Members

### `guidMajorType`

The major media type. For a list of possible values, see [Major Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-type-guids).

### `guidSubtype`

The media subtype. For a list of possible values, see the following topics:

* [Audio Subtype GUIDs](https://learn.microsoft.com/windows/desktop/medfound/audio-subtype-guids)
* [Video Subtype GUIDs](https://learn.microsoft.com/windows/desktop/medfound/video-subtype-guids)

## See also

[MFTEnum](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenum)

[MFTGetInfo](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftgetinfo)

[MFTRegister](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregister)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)