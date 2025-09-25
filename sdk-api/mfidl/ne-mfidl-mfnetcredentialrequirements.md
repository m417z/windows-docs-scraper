# MFNetCredentialRequirements enumeration

## Description

Specifies how the credential manager should obtain user credentials.

## Constants

### `REQUIRE_PROMPT:0x1`

The credential manager should prompt the user to provide the credentials.

### `REQUIRE_SAVE_SELECTED:0x2`

**Note** Requires Windows 7 or later.

The credentials are saved to persistent storage. This flag acts as a hint for the application's UI. If the application prompts the user for credentials, the UI can indicate that the credentials have already been saved.

## Remarks

The application implements the credential manager, which must expose the [IMFNetCredentialManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredentialmanager) interface. If the **REQUIRE_PROMPT** flag is set, the credential manager should prompt the user for his or her name and password.

The credential cache object sets the **REQUIRE_PROMPT** flag if the cache does not yet contain valid credentials. It also sets this flag if the credentials will be sent as plain text, unless the credential manager previously set the **MFNET_CREDENTIAL_ALLOW_CLEAR_TEXT** option. (See [IMFNetCredentialCache::SetUserOptions](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfnetcredentialcache-setuseroptions).)

## See also

[IMFNetCredentialCache::GetCredential](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfnetcredentialcache-getcredential)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)

[Network Source Authentication](https://learn.microsoft.com/windows/desktop/medfound/network-source-authentication)