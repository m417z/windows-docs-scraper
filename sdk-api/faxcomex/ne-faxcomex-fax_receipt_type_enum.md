# FAX_RECEIPT_TYPE_ENUM enumeration

## Description

The **FAX_RECEIPT_TYPE_ENUM** enumeration defines the types of delivery reports (delivery receipt formats) for outbound faxes. The members of this enumeration are bit values and can be used in combination.

## Constants

### `frtNONE:0`

Do not send a delivery report.

### `frtMAIL:0x1`

Send a delivery report through SMTP mail.

### `frtMSGBOX:0x4`

Display a delivery report in a message box on the display of a specific computer. This is not supported in Windows Vista.

## See also

[IFaxDocument::get_ReceiptType](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-receipttype-vb)

[IFaxOutgoingJob::get_ReceiptType](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingjob-receipttype-vb)