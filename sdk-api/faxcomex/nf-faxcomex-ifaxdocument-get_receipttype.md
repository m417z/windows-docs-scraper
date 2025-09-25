# IFaxDocument::get_ReceiptType

## Description

The **IFaxDocument::get_ReceiptType** property specifies the type of delivery receipt to deliver when the fax job reaches a final state.

This property is read/write.

## Parameters

## Remarks

The fax service sends a report (a delivery receipt) to the sender of the fax when the fax completes successfully or when the fax transmission fails.

If an email receipt will be sent, an address has to be provided in the [IFaxDocument::get_ReceiptAddress](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument-receiptaddress-vb) property. If the receipt type is set to [frtMSGBOX](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_receipt_type_enum), the message box will appear on the computer from which the document was sent. By default, **ReceiptType** is set to [frtNONE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_receipt_type_enum), indicating that no receipt will be sent.

## See also

[FaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument)

[IFaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdocument)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-sending-a-fax)