# KERB_QUERY_DOMAIN_EXTENDED_POLICIES_RESPONSE structure

## Description

Contains the results of querying for the extended policies of the specified domain. You must have the **SeTcbPrivilege** privilege set.

## Members

### `MessageType`

A
value of the [KERB_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_protocol_message_type) enumeration that lists the types of messages that can be sent to the [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) authentication package by calling
the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function. This member must be set to **KerbQueryDomainExtendedPoliciesMessage**.

### `Flags`

Contains flags used for the extended policies.

| Value | Meaning |
| --- | --- |
| **KERB_QUERY_DOMAIN_EXTENDED_POLICIES_RESPONSE_FLAG_DAC_DISABLED**<br><br>0x1 | The Dynamic Access Control (DAC) is disabled so you can't get the extended policies. |

### `ExtendedPolicies`

The name of the domain that you are querying for the extended policies.

### `DsFlags`

Flags that represent the requirements. These flags are returned from the [DsGetDcName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcnamea) function.