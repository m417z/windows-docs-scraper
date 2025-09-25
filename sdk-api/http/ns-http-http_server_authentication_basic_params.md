# HTTP_SERVER_AUTHENTICATION_BASIC_PARAMS structure

## Description

The **HTTP_SERVER_AUTHENTICATION_BASIC_PARAMS** structure contains the information for Basic authentication on a URL Group.

This structure is contained in the [HTTP_SERVER_AUTHENTICATION_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_server_authentication_info) structure.

## Members

### `RealmLength`

The length, in bytes, of the **Realm** member.

### `Realm`

The realm used for Basic authentication.

The realm allows the server to be partitioned into a set of protection spaces, each with its own set of authentication schemes from the authentication database.

## See also

[HTTP Server API Version 2.0 Structures](https://learn.microsoft.com/windows/desktop/Http/http-server-api-version-2-0-structures)

[HTTP_SERVER_AUTHENTICATION_INFO](https://learn.microsoft.com/windows/desktop/api/http/ns-http-http_server_authentication_info)