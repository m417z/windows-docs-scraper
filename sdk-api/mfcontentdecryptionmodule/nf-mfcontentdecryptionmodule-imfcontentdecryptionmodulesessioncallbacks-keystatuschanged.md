## Description

Called when there has been a change in the keys in the Content Decryption Module (CDM) session or their status.

## Return value

Returns S_OK.

## Remarks

Get the current status of the CDM session keys by calling [IMFContentDecryptionModuleSession::GetKeyStatuses](https://learn.microsoft.com/windows/win32/api/mfcontentdecryptionmodule/nf-mfcontentdecryptionmodule-imfcontentdecryptionmodulesession-getkeystatuses).

**KeyStatusChanged** is based on the Encrypted Media Extension specification's [keystatuseschange](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#dom-evt-keystatuseschange).

## See also