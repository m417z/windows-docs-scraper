## Description

The **TOKEN_LOGGING_INFORMATION** provides detailed information about a security token.

## Members

### `TokenType`

A [**TOKEN_TYPE**](https://learn.microsoft.com/windows/win32/api/winnt/ne-winnt-token_type) value that indicates the type of the token.

### `TokenElevation`

A [**TOKEN_ELEVATION**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-token_elevation) value that indicates the elevation level of the token.

### `TokenElevationType`

A [**TOKEN_ELEVATION_TYPE**](https://learn.microsoft.com/windows/win32/api/winnt/ne-winnt-token_elevation_type) value that indicates the elevation type of the token.

### `ImpersonationLevel`

A [**SECURITY_IMPERSONATION_LEVEL**](https://learn.microsoft.com/windows/win32/api/winnt/ne-winnt-security_impersonation_level) value that indicates the impersonation level of the token.

### `IntegrityLevel`

Indicates the integrity level of the token.

### `User`

A [**SID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-sid_and_attributes) structure that contains the user SID and its attributes.

### `TrustLevelSid`

Pointer to a [**SID**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-sid) structure representing the trust level of the token.

### `SessionId`

The session ID associated with the token.

### `AppContainerNumber`

The number of the app container associated with the token.

### `AuthenticationId`

A **LUID** that represents the authentication ID of the token.

### `GroupCount`

Number of groups associated with the token.

### `GroupsLength`

Length in bytes of the **Groups** array.

### `Groups`

Pointer to an array of [**SID_AND_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-sid_and_attributes) structures that represent the groups associated with the token.