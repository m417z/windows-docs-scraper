# SECURITY_QUALITY_OF_SERVICE structure

## Description

The **SECURITY_QUALITY_OF_SERVICE** data structure contains information used to support client impersonation. A client can specify this information when it connects to a server; the information determines whether the server may impersonate the client, and if so, to what extent.

## Members

### `Length`

Specifies the size, in bytes, of this structure.

### `ImpersonationLevel`

Specifies the information given to the server about the client, and how the server may represent, or impersonate, the client. Security impersonation levels govern the degree to which a server process can act on behalf of a client [process](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly). This member is a
[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level) enumeration type value.

### `ContextTrackingMode`

Specifies whether the server is to be given a snapshot of the client's [security context](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) (called static tracking), or is to be continually updated to track changes to the client's security context (called dynamic tracking). The SECURITY_STATIC_TRACKING value specifies static tracking, and the SECURITY_DYNAMIC_TRACKING value specifies dynamic tracking. Not all communications mechanisms support dynamic tracking; those that do not will default to static tracking.

### `EffectiveOnly`

Specifies whether the server may enable or disable [privileges](https://learn.microsoft.com/windows/desktop/SecGloss/p-gly) and groups that the client's security context may include.

## See also

[DdeSetQualityOfService](https://learn.microsoft.com/windows/desktop/api/dde/nf-dde-ddesetqualityofservice)

[SECURITY_IMPERSONATION_LEVEL](https://learn.microsoft.com/windows/desktop/api/winnt/ne-winnt-security_impersonation_level)