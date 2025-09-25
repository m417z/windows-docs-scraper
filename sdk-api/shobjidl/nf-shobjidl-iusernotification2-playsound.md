# IUserNotification2::PlaySound

## Description

Plays a sound in conjunction with the notification.

## Parameters

### `pszSoundName` [in]

Type: **LPCWSTR**

A pointer to a null-terminated Unicode string that specifies the alias of the sound file to play.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The string pointed to by *pszSoundName* contains an alias for a system event found in the registry or the Win.ini file; for instance, "SystemExit".

The specified sound is played asynchronously and the method returns immediately after beginning the sound. To stop an asynchronous waveform sound, call **IUserNotification2::PlaySound** with *pszSoundName* set to **NULL**.

The specified sound event will yield to another sound event that is already playing. If a sound cannot be played because the resource needed to play that sound is busy, the method immediately returns S_FALSE without playing the requested sound.

If the specified sound cannot be found, **IUserNotification2::PlaySound** uses the system default sound.

## See also

[IUserNotification2](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-iusernotification2)

[PlaySound](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iusernotification-playsound)