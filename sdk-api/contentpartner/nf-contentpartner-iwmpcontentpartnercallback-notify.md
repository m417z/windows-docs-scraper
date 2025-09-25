# IWMPContentPartnerCallback::Notify

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **Notify** method provides notifications from the content partner plug-in to Windows Media Player.

## Parameters

### `type` [in]

The type of notification being made, specified as a member of the [WMPCallbackNotification](https://learn.microsoft.com/windows/desktop/api/contentpartner/ne-contentpartner-wmpcallbacknotification) enumeration.

### `pContext` [in]

Context-specific data for the notification. See Remarks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The following list gives the possible values for the *type* parameter and the corresponding values of the *pContext* parameter.

wmpcnLoginStateChange

The meaning of the *pContext* parameter depends on its type, which the caller specifies in the **vt** member of *pContext*.

If the type of the *pContext* parameter is **VT_BOOL**, this call notifies Windows Media Player that an attempt to log in or out was successful. The **boolVal** member of *pContext* specifies the log-in state of the user after the successful attempt. VARIANT_TRUE specifies that the a log-in attempt was successful, and the user is logged in. VARIANT_FALSE specifies that a log-out attempt was successful, and the user is logged out.

If the type of the *pContext* parameter is **VT_UI4**, this call notifies Windows Media Player that a log-in attempt failed. The **ulVal** member of *pContext* specifies the index of a webpage, provided by the online store, that will handle the failure. The Player obtains the URL of the webpage by passing the index to [IWMPContentPartner::GetItemInfo](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-getiteminfo), which is implemented by the online store's plug-in. Note that the webpage index is not interpreted by Windows Media Player; it has meaning only to the online store.

For more information about logging in and out, see [Managing Login](https://learn.microsoft.com/windows/desktop/WMP/managing-login).

wmpcnAuthResult

The type of the *pContext* parameter is **VT_BOOL**. This call notifies Windows Media Player that an attempt to authenticate the user either succeeded or failed. VARIANT_TRUE specifies that the authentication attempt succeeded. VARIANT_FALSE specifies that the authentication attempt failed.

Windows Media Player previously requested an authentication attempt by calling [IWMPContentPartner::Authenticate](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-authenticate).

wmpcnNewCatalogAvailable

The type of the *pContext* parameter is **VT_EMPTY**. This call notifies Windows Media Player that the online store has a new catalog available.

wmpcnNewPluginAvailable

The type of the *pContext* parameter is **VT_BOOL**. This call notifies Windows Media Player that the online store has a new plug-in available. The **boolVal** member of *pContext* specifies whether the new plug-in is required. VARIANT_TRUE specifies that the new plug-in is required. VARIANT_FALSE specifies that the new plug-in is optional.

wmpcnDisableRadioSkipping

The type of the *pContext* parameter is **VT_EMPTY**. This call notifies Windows Media Player that it should disable skipping for the metafile playlist (ASX file) that is currently playing.

As Windows Media Player plays an ASX file that it obtained from a type 1 online store, it notifies the online store each time a track is skipped. When the number of tracks skipped reaches the maximum number allowed, the online store calls **IWMPContentPartnerCallback::Notify**, passing wmpcnDisableRadioSkipping, to instruct the Player that it must not skip any more tracks in the currently-playing ASX file. The maximum number of skips allowed for an ASX file is determined by the online store.

Windows Media Player notifies the online store that a track has been skipped by calling [IWMPContentPartner::StationEvent](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-stationevent), passing g_szStationEvent_Skipped in the *bstrStationEventType* parameter.

## See also

[IWMPContentPartnerCallback Interface](https://learn.microsoft.com/windows/desktop/api/contentpartner/nn-contentpartner-iwmpcontentpartnercallback)