# IFaxOutgoingJob2::get_ReceiptAddress

## Description

A null-terminated string containing the address to which a delivery report will be sent, indicating success or failure.

This property is read-only.

## Parameters

## Remarks

The type of address will vary according to the value of the [ReceiptType](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob-receipttype-vb) property as indicated in this table.

| Value of [ReceiptType](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob-receipttype-vb) property | Type of address |
| --- | --- |
| frtMAIL | An SMTP email address |
| frtMSGBOX | The computer name on which the delivery report message box will appear |

## See also

[FaxOutgoingJob](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob)

[IFaxOutgoingJob2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingjob2)