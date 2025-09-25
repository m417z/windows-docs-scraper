# WMPOpenState enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMPOpenState** enumeration type defines the possible operational states of Windows Media Player as it opens a digital media file.

## Constants

### `wmposUndefined:0`

The content source is in an undefined state.

### `wmposPlaylistChanging`

A new playlist is about to be loaded.

### `wmposPlaylistLocating`

Locating the playlist.

### `wmposPlaylistConnecting`

Connecting to the server that is hosting the playlist.

### `wmposPlaylistLoading`

Loading a playlist.

### `wmposPlaylistOpening`

Opening a playlist.

### `wmposPlaylistOpenNoMedia`

Playlist is open.

### `wmposPlaylistChanged`

Playlist has changed.

### `wmposMediaChanging`

New media item is about to be loaded.

### `wmposMediaLocating`

Locating the media item.

### `wmposMediaConnecting`

Connecting to the server that is hosting the media item.

### `wmposMediaLoading`

Loading the media item.

### `wmposMediaOpening`

Opening the media item.

### `wmposMediaOpen`

The media item is open.

### `wmposBeginCodecAcquisition`

Starting codec acquisition.

### `wmposEndCodecAcquisition`

Ending codec acquisition.

### `wmposBeginLicenseAcquisition`

Starting license acquisition.

### `wmposEndLicenseAcquisition`

Ending license acquisition.

### `wmposBeginIndividualization`

Starting individualization.

### `wmposEndIndividualization`

Individualization has ended.

### `wmposMediaWaiting`

Waiting for the media item to open.

### `wmposOpeningUnknownURL`

Opening a URL whose type is unknown.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/WMP/enumeration-types)