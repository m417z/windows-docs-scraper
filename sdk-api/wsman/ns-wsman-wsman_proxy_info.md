# WSMAN_PROXY_INFO structure

## Description

Specifies proxy information.

## Members

### `accessType`

Specifies the access type for the proxy. This member must be set to one of the values defined in the [WSManProxyAccessType](https://learn.microsoft.com/windows/desktop/api/wsman/ne-wsman-wsmanproxyaccesstype) enumeration.

### `authenticationCredentials`

A [WSMAN_AUTHENTICATION_CREDENTIALS](https://learn.microsoft.com/windows/desktop/api/wsman/ns-wsman-wsman_authentication_credentials) structure that specifies the credentials and authentication scheme used for proxy access.