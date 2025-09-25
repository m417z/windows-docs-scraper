# IFaxIncomingMessage2::put_SenderFaxNumber

## Description

Contains the sender's fax number associated with the inbound fax message. This property is a null-terminated string.

**Note** This property is supported only in Windows Vista and later.

This property is read/write.

## Parameters

## Remarks

A received message starts with a null value for the sender's fax number when it arrives. A [routing assistant](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-glossary) can specify the sender's fax number when the fax is reassigned.

## See also

[FaxIncomingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage)

[IFaxIncomingMessage2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessage2)