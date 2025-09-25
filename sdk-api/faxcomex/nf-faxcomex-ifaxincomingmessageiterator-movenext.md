# IFaxIncomingMessageIterator::MoveNext

## Description

The **MoveNext** method moves the archive cursor to the next message in the archive of inbound faxes.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You can make the iteration process more efficient by using a prefetch buffer. A prefetch buffer contains messages and allows you to iterate through the buffer rather than through a folder. Set the size of the buffer (the number of messages to be held in the buffer) using the [PrefetchSize](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessageiterator-prefetchsize) property.

To use this method, a user must have the [farQUERY_IN_ARCHIVE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxIncomingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessageiterator)

[IFaxIncomingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessageiterator)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-opening-a-fax-from-the-incoming-archive)