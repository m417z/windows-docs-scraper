# DsDeregisterDnsHostRecordsW function

## Description

The **DsDeregisterDnsHostRecords** function deletes DNS entries, except for type A records registered by a domain controller. Only an administrator, account operator, or server operator may call this function.

## Parameters

### `ServerName` [in, optional]

The null-terminated string that specifies the name of the remote domain controller. Can be set to **NULL** if the calling application is running on the domain controller being updated.

### `DnsDomainName` [in, optional]

The null-terminated string that specifies the DNS domain name of the domain occupied by the domain controller. It is unnecessary for this to be a domain hosted by this domain controller. If **NULL**, the *DnsHostName* with the leftmost label removed is specified.

### `DomainGuid` [in, optional]

Pointer to the Domain GUID of the domain. If **NULL**, GUID specific names are not removed.

### `DsaGuid` [in, optional]

Pointer to the GUID of the **NTDS-DSA** object to be deleted. If **NULL**, **NTDS-DSA** specific names are not removed.

### `DnsHostName` [in]

Pointer to the null-terminated string that specifies the DNS host name of the domain controller whose DNS records are being deleted.

## Return value

This function returns DSGETDCAPI DWORD.

## Remarks

This function deregisters SRV and CNAME records only. It leaves type A records intact. Deletion of site specific records, for example, _ldap._tcp._\<SiteName>._sites.dc._msdcs.\<DnsDomainName>, is attempted for every site (\<SiteName> in this example) in the enterprise of the domain controller on which the function is executed. Therefore, this function call could create a time-consuming run and may generate significant network traffic for enterprises with many sites.

> [!NOTE]
> The dsgetdc.h header defines DsDeregisterDnsHostRecords as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DsGetDcSiteCoverage](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetdcsitecoveragea)

[DsGetSiteName](https://learn.microsoft.com/windows/desktop/api/dsgetdc/nf-dsgetdc-dsgetsitenamea)