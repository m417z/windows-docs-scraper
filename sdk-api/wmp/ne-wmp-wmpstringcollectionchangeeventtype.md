# WMPStringCollectionChangeEventType enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMPStringCollectionChangeEventType** enumeration type defines the types of changes that can occur in a string collection.

**Syntax**

## Constants

### `wmpsccetUnknown:0`

Not a valid event type.

### `wmpsccetInsert`

An item was inserted.

### `wmpsccetChange`

The string collection changed.

### `wmpsccetDelete`

An item was deleted.

### `wmpsccetClear`

The string collection was cleared.

### `wmpsccetBeginUpdates`

Bulk updates are beginning.

### `wmpsccetEndUpdates`

Bulk updates have ended.

## Remarks

Windows Media Player 10 Mobile: This enumeration is not supported.

## See also

[Enumeration Types](https://learn.microsoft.com/windows/desktop/WMP/enumeration-types)

[IWMPEvents3::StringCollectionChange](https://learn.microsoft.com/windows/desktop/api/wmp/nf-wmp-iwmpevents3-stringcollectionchange)

[IWMPStringCollection Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpstringcollection)

[Interfaces](https://learn.microsoft.com/windows/desktop/WMP/interfaces)