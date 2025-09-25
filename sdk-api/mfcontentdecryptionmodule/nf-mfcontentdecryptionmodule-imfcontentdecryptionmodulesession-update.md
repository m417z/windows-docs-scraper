## Description

Provides messages, including licenses, to the Content Decryption Module (CDM) session. Persisted data should not be released or cleared.

## Parameters

### `response`

A **BYTE** array containing messages.

### `responseSize`

The size of the **BYTE** array provided in the *response* parameter.

## Return value

Returns S_OK on success.

## Remarks

**Update** is based on the Encrypted Media Extension specification's [MediaKeySession.update](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#dom-mediakeysession-update).

## See also