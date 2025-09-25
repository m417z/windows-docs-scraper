# WMPCallbackNotification enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **WMPCallbackNotification** enumeration defines states for use by the **IWMPContentPartnerCallback::Notify** callback function.

## Constants

### `wmpcnLoginStateChange:1`

The user has either signed in or signed out.

### `wmpcnAuthResult:2`

The notification contains the result of an authentication attempt.

### `wmpcnLicenseUpdated:3`

A license was updated for a content item.

### `wmpcnNewCatalogAvailable:4`

A new catalog or update is available for download.

### `wmpcnNewPluginAvailable:5`

A new plug-in or update is available for download.

### `wmpcnDisableRadioSkipping:6`

Disable radio skipping in Windows Media Player.

## See also

[Enumerations for Type 1 Online Stores](https://learn.microsoft.com/windows/desktop/WMP/enumerations-for-type-1-online-stores)