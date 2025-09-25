## Description

Specifies the type of a Content Decryption Module (CDM) session, represented by an [IMFContentDecryptionModuleSession](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nn-mfcontentdecryptionmodule-imfcontentdecryptionmodulesession) object.

## Constants

### `MF_MEDIAKEYSESSION_TYPE_TEMPORARY:0`

A session for which the license, key(s) and record of or data related to the session are not persisted.

### `MF_MEDIAKEYSESSION_TYPE_PERSISTENT_LICENSE`

A session for which the license (and potentially other data related to the session) will be persisted.

### `MF_MEDIAKEYSESSION_TYPE_PERSISTENT_RELEASE_MESSAGE`

A record of license destruction.

### `MF_MEDIAKEYSESSION_TYPE_PERSISTENT_USAGE_RECORD`

A record of license usage.

## Remarks

Pass a member of this enumeration into [IMFContentDecryptionModule::CreateSession](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nf-mfcontentdecryptionmodule-imfcontentdecryptionmodule-createsession)

## See also

- [IMFContentDecryptionModuleSession](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nn-mfcontentdecryptionmodule-imfcontentdecryptionmodulesession)

- [IMFContentDecryptionModule::CreateSession](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nf-mfcontentdecryptionmodule-imfcontentdecryptionmodule-createsession)