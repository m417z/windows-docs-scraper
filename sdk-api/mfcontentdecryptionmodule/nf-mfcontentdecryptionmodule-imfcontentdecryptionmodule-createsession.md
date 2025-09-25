## Description

Creates a [IMFContentDecryptionModuleSession](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nn-mfcontentdecryptionmodule-imfcontentdecryptionmodulesession) object representing a Content Decryption Module (CDM) session.

## Parameters

### `sessionType`

A member of the [MF_MEDIAKEYSESSION_TYPE](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mf_mediakeysession_type) that specifies the type of CDM session to create.

### `callbacks`

An [IMFContentDecryptionModuleSessionCallbacks](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nn-mfcontentdecryptionmodule-imfcontentdecryptionmodulesessioncallbacks) object for receiving key status change updates.

### `session`

Receives the created **IMFContentDecryptionModuleSession** object.

## Return value

Returns S_OK on success.

## Remarks

**CreateSession** is based on the Encrypted Media Extension specification's [createSession](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#dom-mediakeys-createsession).

## See also