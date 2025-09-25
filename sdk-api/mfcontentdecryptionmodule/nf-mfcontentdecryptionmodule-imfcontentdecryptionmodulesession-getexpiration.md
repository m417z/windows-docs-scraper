## Description

Gets the expiration time for all keys in the session as determined by the Content Decryption Module (CDM).

## Parameters

### `expiration`

Receives a pointer to an LPWSTR representing the session ID or NaN if no such time exists or if the license explicitly never expires.

## Return value

Returns S_OK.

## Remarks

**GetExpiration** is based on the Encrypted Media Extension specification's [MediaKeySession.expiration](https://www.w3.org/TR/2017/REC-encrypted-media-20170918/#dom-mediakeysession-expiration). The time and time range values of the expiration are based on ECMA Language Specification's [Time Values and Time Range](https://tc39.es/ecma262/#sec-time-values-and-time-range).

## See also