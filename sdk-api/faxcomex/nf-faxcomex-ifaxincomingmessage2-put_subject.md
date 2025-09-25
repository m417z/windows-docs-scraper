# IFaxIncomingMessage2::put_Subject

## Description

The **Subject** property contains the subject associated with the inbound fax message. This property is a null-terminated string.

**Note** This property is supported only in Windows Vista and later.

This property is read/write.

## Parameters

## Remarks

A received message starts with a null value for the subject when it arrives. It can be given a subject by a [routing assistant](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-glossary) when it is reassigned.

## See also

[FaxIncomingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage)

[IFaxIncomingMessage2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessage2)