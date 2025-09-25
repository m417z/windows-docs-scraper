## Description

Gets a reference to an array of structures that represent the key IDs known to the Content Decryption Module (CDM) session and the current status of the associated key.

## Parameters

### `keyStatuses`

Receives a pointer to an array of [MFMediaKeyStatus](https://learn.microsoft.com/windows/win32/api/mfidl/ns-mfidl-mfmediakeystatus) structures containing the IDs and statuses of the keys known to the CDM session.

### `numKeyStatuses`

Receives the number of structures present in the *keyStatuses* array.

## Return value

Returns S_OK. If an error occurs, the returned key status list is empty.

## Remarks

**GetKeyStatuses** is based on the Encrypted Media Extension specification's [MediaKeySession.keyStatuses](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#dom-mediakeysession-keystatuses).

## See also