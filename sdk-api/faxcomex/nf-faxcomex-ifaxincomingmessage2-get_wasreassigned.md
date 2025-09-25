# IFaxIncomingMessage2::get_WasReAssigned

## Description

Indicates if the fax has been reassigned.

**Note** This property is supported only in Windows Vista and later.

This property is read-only.

## Parameters

## Remarks

This property is always VARIANT_FALSE when the fax arrives at the server. If it is reassigned by a [routing assistant](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-glossary), the fax service sets it to VARIANT_TRUE.

## See also

[FaxIncomingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage)

[IFaxIncomingMessage2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessage2)