## Description

The **MEDIUM_INFO** structure describes the media loaded into an external device.

## Members

### `MediaPresent`

Specifies if media is present in the external device. **TRUE** if media is loaded, **FALSE** otherwise.

### `MediaType`

Indicates the type of the media loaded in an external device.

| Flag | Meaning |
|---|---|
| ED_MEDIA_DVC | Digital video cassette. For example MiniDV |
| ED_MEDIA_VHS | VHS cassette |
| ED_MEDIA_HI8 | Hi-8 cassette |

### `RecordInhibit`

Specifies if recording is inhibited on the media. **TRUE** if recording onto the media is inhibited, **FALSE** otherwise.

## Remarks

Any ED_Xxx tokens are defined in *xprtdefs.h* in the Microsoft DirectX SDK.