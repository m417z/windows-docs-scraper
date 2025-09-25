# DNS_ATMA_DATA structure

## Description

The
**DNS_ATMA_DATA** structure represents a DNS ATM address (ATMA) resource record (RR).

## Members

### `AddressType`

The format of the ATM address in **Address**. The possible values for **AddressType** are:

| Value | Meaning |
| --- | --- |
| **DNS_ATMA_FORMAT_AESA** | An address of the form: 39.246f.123456789abcdefa0123.00123456789a.00. It is a 40 hex character address mapped to 20 octets with arbitrarily placed "." separators. Its length is exactly **DNS_ATMA_AESA_ADDR_LENGTH** bytes. |
| **DNS_ATMA_FORMAT_E164** | An address of the form: +358.400.1234567\0. The null-terminated hex characters map one-to-one into the ATM address with arbitrarily placed "." separators. The '+' indicates it is an E.164 format address. Its length is less than **DNS_ATMA_MAX_ADDR_LENGTH** bytes. |

### `Address`

A **BYTE** array that contains the ATM address whose format is specified by **AddressType**.

## Remarks

The
**DNS_ATMA_DATA** structure is used in conjunction with the
[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda) structure to programmatically manage DNS entries.

## See also

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)