# KERB_QUERY_DOMAIN_EXTENDED_POLICIES_REQUEST structure

## Description

Contains information used to query the domain for the extended policies. You must have the **SeTcbPrivilege** privilege set.

## Members

### `MessageType`

A
value of the [KERB_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_protocol_message_type) enumeration that lists the types of messages that can be sent to the [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) authentication package by calling
the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function. This member must be set to **KerbQueryDomainExtendedPoliciesMessage**.

### `Flags`

Reserved.

### `DomainName`

The name of the domain that you are querying for the extended policies.