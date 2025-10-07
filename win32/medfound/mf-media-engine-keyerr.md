# MF\_MEDIA\_ENGINE\_KEYERR enumeration

Defines media key error codes for the media engine.

## Constants

**MF\_MEDIAENGINE\_KEYERR\_UNKNOWN**

Unknown error occurred.

**MF\_MEDIAENGINE\_KEYERR\_CLIENT**

An error with the client occurred.

**MF\_MEDIAENGINE\_KEYERR\_SERVICE**

An error with the service occurred.

**MF\_MEDIAENGINE\_KEYERR\_OUTPUT**

An error with the output occurred.

**MF\_MEDIAENGINE\_KEYERR\_HARDWARECHANGE**

An error occurred related to a hardware change.

**MF\_MEDIAENGINE\_KEYERR\_DOMAIN**

An error with the domain occurred.

## Remarks

**MF\_MEDIA\_ENGINE\_KEYERR** is used with the *code* parameter of [**IMFMediaKeySessionNotify::KeyError**](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nf-mfmediaengine-imfmediakeysessionnotify-keyerror) and the *code* value returned from [**IMFMediaKeySession::GetError**](https://learn.microsoft.com/windows/win32/medfound/imfmediakeysession-geterror).

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8.1 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| IDL<br> | Mfmediaengine.idl |

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/win32/medfound/media-foundation-enumerations)

