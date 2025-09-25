# MSV1_0_LOGON_SUBMIT_TYPE enumeration

## Description

The **MSV1_0_LOGON_SUBMIT_TYPE** enumeration indicates the kind of logon being requested.

## Constants

### `MsV1_0InteractiveLogon:2`

Requests an interactive user logon. This dispatch routine handles NTLM interactive logons initiated by
[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser) or
[LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera).

### `MsV1_0Lm20Logon`

Requests the second half of an NTLM 2.0 protocol logon. The first half of this type of logon is performed by calling
[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) with the **MsV1_0Lm20ChallengeRequest** message. For more information see,
[MSV1_0_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_protocol_message_type).

### `MsV1_0NetworkLogon`

Requests a network logon. The only difference between this dispatch routine and **MsV1_0Lm20Logon** is that **MsV1_0NetworkLogon** uses a **ParameterControl** member.

### `MsV1_0SubAuthLogon`

Requests the second half of an NTLM 2.0 protocol logon using a [subauthentication package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly). When MSV1_0 initializes itself, it checks a registry key to determine whether it should load a subauthentication package. For more information about subauthentication packages used with MSV1_0, see the subauthentication sample included in the Platform SDK.

### `MsV1_0WorkstationUnlockLogon:7`

Requests a logon unlock of a workstation.

**Note** Windows Server 2003Windows XPThis constant is not supported.

### `MsV1_0S4ULogon:12`

Requests a service for user (S4U) logon.

**Note** Windows Server 2003 with SP2Windows VistaWindows Server 2003Windows XPThis constant is not supported.

### `MsV1_0VirtualLogon:82`

Requests a logon from a remote session.

**Note** Windows Server 2003 with SP2Windows VistaWindows Server 2003Windows XPThis constant is not supported.

### `MsV1_0NoElevationLogon:83`

Requests a logon that doesn't allow for elevation of privileges.

**Note** Windows Server 2008 R2Windows 7Windows Server 2003 with SP2Windows VistaWindows Server 2003Windows XPThis constant is not supported.

### `MsV1_0LuidLogon:84`

## See also

[LogonUser](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-logonusera)

[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage)

[LsaLogonUser](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsalogonuser)

[MSV1_0_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-msv1_0_protocol_message_type)