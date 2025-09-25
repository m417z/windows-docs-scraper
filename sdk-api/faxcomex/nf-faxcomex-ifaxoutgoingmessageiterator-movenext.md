# IFaxOutgoingMessageIterator::MoveNext

## Description

The **IFaxOutgoingMessageIterator::MoveNext** method moves the archive cursor to the next fax message in the outbound archive.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The method will fail if the [IFaxOutgoingMessageIterator::get_AtEOF](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingmessageiterator-ateof-vb) property is equal to **TRUE**.

## See also

[FaxOutgoingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingmessageiterator)

[IFaxOutgoingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingmessageiterator)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-opening-a-fax-from-the-outgoing-archive)