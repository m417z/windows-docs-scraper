# ODJ_WIN7BLOB structure

Contains the basic information required to join a client to a domain.

## Members

### lpDomain

Must be set to the domain name.

### lpMachineName

Must be set to the machine name.

### lpMachinePassword

Must be set to a cleartext password for the machine account identified by lpMachineName

### DnsDomainInfo

Contains information about the domain being joined.

### DcInfo

Contains naming and addressing information about the domain controller that was used to create the machine account Active Directory.

### Options

Must be set to zero.

## See also

[**Offline Domain Join IDL Definitions**](https://learn.microsoft.com/windows/win32/netmgmt/odj-idl)

[**ODJ\_POLICY\_DNS\_DOMAIN\_INFO**](https://learn.microsoft.com/windows/win32/netmgmt/odj-odj_policy_dns_domain_info)

[**DOMAIN_CONTROLLER_INFOW**](https://learn.microsoft.com/windows/win32/api/dsgetdc/ns-dsgetdc-domain_controller_infow)