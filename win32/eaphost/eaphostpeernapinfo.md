# EapHostPeerNapInfo structure

The **EapHostPeerNapInfo** structure contains the Network Access Protection (NAP) information on an EAP supplicant.

## Members

**isolationState**

An [**ISOLATION\_STATE**](https://learn.microsoft.com/windows/desktop/api/eaphostpeertypes/ne-eaphostpeertypes-isolation_state) structure that specifies the NAP isolation state of a computer. The isolation state determines the level of network access granted.

**probationTime**

A **ProbationTime** structure that specifies the time required for the connection to come out of quarantine after which the connection will be dropped. A **ProbationTime** structure is identical to a [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) structure.

**stringCorrelationIdLength**

The length, in bytes, of the NAP [stringCorrelationId](https://learn.microsoft.com/windows/desktop/NAP/nap-datatypes) that follows this structure.

## Remarks

The **EapHostPeerNapInfo** structure precedes the NAP [stringCorrelationId](https://learn.microsoft.com/windows/desktop/NAP/nap-datatypes) of data type **WCHAR** in the RPC byte stream.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 7 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 R2 \[desktop apps only\]<br> |
| Header<br> | Eaphostpeerapis.h |

## See also

[EAPHost Supplicant Structures](https://learn.microsoft.com/windows/win32/eaphost/eap-host-supplicant-structures)

[**EapHostPeerGetAuthStatus**](https://learn.microsoft.com/previous-versions/windows/desktop/api/eappapis/nf-eappapis-eaphostpeergetauthstatus)

[**EapHostPeerMethodAuthParams**](https://learn.microsoft.com/windows/win32/api/eaphostpeertypes/ne-eaphostpeertypes-eaphostpeerauthparams)

