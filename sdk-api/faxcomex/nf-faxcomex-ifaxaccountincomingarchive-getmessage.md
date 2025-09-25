# IFaxAccountIncomingArchive::GetMessage

## Description

Returns a fax message from the archive of inbound faxes, for a particular fax account, by using the fax message ID.

## Parameters

### `bstrMessageId` [in]

Type: **BSTR**

Specifies a null-terminated string that contains the message ID of the fax to retrieve from the archive of inbound faxes.

### `pFaxIncomingMessage`

Type: **[IFaxIncomingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessage)****

An [IFaxIncomingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessage) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [far2QUERY_ARCHIVES](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) access right.

If the setting 'All incoming faxes are viewable by everyone' is true (see [IncomingFaxesArePublic](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxconfiguration-incomingfaxesarepublic-vb)) or if [far2MANAGE_RECEIVE_FOLDER](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) access rights, then the fax service searches all faxes in the Incoming archive of the Fax Server Receive Folder.

## See also

[FaxAccountIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive)

[IFaxAccountIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccountincomingarchive)