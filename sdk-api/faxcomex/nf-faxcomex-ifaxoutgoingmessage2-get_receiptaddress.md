# IFaxOutgoingMessage2::get_ReceiptAddress

## Description

Specifies the address to which the delivery report is sent.

**Note** This property is supported only on Windows Vista and later.

This property is read-only.

## Parameters

## Remarks

The type of address will vary according to the value of the [IFaxOutgoingMessage2::ReceiptType](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingmessage-receipttype-vb) property as indicated in this table.

| Value of [IFaxOutgoingMessage2::ReceiptType](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingmessage-receipttype-vb) property | Type of address |
| --- | --- |
| frtMAIL | An SMTP email address |
| frtMSGBOX | The computer name on which the delivery report message box will appear |

## See also

[FaxOutgoingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingmessage)

[IFaxOutgoingMessage2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingmessage2)