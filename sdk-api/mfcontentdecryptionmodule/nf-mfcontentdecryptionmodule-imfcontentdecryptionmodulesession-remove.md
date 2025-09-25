## Description

Removes all licenses and keys associated with the session.

## Return value

Returns S_OK on success.

## Remarks

For persistent session types, other session data will be cleared as defined for each session type once a release message acknowledgment is processed by [Update](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nf-mfcontentdecryptionmodule-imfcontentdecryptionmodulesession-update).

**Remove** is based on the Encrypted Media Extension specification's [MediaKeySession.remove](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#dom-mediakeysession-remove).

## See also