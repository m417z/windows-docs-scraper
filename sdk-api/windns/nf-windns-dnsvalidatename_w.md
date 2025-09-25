# DnsValidateName_W function

## Description

The
**DnsValidateName** function validates the status of a specified DNS name. Like many DNS functions, the
**DnsValidateName** function type is implemented in multiple forms to facilitate different character encoding. Based on the character encoding involved, use one of the following functions:

* **DnsValidateName_A** (_A for ANSI encoding)
* **DnsValidateName_W** (_W for Unicode encoding)
* **DnsValidateName_UTF8** (_UTF8 for UTF-8 encoding)

## Parameters

### `pszName` [in]

A pointer to a string that represents the DNS name to be examined.

### `Format` [in]

A [DNS_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/windns/ne-windns-dns_name_format) value that specifies the format of the name to be examined.

## Return value

The
**DnsValidateName** function has the following possible return values:

## Remarks

To verify the status of the Computer Host (single label), use the
**DnsValidateName** function type with **DnsNameHostnameLabel** in *Format*.

The
**DnsValidateName** function works in a progression when determining whether an error exists with a given DNS name, and returns upon finding its first error. Therefore, a DNS name that has multiple, different errors may be reported as having the first error, and could be corrected and resubmitted, only then to find the second error.

The
**DnsValidateName** function searches for errors as follows:

1. Returns **ERROR_INVALID_NAME** if the DNS name:
   * Is longer than 255 octets.
   * Contains a label longer than 63 octets.
   * Contains two or more consecutive dots.
   * Begins with a dot (.).
   * Contains a dot (.) if the name is submitted with *Format* set to DnsNameDomainLabel or DnsNameHostnameLabel.
2. Next,
   **DnsValidateName** returns **DNS_ERROR_NUMERIC_NAME** if the full DNS name consists of only numeric characters (0-9) or the first label of the DNS name consists of only numeric characters (0-9), unless *Format* is set to DnsNameDomainLabel or DnsNameDomain.
3. Then,
   **DnsValidateName** returns DNS_ERROR_NON_RFC_NAME if the DNS name:
   * Contains at least one extended or Unicode character.**Note** Windows 8 or later: **DnsValidateName_W** does not return an error if International Domain Name (IDN) encoding is enabled.
   * Contains underscore (_), unless the underscore is a first character in a label, in the name, submitted with *Format* set to DnsNameSrvRecord.
4. Next,
   **DnsValidateName** returns **DNS_ERROR_INVALID_NAME_CHAR** if the DNS name:
   * Contains a space.
   * Contains any of the following invalid characters: { | } ~ [ \ ] ^ ' : ; < = > ? & @ ! " # $ % ^ ` ( ) + / ,
   * Contains an asterisk (*), unless the asterisk is the first label in the multi-labeled name, submitted with *Format* set to **DnsNameWildcard**.

**Note** If
**DnsValidateName** returns **DNS_ERROR_NON_RFC_NAME**, the error should be handled as a warning that not all DNS servers will accept the name. When this error is received, note that the DNS Server does accept the submitted name, if appropriately configured (default configuration accepts the name as submitted when **DNS_ERROR_NON_RFC_NAME** is returned), but other DNS server software may not. Windows DNS servers do handle **NON_RFC_NAMES**.

If
**DnsValidateName** returns any of the following errors, *pszName* should be handled as an invalid host name:

DNS_ERROR_NUMERIC_NAME

DNS_ERROR_INVALID_NAME_CHAR

ERROR_INVALID_NAME

## See also

[DNS_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/windns/ne-windns-dns_name_format)

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DnsNameCompare](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsnamecompare)

[DnsQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsquery_a)