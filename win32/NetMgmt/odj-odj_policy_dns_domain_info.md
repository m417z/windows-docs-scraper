# ODJ_POLICY_DNS_DOMAIN_INFO structure

Contains information about the domain and forest that a client should be joined to.

## Members

### Name

Must be set to a Netbios domain name.

### DnsDomainName

Must be set to a domain name in DNS format.

### DnsForestName

Must be set to a forest name in DNS format.

### DomainGuid

Must be set to the domain guid.

### Sid

Must be set to the domain sid.

## See also

[**Offline Domain Join IDL Definitions**](https://learn.microsoft.com/windows/win32/netmgmt/odj-idl)

[**ODJ\_UNICODE\_STRING**](https://learn.microsoft.com/windows/win32/netmgmt/odj-odj_unicode_string)

[**ODJ\_SID**](https://learn.microsoft.com/windows/win32/netmgmt/odj-odj_sid)