# IFaxIncomingMessage2::get_SenderName

## Description

Contains the name of the sender that is associated with the inbound fax message. This property is a null-terminated string.

**Note** This property is supported only in Windows Vista and later.

This property is read/write.

## Parameters

## Remarks

A received message starts with a null value for the sender when it arrives. A sender can be specified by a [routing assistant](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-glossary) when it is re-assigned.

## See also

[FaxIncomingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage)

[IFaxIncomingMessage2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessage2)