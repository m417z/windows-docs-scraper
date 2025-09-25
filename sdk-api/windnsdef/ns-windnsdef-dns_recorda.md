# DNS_RECORDA structure

## Description

The
**DNS_RECORD** structure stores a DNS resource record (RR).

## Members

### `pNext`

A pointer to the next
**DNS_RECORD** structure.

### `pName`

A pointer to a string that represents the domain name of the record set. This must be in the string format that corresponds to the function called, such as ANSI, Unicode, or UTF8.

### `wType`

A value that represents the RR [DNS Record Type](https://learn.microsoft.com/windows/win32/DNS/dns-constants). **wType** determines the format of **Data**. For example, if the value of **wType** is **DNS_TYPE_A**, the data type of **Data** is [DNS_A_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsquery_a).

### `wDataLength`

The length, in bytes, of **Data**. For fixed-length data types, this value is the size of the corresponding data type, such as **sizeof(DNS_A_DATA)**. For the non-fixed data types, use one of the following macros to determine the length of the data:

| C++ |
| --- |
| ``` #include <windows.h><br><br>#define DNS_NULL_RECORD_LENGTH(ByteCount) (sizeof(DWORD) + (ByteCount)) #define DNS_WKS_RECORD_LENGTH(ByteCount) (sizeof(DNS_WKS_DATA) + (ByteCount-1)) #define DNS_WINS_RECORD_LENGTH(IpCount) (sizeof(DNS_WINS_DATA) + ((IpCount-1) * sizeof(IP_ADDRESS))) #define DNS_TEXT_RECORD_LENGTH(StringCount) (sizeof(DWORD) + ((StringCount) * sizeof(PCHAR))) ``` |

### `Flags`

### `Flags.DW`

 A value that contains a bitmap of [DNS Record Flags](https://learn.microsoft.com/windows/win32/DNS/dns-constants).

### `Flags.S`

A set of flags in the form of a
[DNS_RECORD_FLAGS](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_record_flags) structure.

### `dwTtl`

The DNS RR's Time To Live value (TTL), in seconds.

### `dwReserved`

Reserved. Do not use.

### `Data`

The DNS RR data type is determined by **wType** and is one of the following members:

#### SOA, Soa

The RR data type is [DNS_SOA_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_soa_dataw). The value of **wType** is **DNS_TYPE_SOA**.

#### PTR, Ptr, NS, Ns, CNAME, Cname, DNAME, Dname, MB, Mb, MD, Md, MF, Mf, MG, Mg, MR, Mr

The RR data type is [DNS_PTR_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsquery_w). The value of **wType** is **DNS_TYPE_PTR**.

#### MINFO, Minfo, RP, Rp

The RR data type is [DNS_MINFO_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_minfo_dataw). The value of **wType** is **DNS_TYPE_MINFO**.

#### MX, Mx, AFSDB, Afsdb, RT, Rt

The RR data type is [DNS_MX_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_mx_dataa). The value of **wType** is **DNS_TYPE_MX**.

#### HINFO, Hinfo, ISDN, Isdn, TXT, Txt, X25

The RR data type is [DNS_TXT_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_txt_dataw). The value of **wType** is **DNS_TYPE_TEXT**.

#### WKS, Wks

The RR data type is [DNS_WKS_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_wks_data). The value of **wType** is **DNS_TYPE_WKS**.

#### KEY, Key

The RR data type is [DNS_KEY_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_key_data). The value of **wType** is **DNS_TYPE_KEY**.

#### SIG, Sig

The RR data type is [DNS_SIG_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms682094(v=vs.85)). The value of **wType** is **DNS_TYPE_SIG**.

#### ATMA, Atma

The RR data type is [DNS_ATMA_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_atma_data). The value of **wType** is **DNS_TYPE_ATMA**.

#### NXT, Nxt

The RR data type is [DNS_NXT_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_nxt_dataa). The value of **wType** is **DNS_TYPE_NXT**.

#### SRV, Srv

The RR data type is [DNS_SRV_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_srv_dataa). The value of **wType** is **DNS_TYPE_SRV**.

#### NAPTR, Naptr

The RR data type is [DNS_NAPTR_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_naptr_dataa). The value of **wType** is **DNS_TYPE_NAPTR**.

#### OPT, Opt

Windows 7 or later: The RR data type is [DNS_OPT_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_opt_data). The value of **wType** is **DNS_TYPE_OPT**.

#### DS, Ds

Windows 7 or later: The RR data type is [DNS_DS_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_ds_data). The value of **wType** is **DNS_TYPE_DS**.

#### RRSIG, Rrsig

Windows 7 or later: The RR data type is [DNS_RRSIG_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_sig_dataw). The value of **wType** is **DNS_TYPE_RRSIG**.

#### NSEC, Nsec

Windows 7 or later: The RR data type is [DNS_NSEC_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_nsec_dataa). The value of **wType** is **DNS_TYPE_NSEC**.

#### DNSKEY, Dnskey

Windows 7 or later: The RR data type is [DNS_DNSKEY_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd392295(v=vs.85)). The value of **wType** is **DNS_TYPE_DNSKEY**.

#### TKEY, Tkey

The RR data type is [DNS_TKEY_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_tkey_dataa). The value of **wType** is **DNS_TYPE_TKEY**.

#### TSIG, Tsig

The RR data type is [DNS_TSIG_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_tsig_dataa). The value of **wType** is **DNS_TYPE_TSIG**.

#### WINS, Wins

The RR data type is [DNS_WINS_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_wins_data). The value of **wType** is **DNS_TYPE_WINS**.

#### WINSR, WinsR, NBSTAT, Nbstat

The RR data type is [DNS_WINSR_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_winsr_dataw). The value of **wType** is **DNS_TYPE_WINSR**.

### `Data.A`

The RR data type is [DNS_A_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsquery_a). The value of **wType** is **DNS_TYPE_A**.

### `Data.SOA`

### `Data.Soa`

### `Data.PTR`

### `Data.Ptr`

### `Data.NS`

### `Data.Ns`

### `Data.CNAME`

### `Data.Cname`

### `Data.DNAME`

### `Data.Dname`

### `Data.MB`

### `Data.Mb`

### `Data.MD`

### `Data.Md`

### `Data.MF`

### `Data.Mf`

### `Data.MG`

### `Data.Mg`

### `Data.MR`

### `Data.Mr`

### `Data.MINFO`

### `Data.Minfo`

### `Data.RP`

### `Data.Rp`

### `Data.MX`

### `Data.Mx`

### `Data.AFSDB`

### `Data.Afsdb`

### `Data.RT`

### `Data.Rt`

### `Data.HINFO`

### `Data.Hinfo`

### `Data.ISDN`

### `Data.Isdn`

### `Data.TXT`

### `Data.Txt`

### `Data.X25`

### `Data.Null`

The RR data type is [DNS_NULL_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_null_data). The value of **wType** is **DNS_TYPE_NULL**.

### `Data.WKS`

### `Data.Wks`

### `Data.AAAA`

The RR data type is [DNS_AAAA_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_aaaa_data). The value of **wType** is **DNS_TYPE_AAAA**.

### `Data.KEY`

### `Data.Key`

### `Data.SIG`

### `Data.Sig`

### `Data.ATMA`

### `Data.Atma`

### `Data.NXT`

### `Data.Nxt`

### `Data.SRV`

### `Data.Srv`

### `Data.NAPTR`

### `Data.Naptr`

### `Data.OPT`

### `Data.Opt`

### `Data.DS`

### `Data.Ds`

### `Data.RRSIG`

### `Data.Rrsig`

### `Data.NSEC`

### `Data.Nsec`

### `Data.DNSKEY`

### `Data.Dnskey`

### `Data.TKEY`

### `Data.Tkey`

### `Data.TSIG`

### `Data.Tsig`

### `Data.WINS`

### `Data.Wins`

### `Data.WINSR`

### `Data.WinsR`

### `Data.NBSTAT`

### `Data.Nbstat`

### `Data.DHCID`

Windows 7 or later: The RR data type is [DNS_DHCID_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windns-dns_dhcid_data). The value of **wType** is **DNS_TYPE_DHCID**.

### `Data.NSEC3`

### `Data.Nsec3`

### `Data.NSEC3PARAM`

### `Data.Nsec3Param`

### `Data.TLSA`

### `Data.Tlsa`

### `Data.SVCB`

Type: **[DNS_SVCB_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_svcb_data)**

TBD

### `Data.Svcb`

Type: **[DNS_SVCB_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_svcb_data)**

TBD

### `Data.UNKNOWN`

### `Data.Unknown`

### `Data.pDataPtr`

## Remarks

When building a
**DNS_RECORD** list as an input argument for the various DNS update routines found in the DNS API, all flags in the
**DNS_RECORD** structure should be set to zero.

> [!NOTE]
> The windns.h header defines DNS_RECORD as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DNS_AAAA_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_aaaa_data)

[DNS_ATMA_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_atma_data)

[DNS_A_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsquery_a)

[DNS_DHCID_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windns-dns_dhcid_data)

[DNS_DNSKEY_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd392295(v=vs.85))

[DNS_DS_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_ds_data)

[DNS_KEY_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_key_data)

[DNS_LOC_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_loc_data)

[DNS_MINFO_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_minfo_dataw)

[DNS_MX_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_mx_dataa)

[DNS_NAPTR_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_naptr_dataa)

[DNS_NSEC_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_nsec_dataa)

[DNS_NULL_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_null_data)

[DNS_NXT_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_nxt_dataa)

[DNS_OPT_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_opt_data)

[DNS_PTR_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsquery_w)

[DNS_RRSIG_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_sig_dataw)

[DNS_SIG_DATA](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms682094(v=vs.85))

[DNS_SOA_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_soa_dataw)

[DNS_SRV_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_srv_dataa)

[DNS_TKEY_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_tkey_dataa)

[DNS_TSIG_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_tsig_dataa)

[DNS_TXT_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_txt_dataw)

[DNS_WINSR_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_winsr_dataw)

[DNS_WINS_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_wins_data)

[DNS_WKS_DATA](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_wks_data)

[DnsExtractRecordsFromMessage](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsextractrecordsfrommessage_utf8)

[DnsModifyRecordsInSet](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsmodifyrecordsinset_a)

[DnsQuery](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsquery_a)

[DnsRecordCompare](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsrecordcompare)

[DnsRecordCopyEx](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsrecordcopyex)

[DnsRecordSetCompare](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsrecordsetcompare)

[DnsRecordSetDetach](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsrecordsetdetach)

[DnsReplaceRecordSet](https://learn.microsoft.com/windows/win32/api/windnsdef/nf-windns-dnsreplacerecordseta)