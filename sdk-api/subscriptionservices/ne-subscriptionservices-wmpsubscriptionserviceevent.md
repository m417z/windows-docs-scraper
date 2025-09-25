# WMPSubscriptionServiceEvent enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **WMPSubscriptionServiceEvent** enumeration type defines the types of service events that may occur.

## Constants

### `wmpsseCurrentBegin:1`

The online store is active.

### `wmpsseCurrentEnd:2`

The online store is no longer active.

### `wmpsseFullBegin:3`

The online store is the current active music store.

### `wmpsseFullEnd:4`

The online store is no longer the current active music store.

## See also

[Enumerations for Type 2 Online Stores](https://learn.microsoft.com/windows/desktop/WMP/enumerations-for-type-2-online-stores)