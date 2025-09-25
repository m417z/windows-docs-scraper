# DnsModifyRecordsInSet_W function

## Description

The
**DnsModifyRecordsInSet** function adds, modifies or removes a Resource Record (RR) set that may have been previously registered with DNS servers.

Like many DNS functions, the
**DnsModifyRecordsInSet** function type is implemented in multiple forms to facilitate different character encoding. Based on the character encoding involved, use one of the following functions:

* **DnsModifyRecordsInSet_A** (_A for ANSI encoding)
* **DnsModifyRecordsInSet_W** (_W for Unicode encoding)
* **DnsModifyRecordsInSet_UTF8** (_UTF8 for UTF 8 encoding)

## Parameters

### `pAddRecords` [in, optional]

A pointer to the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure that contains the RRs to be added to the RR set.

### `pDeleteRecords` [in, optional]

A pointer to the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure that contains the RRs to be deleted from the RR set.

### `Options` [in]

A value that contains a bitmap of [DNS Update Options](https://learn.microsoft.com/windows/desktop/DNS/dns-constants). Options can be combined and all options override **DNS_UPDATE_SECURITY_USE_DEFAULT**.

### `hCredentials` [in, optional]

A handle to the credentials of a specific account. Used when secure dynamic update is required. This parameter is optional.

### `pExtraList` [in, out, optional]

This parameter is reserved for future use and must be set to **NULL**.

### `pReserved` [in, out, optional]

This parameter is reserved for future use and must be set to **NULL**.

## Return value

Returns success confirmation upon successful completion. Otherwise, it returns the appropriate DNS-specific error code as defined in Winerror.h.

## Remarks

The
**DnsModifyRecordsInSet** function type executes in the following steps.

1. Records specified in *pDeleteRecords* are deleted. If *pDeleteRecords* is empty or does not contain records that exist in the current set, the **DnsModifyRecordsInSet** function goes to the next step.
2. Records specified in *pAddRecords* are added. If *pAddRecords* is empty, the operation completes without adding any records.

To add a new record, provide no records in *pDeleteRecords*, and provide the record to be added in *pAddRecords*. To modify a record, specify the record being modified in *pDeleteRecords*, then add the modified version of that record by placing it in *pAddRecords*. To delete records, specify only records to be deleted. Multiple records can be added or deleted in a single call to **DnsModifyRecordsInSet**; however, the value of the **pName** member in each [DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) must be the same or the call will fail. If a record specified in *pAddRecords* is already present, no change occurs.

If no server list is specified, the default name server is queried.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DnsQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsquery_a)

[DnsReplaceRecordSet](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsreplacerecordseta)