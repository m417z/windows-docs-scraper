# KERB_ADD_BINDING_CACHE_ENTRY_REQUEST structure

## Description

Specifies a message to add a binding cache entry. You must have the **SeTcbPrivilege** privilege set.

## Members

### `MessageType`

A
value of the [KERB_PROTOCOL_MESSAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-kerb_protocol_message_type) enumeration that lists the types of messages that can be sent to the [Kerberos](https://learn.microsoft.com/windows/desktop/SecGloss/k-gly) authentication package by calling
the [LsaCallAuthenticationPackage](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsacallauthenticationpackage) function. This member must be set to **KerbAddBindingCacheEntryMessage**.

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