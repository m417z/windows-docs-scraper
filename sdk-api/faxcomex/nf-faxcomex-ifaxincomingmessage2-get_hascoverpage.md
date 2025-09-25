# IFaxIncomingMessage2::get_HasCoverPage

## Description

A flag that indicates whether the fax has a cover page.

**Note** This property is supported only in Windows Vista and later.

This property is read/write.

## Parameters

## Remarks

A received message has a VARIANT_FALSE value when it arrives. A [routing assistant](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-glossary) application can set this to VARIANT_TRUE when it is reassigned.

A change to this value is not committed to the server until [IFaxIncomingMessage2::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-save-vb) is called.

## See also

[FaxIncomingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage)

[IFaxIncomingMessage2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessage2)