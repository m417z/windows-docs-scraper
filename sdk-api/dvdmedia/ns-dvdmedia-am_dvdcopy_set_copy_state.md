# AM_DVDCOPY_SET_COPY_STATE structure

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Specifies the copy protection state of the filter.

## Members

### `DVDCopyState`

Copy protection state of the filter. Member of the [AM_DVDCOPYSTATE](https://learn.microsoft.com/windows/desktop/api/dvdmedia/ne-dvdmedia-am_dvdcopystate) enumerated data type.

## Remarks

Both the [IKsPropertySet::Get](https://learn.microsoft.com/windows/desktop/DirectShow/ikspropertyset-get) and [IKsPropertySet::Set](https://learn.microsoft.com/windows/desktop/DirectShow/ikspropertyset-set) methods are supported on this property. The Get method is called first to determine if authentication is required. If a filter provides multiple pins that use the same authenticator, such as a hardware DVD decoder, the decoder might respond with **AM_DVDCOPYSTATE_AUTHENTICATION_NOT_REQUIRED** on some pins to indicate that the key exchange algorithm only needs to be applied once. The filter should respond with **AM_DVDCOPYSTATE_AUTHENTICATION_REQUIRED** to get the copy protection state property on the first pin where this property is issued.

The Set method is used to indicate which phase of copy protection negotiation the filter is entering. Specify these by setting the required flag in the [AM_DVDCOPYSTATE](https://learn.microsoft.com/windows/desktop/api/dvdmedia/ne-dvdmedia-am_dvdcopystate) enumerated type.

The AM_PROPERTY_DVDCOPY_SET_COPY_STATE property uses this structure.

## See also

[DVD Copy Protection Property Set](https://learn.microsoft.com/windows/desktop/DirectShow/dvd-copy-protection-property-set)