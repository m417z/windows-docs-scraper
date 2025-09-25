## Description

Represents the status of a Content Decryption Module (CDM) session key.

## Members

### `pbKeyId`

A byte array representing the identifier of a session key.

### `cbKeyId`

The number of bytes in the *pbKeyId* parameter.

### `eMediaKeyStatus`

A value from the [MF_MEDIAKEY_STATUS](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mf_mediakey_status) enumeration specifying the status of the associated session key.

## Remarks

This structure is used as the output parameter for the [IMFContentDecryptionModuleSession::GetKeyStatuses](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nf-mfcontentdecryptionmodule-imfcontentdecryptionmodulesession-getkeystatuses) method.

**MFMediaKeyStatus** is based on the Encrypted Media Extension specification's [MediaKeyStatusMap](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#dom-mediakeysession-sessionid).

## See also