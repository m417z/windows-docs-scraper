# TOKEN_ELEVATION_TYPE enumeration

## Description

The **TOKEN_ELEVATION_TYPE** enumeration indicates the elevation type of token being queried by the [GetTokenInformation](https://learn.microsoft.com/windows/desktop/api/securitybaseapi/nf-securitybaseapi-gettokeninformation) function.

## Constants

### `TokenElevationTypeDefault:1`

The token does not have a linked token.

### `TokenElevationTypeFull`

The token is an elevated token.

### `TokenElevationTypeLimited`

The token is a limited token.