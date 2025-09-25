# WMPPlaylistChangeEventType enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMPPlaylistChangeEventType** enumeration type defines the types of changes that can be made to a playlist.

## Constants

### `wmplcUnknown:0`

An unknown change has occurred.

### `wmplcClear`

The playlist has been cleared.

### `wmplcInfoChange`

A playlist attribute has changed value.

### `wmplcMove`

A media item within the playlist has been moved to a new position.

### `wmplcDelete`

A media item has been deleted from the playlist.

### `wmplcInsert`

A media item has been inserted into the playlist.

### `wmplcAppend`

A media item has been appended to the playlist.

### `wmplcPrivate`

Not supported.

### `wmplcNameChange`

The name of the playlist has changed.

### `wmplcMorph`

Not supported.

### `wmplcSort`

The playlist has been sorted.

### `wmplcLast`

Last enumerated value. Not a valid change type.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/WMP/enumeration-types)