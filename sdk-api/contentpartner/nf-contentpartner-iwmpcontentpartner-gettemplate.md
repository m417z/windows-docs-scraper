# IWMPContentPartner::GetTemplate

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **GetTemplate** method retrieves the URL of the discovery page to be displayed when the library view changes in Windows Media Player.

## Parameters

### `task` [in]

A member of the [WMPTaskType](https://learn.microsoft.com/windows/desktop/api/contentpartner/ne-contentpartner-wmptasktype) enumeration that specifies the active task pane.

### `location` [in]

A [library location constant](https://learn.microsoft.com/windows/desktop/WMP/library-location-constants) that specifies the type of library view the user is currently seeing. For example, the constant g_szCPListID specifies that the user is viewing a pane that shows a particular playlist.

### `pContext` [in]

The ID of the specific item the user is currently seeing. For example, if *location* is g_szCPListID, then this parameter specifies the ID of the particular playlist that the user is seeing.

### `clickLocation` [in]

A library location constant that specifies the type of item the user has selected. For example, the constant g_szCPTrackID specifies that the user has selected a particular music track.

### `pClickContext` [in]

The ID of the particular item the user has selected. For example, if *clickLocation* is g_szCPTrackID, then this parameter specifies the ID of the particular track that the user has selected.

### `bstrFilter` [in]

The filter for the current library view. This is the text that the user entered in the Player's word wheel control.

### `bstrViewParams` [in]

Parameters, meaningful only to the online store, associated with the new library location. See Remarks.

### `pbstrTemplateURL` [out]

Pointer to a **BSTR** that receives the URL of the discovery page to display.

### `pTemplateSize` [out]

Receives a member of the [WMPTemplateSize](https://learn.microsoft.com/windows/desktop/api/contentpartner/ne-contentpartner-wmptemplatesize) enumeration that indicates the size of the template in which the Player will display the discovery page.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Windows Media Player calls this method when the view changes in the **Library**, **Sync**, or **Burn** pane. The Player also calls this method when one of those three panes becomes active. The pane or view can change as a result of user navigation or as the result of a call from the discovery page.

When the discovery page calls [External.changeView](https://learn.microsoft.com/windows/desktop/WMP/external-changeview), it sets the *ViewParams* parameter to whatever context it wants to associate with the new view. Windows Media Player passes that context along to the plug-in in the *bstrViewParams* parameter of **GetTemplate**.

When the discovery page calls [External.changeViewOnlineList](https://learn.microsoft.com/windows/desktop/WMP/external-changeviewonlinelist), it sets the *Params* parameter to whatever context it wants to associate with the new view. Windows Media Player passes that context along to the plug-in in the *bstrViewParams* parameter of **GetTemplate**.

If the view changes as a result of user navigation, Windows Media Player sets the *bstrParams* parameter to **NULL** when it calls **GetTemplate**.

Windows Media Player calls **GetTemplate** to retrieve the URL of the discovery page that it should display in the new view. The Player also receives a **WMPTemplateSize** value that indicates what portion of the new view should be occupied by the discovery page.

## See also

[IWMPContentPartner Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartner)