# MF_MEDIA_ENGINE_ERR enumeration

## Description

Defines error status codes for the Media Engine.

## Constants

### `MF_MEDIA_ENGINE_ERR_NOERROR:0`

No error.

### `MF_MEDIA_ENGINE_ERR_ABORTED:1`

The process of fetching the media resource was stopped at the user's request.

### `MF_MEDIA_ENGINE_ERR_NETWORK:2`

A network error occurred while fetching the media resource.

### `MF_MEDIA_ENGINE_ERR_DECODE:3`

An error occurred while decoding the media resource.

### `MF_MEDIA_ENGINE_ERR_SRC_NOT_SUPPORTED:4`

The media resource is not supported.

### `MF_MEDIA_ENGINE_ERR_ENCRYPTED:5`

An error occurred while encrypting the media resource.

Supported in Windows 8.1 and later.

## Remarks

The values greater than zero correspond to error codes defined for the **MediaError** object in HTML5.

## See also

[IMFMediaError::GetErrorCode](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediaerror-geterrorcode)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)