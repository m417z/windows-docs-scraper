# KERB_QUERY_BINDING_CACHE_RESPONSE structure

## Description

Contains the results of querying the binding cache. You must have the **SeTcbPrivilege** privilege set.

## Members

### `MessageType`

A
value of the [KERB_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_protocol_message_type) enumeration that lists the types of messages that can be sent to the [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) authentication package by calling
the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function. This member must be set to **KerbQueryBindingCacheMessage**.

### `CountOfEntries`

The number of entries in the binding cache.

### `Entries`