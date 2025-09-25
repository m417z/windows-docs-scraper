# IWMPEvents::MediaCollectionAttributeStringChanged

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **MediaCollectionAttributeStringChanged** event occurs when an attribute value in the library is changed.

## Parameters

### `bstrAttribName` [in]

Specifies the name of the attribute. For information about the attributes supported by Windows Media Player, see the Windows Media Player [Attribute Reference](https://learn.microsoft.com/windows/desktop/WMP/attribute-reference).

### `bstrOldAttribVal` [in]

Specifies the original attribute value.

### `bstrNewAttribVal` [in]

Specifies the new attribute value.

## Remarks

When a user modifies library metadata, the **MediaCollection** object is updated and this event fires for each attribute changed.

**Windows Media Player 10 Mobile:** This event is not supported.

## See also

[IWMPEvents Interface](https://learn.microsoft.com/windows/desktop/api/wmp/nn-wmp-iwmpevents)