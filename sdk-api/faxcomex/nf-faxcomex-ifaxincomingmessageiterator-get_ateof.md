# IFaxIncomingMessageIterator::get_AtEOF

## Description

The **AtEOF** property is the end of file marker for the archive of inbound fax messages. If this property is equal to **TRUE**, the archive cursor has moved beyond the last fax message in the inbound fax archive. If this property is equal to **FALSE**, the archive cursor has not yet reached the end of the archive.

This property is read-only.

## Parameters

## Remarks

To use this method, a user must have the [farQUERY_IN_ARCHIVE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxIncomingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessageiterator)

[IFaxIncomingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessageiterator)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-opening-a-fax-from-the-incoming-archive)