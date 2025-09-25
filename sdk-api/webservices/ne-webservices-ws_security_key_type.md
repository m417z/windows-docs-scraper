# WS_SECURITY_KEY_TYPE enumeration

## Description

The key type of a security token. It is used as the return type when
a security token is queried about its key. It is also used to specify
the required key type when requesting a security token from a security
token service.

## Constants

### `WS_SECURITY_KEY_TYPE_NONE:1`

Has no key -- it may be a bearer token such as a username/password
pair.

### `WS_SECURITY_KEY_TYPE_SYMMETRIC:2`

Has a symmetric key.

### `WS_SECURITY_KEY_TYPE_ASYMMETRIC:3`

Has an asymmetric key.