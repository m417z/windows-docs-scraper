# WMPContextMenuInfo structure

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMPContextMenuInfo** structure contains data about a context menu command.

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

## Members

### `dwID`

The ID of the command.

### `bstrMenuText`

The menu text to display for the command.

### `bstrHelpText`

The help text to display for the command.

## Remarks

This structure is retrieved by a call to [IWMPContentPartner::GetCommands](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-getcommands).

## See also

[Structures for Type 1 Online Stores](https://learn.microsoft.com/windows/desktop/WMP/structures-for-type-1-online-stores)