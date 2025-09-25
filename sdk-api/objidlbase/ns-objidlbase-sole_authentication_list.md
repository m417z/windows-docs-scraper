# SOLE_AUTHENTICATION_LIST structure

## Description

Indicates the default authentication information to use with each authentication service. When DCOM negotiates the default authentication service for a proxy, it picks the default authentication information from this list.

## Members

### `cAuthInfo`

The count of pointers in the array pointed to by **aAuthInfo**.

### `aAuthInfo`

An array of [SOLE_AUTHENTICATION_INFO](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-sole_authentication_info) structures. Each of these structures contains an identifier for an authentication service, an identifier for the authorization service, and a pointer to authentication information to use with the specified authentication service.

## See also

[CoInitializeSecurity](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializesecurity)