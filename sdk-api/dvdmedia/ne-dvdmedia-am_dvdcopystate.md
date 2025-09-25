# AM_DVDCOPYSTATE enumeration

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the copy protection state.

## Constants

### `AM_DVDCOPYSTATE_INITIALIZE:0`

Starting a full key-exchange algorithm.

### `AM_DVDCOPYSTATE_INITIALIZE_TITLE:1`

Starting a title key-exchange algorithm.

### `AM_DVDCOPYSTATE_AUTHENTICATION_NOT_REQUIRED:2`

Authentication is not required.

### `AM_DVDCOPYSTATE_AUTHENTICATION_REQUIRED:3`

Authentication required.

### `AM_DVDCOPYSTATE_DONE:4`

Key exchange negotiation is complete.

## Remarks

The [AM_DVDCOPY_SET_COPY_STATE](https://learn.microsoft.com/windows/desktop/api/dvdmedia/ns-dvdmedia-am_dvdcopy_set_copy_state) structure uses this data type.

## See also

[DVD Copy Protection Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-copy-protection-property-set)