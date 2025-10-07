# IFaxIncomingMessage2::get_Recipients

## Description

Contains the recipients associated with the inbound fax message. This property is a null-terminated string.

**Note** This property is supported only in Windows Vista and later.

This property is read/write.

## Parameters

## Remarks

A received message starts with a null value for the recipients when it arrives. A list of recipients can be specified by a [routing assistant](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-glossary) when it is reassigned.

Each recipient is identified on the pattern of \<DomainName>\<UserName>. A colon ":" separates each recipient. For local users, \<DomainName> is the local computer name.

## See also

[FaxIncomingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage)

[IFaxIncomingMessage2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessage2)