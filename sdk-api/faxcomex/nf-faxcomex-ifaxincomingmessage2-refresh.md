# IFaxIncomingMessage2::Refresh

## Description

Refreshes [FaxIncomingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage) object information from the fax server. When the **Refresh** method is called, any configuration changes made after the last [Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-save-vb) method call are lost, except for the properties that are committed with the [IFaxIncomingMessage2::Reassign](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-reassign-vb) method: [IFaxIncomingMessage2::Subject](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-subject-vb), [IFaxIncomingMessage2::SenderName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-sendername-vb), [IFaxIncomingMessage2::SenderFaxNumber](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-senderfaxnumber-vb), and [IFaxIncomingMessage2::HasCoverPage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-hascoverpage-vb).

**Note** This method is supported only in Windows Vista and later.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [far2QUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) access rights.

## See also

[FaxIncomingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage)

[IFaxIncomingMessage2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessage2)