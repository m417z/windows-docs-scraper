# MF_MEDIA_ENGINE_KEYERR enumeration

## Description

Defines media key error codes for the media engine.

## Constants

### `MF_MEDIAENGINE_KEYERR_UNKNOWN:1`

Unknown error occurred.

### `MF_MEDIAENGINE_KEYERR_CLIENT:2`

An error with the client occurred.

### `MF_MEDIAENGINE_KEYERR_SERVICE:3`

An error with the service occurred.

### `MF_MEDIAENGINE_KEYERR_OUTPUT:4`

An error with the output occurred.

### `MF_MEDIAENGINE_KEYERR_HARDWARECHANGE:5`

An error occurred related to a hardware change.

### `MF_MEDIAENGINE_KEYERR_DOMAIN:6`

An error with the domain occurred.

## Remarks

**MF_MEDIA_ENGINE_KEYERR** is used with the *code* parameter of [IMFMediaKeySessionNotify::KeyError](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediakeysessionnotify-keyerror) and the *code* value returned from [IMFMediaKeySession::GetError](https://learn.microsoft.com/windows/desktop/medfound/imfmediakeysession-geterror).

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)