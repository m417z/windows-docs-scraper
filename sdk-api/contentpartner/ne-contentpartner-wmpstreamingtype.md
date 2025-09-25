# WMPStreamingType enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **WMPStreamingType** enumeration specifies the type of streaming media.

## Constants

### `wmpstUnknown:0`

Unknown type.

### `wmpstMusic:1`

The plug-in must return a URL for music content.

### `wmpstVideo:2`

The plug-in must return a URL for video content.

### `wmpstRadio:3`

The plug-in must return a URL for radio content.

## See also

[Enumerations for Type 1 Online Stores](https://learn.microsoft.com/windows/desktop/WMP/enumerations-for-type-1-online-stores)

[IWMPContentPartner::GetStreamingURL](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-getstreamingurl)