# RADIUS_REJECT_REASON_CODE enumeration

## Description

**Note** Internet Authentication Service (IAS) was renamed Network Policy Server (NPS) starting with Windows Server 2008. The content of this topic applies to both IAS and NPS.

The
**RADIUS_REJECT_REASON_CODE** enumeration defines the possible RADIUS packet reject codes.

## Constants

### `rrrcUndefined:0`

Reason code undefined.

### `rrrcAccountUnknown:1`

The authentication attempt is using a user name that does not correspond to any known account.

### `rrrcAccountDisabled:2`

The authentication attempt is using a user name that corresponds to an account that has been disabled by an administrator.

### `rrrcAccountExpired:3`

The authentication attempt is using a user name that corresponds to an account that has expired, either by exceeding its natural expiration lifetime or by administrative action.

### `rrrcAuthenticationFailure:4`

The authentication process has failed; possibly due to incorrect credentials.

## See also

[About NPS Extensions](https://learn.microsoft.com/windows/desktop/Nps/ias-about-internet-authentication-service)

[NPS Extensions Enumerations](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-enumerations)

[NPS Extensions Reference](https://learn.microsoft.com/windows/desktop/Nps/ias-internet-authentication-service-reference)