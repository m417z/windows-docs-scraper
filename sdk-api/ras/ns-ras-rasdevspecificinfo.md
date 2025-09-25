# RASDEVSPECIFICINFO structure

## Description

The **RASDEVSPECIFICINFO** structure is used to send a cookie for server validation and bypass point-to-point (PPP) authentication.

## Members

### `dwSize`

The size, in bytes, of the cookie in **pbDevSpecificInfo**.

### `pbDevSpecificInfo`

A pointer to a BLOB that contains the authentication cookie.

## See also

[RASDIALEXTENSIONS](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa377029(v=vs.85))

[Remote Access Service (RAS) Overview](https://learn.microsoft.com/windows/desktop/RRAS/about-remote-access-service)

[Remote Access Service Structures](https://learn.microsoft.com/windows/desktop/RRAS/remote-access-service-structures)