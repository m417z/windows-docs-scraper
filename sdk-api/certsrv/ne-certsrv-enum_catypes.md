# ENUM_CATYPES enumeration

## Description

The **ENUM_CATYPES** enumeration specifies a [certification authority](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CA) type.

## Constants

### `ENUM_ENTERPRISE_ROOTCA:0`

A root CA that is a member of an Active Directory domain and uses Directory Service to issue and manage certificates.

### `ENUM_ENTERPRISE_SUBCA:1`

A CA that uses Directory Service to issue and manage certificates and is subordinate to an enterprise root CA.

### `ENUM_STANDALONE_ROOTCA:3`

A root CA that does not use Directory Service to issue or manage certificates. It might or might not belong to a domain.

### `ENUM_STANDALONE_SUBCA:4`

A CA that does not use Directory Service to issue or manage certificates and is subordinate to a standalone root CA.

### `ENUM_UNKNOWN_CA:5`

An unknown CA type.