# IFaxReceiptOptions::Save

## Description

The **IFaxReceiptOptions::Save** method saves the [FaxReceiptOptions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxreceiptoptions) object data.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is not supported for Windows XP when the receipt type is set to [frtMAIL](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_receipt_type_enum), or if [IFaxReceiptOptions::get_UseForInboundRouting](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxreceiptoptions-useforinboundrouting-vb)  is set to **TRUE**. In these cases, this method will return the error: [FAX_E_NOT_SUPPORTED_ON_THIS_SKU](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-error-codes).

To use this method, a user must have the [farMANAGE_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) and [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access rights.

## See also

[FaxReceiptOptions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxreceiptoptions)

[IFaxReceiptOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxreceiptoptions)

[Setting Receipt Options](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-setting-receipt-options)