# MF_TIMED_TEXT_ERROR_CODE enumeration

## Description

Specifies the kind error that occurred with a timed text track.

## Constants

### `MF_TIMED_TEXT_ERROR_CODE_NOERROR:0`

No error occurred.

### `MF_TIMED_TEXT_ERROR_CODE_FATAL:1`

A fatal error occurred.

### `MF_TIMED_TEXT_ERROR_CODE_DATA_FORMAT:2`

An error occurred with the data format of the timed text track.

### `MF_TIMED_TEXT_ERROR_CODE_NETWORK:3`

A network error occurred when trying to load the timed text track.

### `MF_TIMED_TEXT_ERROR_CODE_INTERNAL:4`

An internal error occurred.

## Remarks

This enumeration is used to return error information from the [IMFTimedTextTrack::GetErrorCode](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imftimedtexttrack-geterrorcode) method.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)