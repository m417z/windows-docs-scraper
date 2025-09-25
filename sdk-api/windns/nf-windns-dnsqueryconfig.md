# DnsQueryConfig function

## Description

The
**DnsQueryConfig** function enables application programmers to query for the configuration of the local computer or a specific adapter.

## Parameters

### `Config` [in]

A [DNS_CONFIG_TYPE](https://learn.microsoft.com/windows/win32/api/windns/ne-windns-dns_config_type) value that specifies the configuration type of the information to be queried.

### `Flag` [in]

A value that specifies whether to allocate memory for the configuration information. Set *Flag* to **DNS_CONFIG_FLAG_ALLOC**  to allocate memory; otherwise, set it to 0.

**Note** Free the allocated memory with [LocalFree](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-localfree).

### `pwsAdapterName` [in, optional]

A pointer to a string that represents the adapter name against which the query is run.

### `pReserved` [in, optional]

Reserved for future use.

### `pBuffer` [out]

A pointer to a buffer that receives the query response. The following table shows the data type of the buffer for each of the *Config* parameter values.

| *Config* parameter | Data type of buffer |
| --- | --- |
| DnsConfigPrimaryDomainName_W | PWCHAR |
| DnsConfigPrimaryDomainName_A | PCHAR |
| DnsConfigPrimaryDomainName_UTF8 | PCHAR |
| DnsConfigAdapterDomainName_W | Not implemented |
| DnsConfigAdapterDomainName_A | Not implemented |
| DnsConfigAdapterDomainName_UTF8 | Not implemented |
| DnsConfigDnsServerList | IP4_ARRAY |
| DnsConfigSearchList | Not implemented |
| DnsConfigAdapterInfo | Not implemented |
| DnsConfigPrimaryHostNameRegistrationEnabled | DWORD |
| DnsConfigAdapterHostNameRegistrationEnabled | DWORD |
| DnsConfigAddressRegistrationMaxCount | DWORD |
| DnsConfigHostName_W | PWCHAR |
| DnsConfigHostName_A | PCHAR |
| DnsConfigHostName_UTF8 | PCHAR |
| DnsConfigFullHostName_W | PWCHAR |
| DnsConfigFullHostName_A | PCHAR |
| DnsConfigFullHostName_UTF8 | PCHAR |

### `pBufLen` [in, out]

The length of the buffer, in bytes. If the buffer provided is not sufficient, an error is returned and *pBufferLength* contains the minimum necessary buffer size. Ignored on input if *Flag* is set to **TRUE**.

## Return value

Returns success confirmation upon successful completion. Otherwise, returns the appropriate DNS-specific error code as defined in Winerror.h.

## See also

[DNS_CONFIG_TYPE](https://learn.microsoft.com/windows/win32/api/windns/ne-windns-dns_config_type)

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DnsQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsquery_a)