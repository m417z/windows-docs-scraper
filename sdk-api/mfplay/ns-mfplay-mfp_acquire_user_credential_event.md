# MFP_ACQUIRE_USER_CREDENTIAL_EVENT structure

## Description

\[The feature associated with this page, MFPlay, is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer) and [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer** and **IMFMediaEngine** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

Event structure for the **MFP_EVENT_TYPE_ACQUIRE_USER_CREDENTIAL** event. This event is sent if the application plays a media file from a server that requires authentication. The application can respond by providing the user credentials.

## Members

### `header`

[MFP_EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/mfplay/ns-mfplay-mfp_event_header) structure that contains data common to all [IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer) events.

### `dwUserData`

Application-defined user data for the media item. This value is specified when the application calls [IMFPMediaPlayer::CreateMediaItemFromURL](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-createmediaitemfromurl) or [IMFPMediaPlayer::CreateMediaItemFromObject](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayer-createmediaitemfromobject) to create the media item.

This event is sent (if at all) before the media item is created and before the application receives the **MFP_EVENT_TYPE_MEDIAITEM_CREATED** event. You can use the value of **dwUserData** to identify which media item requires authentication.

### `fProceedWithAuthentication`

The application should set this member to either **TRUE** or **FALSE** before returning from the [IMFPMediaPlayerCallback::OnMediaPlayerEvent](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayercallback-onmediaplayerevent) event callback.

If the value is **TRUE** when the callback returns, MFPlay continues the authentication attempt. Otherwise, authentication fails.

### `hrAuthenticationStatus`

The response code of the authentication challenge.

### `pwszURL`

The original URL that requires authentication.

### `pwszSite`

The name of the site or proxy that requires authentication.

### `pwszRealm`

The name of the realm for this authentication.

### `pwszPackage`

The name of the authentication package, such as "Digest" or "MBS_BASIC".

### `nRetries`

The number of retries. This member is set to zero on the first attempt, and incremented once for each subsequent attempt.

### `flags`

Bitwise **OR** of zero or more flags from the [_MFP_CREDENTIAL_FLAGS](https://learn.microsoft.com/windows/win32/api/mfplay/ne-mfplay-_mfp_credential_flags) enumeration.

### `pCredential`

Pointer to the [IMFNetCredential](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredential) interface. The application uses this interface to set the user's credentials.

## Remarks

To get a pointer to this structure, cast the *pEventHeader* parameter of the [IMFPMediaPlayerCallback::OnMediaPlayerEvent](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-imfpmediaplayercallback-onmediaplayerevent) callback method. You can use the [MFP_GET_ACQUIRE_USER_CREDENTIAL_EVENT](https://learn.microsoft.com/windows/desktop/api/mfplay/nf-mfplay-mfp_get_acquire_user_credential_event) macro for this purpose.

If the **flags** member contains the **MFP_CREDENTIAL_PROMPT** flag, the application should do the following:

1. Prompt the user to enter a user name and password.
2. Store the user name in the credentials object by calling [IMFNetCredential::SetUser](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfnetcredential-setuser) on the **pCredential** pointer.
3. Store the password by calling [IMFNetCredential::SetPassword](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfnetcredential-setpassword) on the **pCredential** pointer.

To cancel authentication, set **fProceedWithAuthentication** equal to **FALSE**.

By default, MFPlay uses the network source's implementation of [IMFNetCredentialManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfnetcredentialmanager) to manage credentials. An application can provide its own implementation of this interface as follows:

1. Call **QueryInterface** on the [IMFPMediaPlayer](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayer) pointer to get the **IPropertyStore** interface.
2. Call **IPropertyStore::SetValue** to set the [MFNETSOURCE_CREDENTIAL_MANAGER](https://learn.microsoft.com/windows/desktop/medfound/mfnetsource-credential-manager-property) property.

## See also

[IMFPMediaPlayerCallback](https://learn.microsoft.com/windows/desktop/api/mfplay/nn-mfplay-imfpmediaplayercallback)

[Media Foundation Structures](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-structures)

[Using MFPlay for Audio/Video Playback](https://learn.microsoft.com/windows/desktop/medfound/using-mfplay-for-audio-video-playback)