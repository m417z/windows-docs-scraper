## Description

Specifies the type of a Content Decryption Module (CDM) message.

## Constants

### `MF_MEDIAKEYSESSION_MESSAGETYPE_LICENSE_REQUEST:0`

The message contains a request for a new license.

### `MF_MEDIAKEYSESSION_MESSAGETYPE_LICENSE_RENEWAL:1`

The message contains a request to renew an existing license.

### `MF_MEDIAKEYSESSION_MESSAGETYPE_LICENSE_RELEASE:2`

The message contains a record of license destruction.

### `MF_MEDIAKEYSESSION_MESSAGETYPE_INDIVIDUALIZATION_REQUEST:3`

The message contains a request for App-Assisted Individualization (or re-individualization).

## Remarks

This value is used by the [IMFContentDecryptionModuleSessionCallbacks::KeyMessage](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nf-mfcontentdecryptionmodule-imfcontentdecryptionmodulesessioncallbacks-keymessage) callback.

**MF_MEDIAKEYSESSION_MESSAGETYPE** is based on the Encrypted Media Extension specification's [MediaKeyStatus](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#dom-mediakeymessagetype) enumeration.

## See also

[IMFContentDecryptionModuleSessionCallbacks::KeyMessage](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nf-mfcontentdecryptionmodule-imfcontentdecryptionmodulesessioncallbacks-keymessage)