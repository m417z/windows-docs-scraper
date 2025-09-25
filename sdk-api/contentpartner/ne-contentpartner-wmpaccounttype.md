# WMPAccountType enumeration

## Description

\[The feature associated with this page, [Windows Media Player SDK](https://learn.microsoft.com/windows/win32/wmp/windows-media-player-sdk), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer). **MediaPlayer** has been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** instead of **Windows Media Player SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This section describes functionality designed for use by online stores. Use of this functionality outside the context of an online store is not supported.

The **WMPAccountType** enumeration defines account types for an online store.

## Constants

### `wmpatBuyOnly:1`

The user is only authorized to purchase content.

### `wmpatSubscription:2`

The user has a subscription account, but content must be purchased to synchronize to a device based on Windows Media DRM for Portable Devices.

### `wmpatJanus:3`

The user has a subscription account and the subscription content can be synchronized to a device based on Windows Media DRM for Portable Devices.

## See also

[Enumerations for Type 1 Online Stores](https://learn.microsoft.com/windows/desktop/WMP/enumerations-for-type-1-online-stores)

[IWMPContentPartner::GetContentPartnerInfo](https://learn.microsoft.com/windows/desktop/api/contentpartner/nf-contentpartner-iwmpcontentpartner-getcontentpartnerinfo)