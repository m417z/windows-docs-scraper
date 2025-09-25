# DnsReplaceRecordSetA function

## Description

The
**DnsReplaceRecordSet** function type replaces an existing resource record (RR) set. Like many DNS functions, the
**DnsReplaceRecordSet** function type is implemented in multiple forms to facilitate different character encoding, which is indicated by a suffix. Based on the character encoding involved, use one of the following functions:

**DnsReplaceRecordSetA** (_A for ANSI encoding)

**DnsReplaceRecordSetW** (_W for Unicode encoding)

**DnsReplaceRecordSetUTF8** (_UTF8 for UTF 8 encoding)

Be aware of the lack of an underscore between the function type name and its suffix. If the
**DnsReplaceRecordSet** function type is called without its suffix (A, W, or UTF8), a compiler error will occur.

## Parameters

### `pReplaceSet` [in]

A pointer to a
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure that contains the RR set that replaces the existing set. The specified RR set is replaced with the contents of *pNewSet*. To delete a RR set, specify the set in *pNewSet*, but set *RDATA* to **NULL**.

### `Options` [in]

A value that contains a bitmap of [DNS Update Options](https://learn.microsoft.com/windows/desktop/DNS/dns-constants). Options can be combined and all options override **DNS_UPDATE_SECURITY_USE_DEFAULT**.

### `hContext` [in, optional]

The handle to the credentials of a specific account. Used when secure dynamic update is required. This parameter is optional.

### `pExtraInfo` [in, out, optional]

This parameter is reserved for future use and must be set to **NULL**.

### `pReserved` [in, out, optional]

This parameter is reserved for future use and must be set to **NULL**.

## Return value

Returns success confirmation upon successful completion. Otherwise, returns the appropriate DNS-specific error code as defined in Winerror.h.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DnsModifyRecordsInSet](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsmodifyrecordsinset_a)

## Remarks

> [!NOTE]
> The windns.h header defines DnsReplaceRecordSet as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).