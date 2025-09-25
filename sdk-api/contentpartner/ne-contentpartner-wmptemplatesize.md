# WMPTemplateSize enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **WMPTemplateSize** enumeration represents HTML template sizes.

## Constants

### `wmptsSmall:0`

Small template; height is fixed at 100 pixels.

### `wmptsMedium`

Medium template; height is fixed at 250 pixels.

### `wmptsLarge`

Large template. Windows Media Player allocates as much room as possible while allowing space for the list control to display a single row of items.

## See also

[Enumerations for Type 1 Online Stores](https://learn.microsoft.com/windows/desktop/WMP/enumerations-for-type-1-online-stores)

[IWMPContentPartner::GetTemplate](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-gettemplate)