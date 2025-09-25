# IFaxIncomingMessage2::ReAssign

## Description

[Reassign](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-glossary) the fax to one or more recipients. It also commits changes to the [IFaxIncomingMessage2::Subject](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-subject-vb), [IFaxIncomingMessage2::SenderName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-sendername-vb), [IFaxIncomingMessage2::SenderFaxNumber](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-senderfaxnumber-vb), and [IFaxIncomingMessage2::HasCoverPage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-hascoverpage-vb) properties.

**Note** This method is supported only in Windows Vista and later.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [far2MANAGE_RECEIVE_FOLDER](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) and [far2QUERY_CONFIG](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) access rights. Also, IFaxConfiguration::IncomingFaxesArePublic must be set to false.

If the [routing assistant](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-glossary) application is going to set the [IFaxIncomingMessage2::Subject](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-subject-vb), [IFaxIncomingMessage2::SenderName](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-sendername-vb), [IFaxIncomingMessage2::SenderFaxNumber](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-senderfaxnumber-vb), or [IFaxIncomingMessage2::HasCoverPage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-hascoverpage-vb) properties, it should do this before calling **IFaxIncomingMessage2::Reassign**. **Reassign** will commit those changes, so it is not necessary to call [IFaxIncomingMessage2::Save](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage-save-vb).

## See also

[FaxIncomingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage)

[IFaxIncomingMessage2](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessage2)