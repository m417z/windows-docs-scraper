## Description

Loads the data for the specified session into the **IMFContentDecryptionModuleSession** object.

## Parameters

### `sessionId`

The unique identifier of the session to load.

### `loaded`

Receives a pointer to a *BOOL* indicating if the session data was loaded successfully.

## Return value

Returns S_OK.

## Remarks

**Load** is based on the Encrypted Media Extension specification's [MediaKeySession.Load](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#dom-mediakeysession-load).

## See also