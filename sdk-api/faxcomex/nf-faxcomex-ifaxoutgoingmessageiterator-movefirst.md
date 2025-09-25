# IFaxOutgoingMessageIterator::MoveFirst

## Description

The **IFaxOutgoingMessageIterator::MoveFirst** method moves the archive cursor to the first fax message in the outbound archive.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) and **farQUERY_OUT_ARCHIVE** access rights.

## See also

[FaxOutgoingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingmessageiterator)

[IFaxOutgoingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingmessageiterator)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-opening-a-fax-from-the-outgoing-archive)