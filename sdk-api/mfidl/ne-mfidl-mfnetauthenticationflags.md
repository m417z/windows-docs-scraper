# MFNetAuthenticationFlags enumeration

## Description

Specifies how the user's credentials will be used.

## Constants

### `MFNET_AUTHENTICATION_PROXY:0x1`

The credentials will be used to authenticate with a proxy.

### `MFNET_AUTHENTICATION_CLEAR_TEXT:0x2`

The credentials will be sent over the network unencrypted.

### `MFNET_AUTHENTICATION_LOGGED_ON_USER:0x4`

The credentials must be from a user who is currently logged on.

## See also

[IMFNetCredentialCache::GetCredential](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfnetcredentialcache-getcredential)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Network Source Authentication](https://learn.microsoft.com/windows/desktop/medfound/network-source-authentication)