# SECPKG_PARAMETERS structure

## Description

The **SECPKG_PARAMETERS** structure contains information about the computer system. This structure is used by the
[SpInitialize](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-spinitializefn) function.

## Members

### `Version`

The version of the Security Support Provider Interface in use.

### `MachineState`

The state of the machine. The following table lists the valid values.

| Value | Meaning |
| --- | --- |
| **SECPKG_STATE_ENCRYPTION_PERMITTED** | The [security package](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) may use encryption. |
| **SECPKG_STATE_STRONG_ENCRYPTION_PERMITTED** | The security package may use strong encryption. |
| **SECPKG_STATE_DOMAIN_CONTROLLER** | The machine is a domain controller. |
| **SECPKG_STATE_WORKSTATION** | The machine is a workstation with access to a network. |
| **SECPKG_STATE_STANDALONE** | The machine is a stand-alone system. |

### `SetupMode`

Contains a nonzero value if setup is running.

### `DomainSid`

The security identifier of the primary domain.

### `DomainName`

The name of the primary domain.

### `DnsDomainName`

The Domain Name System (DNS) name of the primary domain.

### `DomainGuid`

The GUID of the primary domain.