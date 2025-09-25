# IFaxIncomingMessageIterator::MoveFirst

## Description

The **MoveFirst** method moves the archive cursor to the first fax message in the archive of inbound faxes.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farQUERY_IN_ARCHIVE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxIncomingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessageiterator)

[IFaxIncomingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessageiterator)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-opening-a-fax-from-the-incoming-archive)