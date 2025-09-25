# WMPLibraryType enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMPLibraryType** enumeration type defines the possible library types to which Windows Media Player can connect.

## Constants

### `wmpltUnknown:0`

Not a valid library type.

### `wmpltAll`

All libraries.

### `wmpltLocal`

The current user's library.

### `wmpltRemote`

A library that belongs to another user on the same computer, the home network, or the Internet. The Player control must be running in remote mode to access these libraries. For information about running the Player control in remote mode, see [Remoting the Windows Media Player Control](https://learn.microsoft.com/windows/desktop/WMP/remoting-the-windows-media-player-control).

### `wmpltDisc`

Libraries on a data CD or DVD.

### `wmpltPortableDevice`

Libraries on portable devices.

## Remarks

Windows Media Player 10 Mobile: This enumeration is not supported.

## See also

[About Library Services](https://learn.microsoft.com/windows/desktop/WMP/about-library-services)

[Enumeration Types](https://learn.microsoft.com/windows/desktop/WMP/enumeration-types)

[IWMPLibrary::get_type](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmplibrary-get_type)

[IWMPLibraryServices Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmplibraryservices)