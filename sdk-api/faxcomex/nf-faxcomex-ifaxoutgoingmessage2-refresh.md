# IFaxOutgoingMessage2::Refresh

## Description

Refreshes [FaxOutgoingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingmessage) object information from the fax server. When the **Refresh** method is called, any configuration changes made after the last [Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingmessage-save-vb) method call are lost.

**Note** This method is supported only on Windows Vista and later.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [far2QUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) access rights.

## See also

[FaxOutgoingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingmessage)

[IFaxOutgoingMessage2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingmessage2)