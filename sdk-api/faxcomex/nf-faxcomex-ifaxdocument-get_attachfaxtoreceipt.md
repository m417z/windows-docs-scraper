# IFaxDocument::get_AttachFaxToReceipt

## Description

The **IFaxDocument::get_AttachFaxToReceipt** property indicates whether to attach a fax to the receipt.

This property is read/write.

## Parameters

## Remarks

By default, **IFaxDocument::get_AttachFaxToReceipt** is set to **FALSE**.

When a fax consisting only of a cover page is sent to multiple recipients, you cannot attach the fax to the receipt because the fax differs for each recipient. If there is a fax body, then the body can be attached to the receipt, even when there are multiple recipients.

## See also

[FaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument)

[IFaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxdocument)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-sending-a-fax)