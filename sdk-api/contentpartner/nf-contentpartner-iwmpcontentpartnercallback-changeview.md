# IWMPContentPartnerCallback::ChangeView

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **ChangeView** method changes the view in Windows Media Player.

## Parameters

### `bstrType` [in]

A [library location constant](https://learn.microsoft.com/windows/desktop/WMP/library-location-constants) that specifies the type of the new library view. For example, the constant g_szGenreID specifies that the new view will show a particular genre.

### `bstrID` [in]

The ID of the specific item to show in the new view. For example, if *bstrType* is g_szGenreID, then this parameter specifies the ID of the particular genre to show in the new view.

### `bstrFilter` [in]

The filter for the new view. The view will be filtered as if the user had entered this text in the Player's word wheel control.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method must be called only in response to a user request, such as when the user invokes a command by clicking a context menu item.

## See also

[IWMPContentPartnerCallback Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartnercallback)