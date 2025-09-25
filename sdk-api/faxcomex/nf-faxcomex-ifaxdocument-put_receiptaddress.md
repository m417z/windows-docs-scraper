# IFaxDocument::put_ReceiptAddress

## Description

The **IFaxDocument::get_ReceiptAddress** property is a null-terminated string that indicates the email address to which the fax service should send a delivery receipt when the fax job reaches a final state.

This property is read/write.

## Parameters

## Remarks

This property has meaning only if the [ReceiptType](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-receipttype-vb) property for the document is set to [frtMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_receipt_type_enum), indicating that the delivery receipt will be sent by email.

## See also

[FaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument)

[IFaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdocument)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-sending-a-fax)