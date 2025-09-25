# MFNetCredentialOptions enumeration

## Description

Describes options for the caching network credentials.

## Constants

### `MFNET_CREDENTIAL_SAVE:0x1`

Allow the credential cache object to save credentials in persistent storage.

### `MFNET_CREDENTIAL_DONT_CACHE:0x2`

Do not allow the credential cache object to cache the credentials in memory. This flag cannot be combined with the MFNET_CREDENTIAL_SAVE flag.

### `MFNET_CREDENTIAL_ALLOW_CLEAR_TEXT:0x4`

The user allows credentials to be sent over the network in clear text.

 By default, [IMFNetCredentialCache::GetCredential](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfnetcredentialcache-getcredential) always returns the REQUIRE_PROMPT flag when the authentication flags include MFNET_AUTHENTICATION_CLEAR_TEXT, even if cached credentials are available. If you set the MFNET_CREDENTIAL_ALLOW_CLEAR_TEXT option, the **GetCredential** method will not return REQUIRE_PROMPT for clear text, if cached credentials are available.

Do not set this flag without notifying the user that credentials might be sent in clear text.

## See also

[IMFNetCredentialCache::SetUserOptions](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfnetcredentialcache-setuseroptions)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Network Source Authentication](https://learn.microsoft.com/windows/desktop/medfound/network-source-authentication)