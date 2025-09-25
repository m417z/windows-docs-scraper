# DnsWriteQuestionToBuffer_UTF8 function

## Description

The
**DnsWriteQuestionToBuffer** function type creates a DNS query message and stores it in a
[DNS_MESSAGE_BUFFER](https://learn.microsoft.com/windows/desktop/api/windnsdef/ns-windnsdef-dns_message_buffer) structure. Like many DNS functions, the
**DnsWriteQuestionToBuffer** function type is implemented in multiple forms to facilitate different character encoding. Based on the character encoding involved, use one of the following functions:

* **DnsWriteQuestionToBuffer_W** (_W for Unicode encoding)
* **DnsWriteQuestionToBuffer_UTF8** (_UTF8 for UTF-8 encoding)

If the
**DnsWriteQuestionToBuffer** function type is used without its suffix (either _W or _UTF8), a compiler error will occur.

## Parameters

### `pDnsBuffer` [in, out]

A pointer to a [DNS_MESSAGE_BUFFER](https://learn.microsoft.com/windows/desktop/api/windnsdef/ns-windnsdef-dns_message_buffer) structure that contains a DNS query message stored in a buffer.

### `pdwBufferSize` [in, out]

The size, in bytes, of the buffer allocated to store *pDnsBuffer*. If the buffer size is insufficient to contain the message, **FALSE** is returned and *pdwBufferSize* contains the minimum required buffer size.

### `pszName` [in]

A pointer to a string that represents the name of the owner of the record set being queried.

### `wType` [in]

A value that represents the RR [DNS Record Type](https://learn.microsoft.com/windows/desktop/DNS/dns-constants). **wType** determines the format of **Data**. For example, if the value of **wType** is **DNS_TYPE_A**, the data type of **Data** is [DNS_A_DATA](https://learn.microsoft.com/windows/win32/api/windns/nf-windns-dnsquery_a).

### `Xid` [in]

A value that specifies the unique DNS query identifier.

### `fRecursionDesired` [in]

A BOOL that specifies whether recursive name query should be used by the DNS name server. Set to **TRUE** to request recursive name query, **FALSE** to request iterative name query.

## Return value

Returns **TRUE** upon successful execution, otherwise **FALSE**.

## Remarks

The following declaration for **DnsWriteQuestionToBuffer_UTF8** can be found in Windns.h.

``` syntax
BOOL
WINAPI
DnsWriteQuestionToBuffer_UTF8(
    __inout     PDNS_MESSAGE_BUFFER pDnsBuffer,
    __inout     PDWORD              pdwBufferSize,
    __in        PCSTR               pszName,
    __in        WORD                wType,
    __in        WORD                Xid,
    __in        BOOL                fRecursionDesired
    );
```

## See also

[DNS_MESSAGE_BUFFER](https://learn.microsoft.com/windows/desktop/api/windnsdef/ns-windnsdef-dns_message_buffer)

[DNS_RECORD](https://learn.microsoft.com/windows/win32/api/windnsdef/ns-windnsdef-dns_recorda)

[DnsQuery](https://learn.microsoft.com/windows/desktop/api/windns/nf-windns-dnsquery_a)