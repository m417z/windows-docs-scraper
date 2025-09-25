# MFPMPSESSION_CREATION_FLAGS enumeration

## Description

Contains flags that define the behavior of the [MFCreatePMPMediaSession](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-mfcreatepmpmediasession) function.

## Constants

### `MFPMPSESSION_UNPROTECTED_PROCESS:0x1`

If this flag is set, the Protected Media Path (PMP) Media Session is created in an unprotected process. You can use the unprotected process to play clear content but not protected content. If this flag is not set, the PMP Media Session is created in a protected process. In that case, the protected process is used for both protected content and clear content.

### `MFPMPSESSION_IN_PROCESS:0x2`

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)