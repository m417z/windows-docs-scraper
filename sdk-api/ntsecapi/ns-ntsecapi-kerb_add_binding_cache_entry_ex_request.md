# KERB_ADD_BINDING_CACHE_ENTRY_EX_REQUEST structure

## Description

Allows the user to bind to a specific domain controller (DC), overriding the Kerberos domain binding cache. Kerberos enforces a DC lookup when Dynamic Access Control (DAC) is enabled, so typically authentication is not bound to a specific DC. Certain users may want to bind to the specific DC on which they created an account or set a new password to avoid the DC replication delay. You must have the **SeTcbPrivilege** privilege set.

## Members

### `MessageType`

A
value of the [KERB_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_protocol_message_type) enumeration that lists the types of messages that can be sent to the [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) authentication package by calling
the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function. This member must be set to **KerbAddBindingCacheEntryExMessage**.

### `RealmName`

The name of the realm of the domain controller.

### `KdcAddress`

The address of the Key Distribution Center (KDC) of the server to which you want to bind.

### `AddressType`

The type of string that is contained in the **KdcAddress** member. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DS_INET_ADDRESS** | The address is a string IP address of the domain controller, for example, "\\157.55.94.74"). |
| **DS_NETBIOS_ADDRESS** | The address is a NetBIOS name of the domain controller, for example, "\\phoenix". |

### `DcFlags`

The domain controller flags that the caller provides. These flags are needed to pass to the [DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) function.

## Remarks

To meet both the user's requirements and Kerberos' requirements, you need to make two calls to override the Kerberos domain binding cache.

1. First, you construct a request message type of [KERB_QUERY_DOMAIN_EXTENDED_POLICIES_REQUEST](https://learn.microsoft.com/windows/win32/api/ntsecapi/ns-ntsecapi-kerb_query_domain_extended_policies_request) in which the **MessageType** member must be set to **KerbQueryDomainExtendedPoliciesMessage**. The **DomainName** member is set to the actual domain name for which the extended domain policies are queried. If **DomainName** is set to null, the local computer's domain is assumed.
2. Next, you call the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/win32/api/ntsecapi/ns-ntsecapi-kerb_query_domain_extended_policies_response) function with Kerberos authentication package and the request message. Upon successful return, [KERB_QUERY_DOMAIN_EXTENDED_POLICIES_RESPONSE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_query_domain_extended_policies_response) is returned.
   * If the local computer has disabled DAC, the **Flags** member is set to KERB_QUERY_DOMAIN_EXTENDED_POLICIES_RESPONSE_FLAG_DAC_DISABLED.
   * If the specified domain has Flexible Authentication Secure Tunneling (FAST) enabled, **ExtendedPolicies** member is set to KERB_EXTENDED_POLICY_FAST_CAPABLE (0x10000).
   * If the specified domain has Claims enabled, **ExtendedPolicies** member is set to KERB_EXTENDED_POLICY_CLAIMS_CAPABLE (0x40000).
   * If the local computer domain doesn't disable DAC and the specified domain has either FAST or Claims enabled, the **DsFlags** member of the [DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) function is set to DS_DIRECTORY_SERVICE_8_REQUIRED. Otherwise, **DsFlags** is 0.
   * If the function returns a failure in the **ProtocolStatus** member, STATUS_NOT_FOUND indicates that the specified domain cannot be queried because the local computer doesn't have trust to the specified domain. Other error codes indicate the actual failure encountered.
3. Then you must call [DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) with the returned **DsFlags** set with flags that represent your own requirements, which may be several, so use the logical operator **OR**. The **DomainControllerInfo** member is returned.
4. Finally, you call the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/win32/api/ntsecapi/ns-ntsecapi-kerb_query_domain_extended_policies_response) function again with the Kerberos authentication package and the request **KERB_ADD_BINDING_CACHE_ENTRY_EX_REQUEST** in which the **DcFlags** member is set to the **DomainControllerInfo** flags. All other members should be populated in the same way as **KERB_ADD_BINDING_CACHE_ENTRY_EX_REQUEST**. If the **DsFlags** of the [KERB_QUERY_DOMAIN_EXTENDED_POLICIES_RESPONSE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ns-ntsecapi-kerb_query_domain_extended_policies_response) is zero, then either **DcFlags** should be set to zero when calling **KERB_ADD_BINDING_CACHE_ENTRY_EX_REQUEST** or default back to the existing KERB_ADD_BINDING_CACHE_ENTRY_REQUEST request.

## See also

[LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage)