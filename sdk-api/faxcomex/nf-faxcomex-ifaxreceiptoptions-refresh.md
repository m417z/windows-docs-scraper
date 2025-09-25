# IFaxReceiptOptions::Refresh

## Description

The **IFaxReceiptOptions::Refresh** method refreshes [FaxReceiptOptions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxreceiptoptions) object information from the fax server. When the **IFaxReceiptOptions::Refresh** method is called, any configuration changes made after the last [IFaxReceiptOptions::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxreceiptoptions-save-vb) method call are lost.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farQUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxReceiptOptions](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxreceiptoptions)

[IFaxReceiptOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxreceiptoptions)