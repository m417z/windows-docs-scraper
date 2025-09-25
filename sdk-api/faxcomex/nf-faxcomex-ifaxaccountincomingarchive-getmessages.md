# IFaxAccountIncomingArchive::GetMessages

## Description

Returns a new iterator (archive cursor) for the archive of inbound fax messages for a particular fax account.

## Parameters

### `lPrefetchSize` [in]

Type: **long**

**long** value that indicates the size of the prefetch buffer. This value determines how many fax messages the iterator object retrieves from the fax server when the object needs to refresh its contents. The default value is [lDEFAULT_PREFETCH_SIZE](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ldefault-prefetch-size).

### `pFaxIncomingMessageIterator`

Type: **IFaxIncomingMessageIterator****

A [FaxIncomingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessageiterator) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

If the setting 'All incoming faxes are viewable by everyone' is true (see [IncomingFaxesArePublic](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxconfiguration-incomingfaxesarepublic-vb)) or if [far2MANAGE_RECEIVE_FOLDER](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum_2) access rights, then the fax service enumerates all faxes in the Incoming archive of the Fax Server Receive Folder.

## See also

[FaxAccountIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive)

[FaxIncomingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessageiterator)

[IFaxAccountIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccountincomingarchive)