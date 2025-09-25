# _MFP_CREDENTIAL_FLAGS enumeration

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Contains flags for the [MFP_ACQUIRE_USER_CREDENTIAL_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_acquire_user_credential_event) structure.

Some of these flags, marked [out], convey information back to the MFPlay player object. The application should set or clear these flags as appropriate, before returning from the [IMFPMediaPlayerCallback::OnMediaPlayerEvent](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayercallback-onmediaplayerevent) callback method.

## Constants

### `MFP_CREDENTIAL_PROMPT:0x1`

The player object does not have any stored credentials and requires them from the application. If the player object can provide cached or stored credentials to the server, it does not set this flag.

### `MFP_CREDENTIAL_SAVE:0x2`

The credentials are saved to persistent storage. This flag acts as a hint for the application's UI. If the application prompts the user for credentials, the UI can indicate that the credentials have already been saved.

[out] If the application sets this flag, the player object saves the user credentials in persistent storage. Otherwise, the player object does not save the credentials.

### `MFP_CREDENTIAL_DO_NOT_CACHE:0x4`

[out] If the application sets this flag, the player object does not cache the user credentials in memory. Otherwise, the player object does not cache the credentials. If you set this flag, do not set the **MFP_CREDENTIAL_SAVE** flag.

### `MFP_CREDENTIAL_CLEAR_TEXT:0x8`

The credentials will be sent in clear text. The application should warn the user that the credentials will be sent over the network without encryption.

[out] On output, set this flag to allow the player object to send credentials in clear text, without prompting the user to re-enter the credentials.

### `MFP_CREDENTIAL_PROXY:0x10`

The credentials will be used to authenticate with a proxy.

### `MFP_CREDENTIAL_LOGGED_ON_USER:0x20`

The authentication scheme supports authentication of the user who is currently logged on.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)