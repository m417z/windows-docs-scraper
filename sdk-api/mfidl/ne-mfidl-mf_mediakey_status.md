## Description

Specifies the status of a Content Decryption Module (CDM) session key.

## Constants

### `MF_MEDIAKEY_STATUS_USABLE:0`

The CDM is certain the key is currently usable for decryption.

### `MF_MEDIAKEY_STATUS_EXPIRED`

The key is no longer usable for decryption because its expiration time has passed.

### `MF_MEDIAKEY_STATUS_OUTPUT_DOWNSCALED`

There are output restrictions associated with the key that cannot currently be met. Media data decrypted with this key may be presented at a lower quality (e.g., resolution), if necessary according to the output restrictions.

### `MF_MEDIAKEY_STATUS_OUTPUT_NOT_ALLOWED`

There are output restrictions associated with the key that disallow output.

### `MF_MEDIAKEY_STATUS_STATUS_PENDING`

The status of the key is not yet known and is being determined. The status will be updated with the actual status when it has been determined.

### `MF_MEDIAKEY_STATUS_INTERNAL_ERROR`

The key is not currently usable for decryption because of an error in the CDM unrelated to the other values. This value is not actionable by the application.

### `MF_MEDIAKEY_STATUS_RELEASED`

The key itself is no longer available to the CDM, but information about the key, such as a record of license destruction, is available.

### `MF_MEDIAKEY_STATUS_OUTPUT_RESTRICTED`

There are output restrictions associated with the key that cannot currently be met. Media data decrypted with this key may be blocked from presentation, if necessary according to the output restrictions. The application should avoid using streams that will trigger the output restrictions associated with the key.

## Remarks

This enumeration is with the [MFMediaKeyStatus](https://learn.microsoft.com/windows/win32/api/mfidl/ns-mfidl-mfmediakeystatus) structure used as the output parameter for the [IMFContentDecryptionModuleSession::GetKeyStatuses](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nf-mfcontentdecryptionmodule-imfcontentdecryptionmodulesession-getkeystatuses) method.

**MF_MEDIAKEY_STATUS** is based on the Encrypted Media Extension specification's [MediaKeyStatus](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#dom-mediakeystatus) enumeration.

## See also

* [MFMediaKeyStatus](https://learn.microsoft.com/windows/win32/api/mfidl/ns-mfidl-mfmediakeystatus)
* [IMFContentDecryptionModuleSession::GetKeyStatuses](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nf-mfcontentdecryptionmodule-imfcontentdecryptionmodulesession-getkeystatuses)