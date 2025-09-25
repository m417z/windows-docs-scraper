# IFaxAccountOutgoingArchive::GetMessages

## Description

Returns a new iterator (archive cursor) for the archive of outbound fax messages for a particular fax account.

## Parameters

### `lPrefetchSize` [in]

Type: **long**

**long** value that indicates the size of the prefetch buffer. This value determines how many fax messages the iterator object retrieves from the fax server when the object needs to refresh its contents. The default value is [lDEFAULT_PREFETCH_SIZE](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ldefault-prefetch-size).

### `pFaxOutgoingMessageIterator`

Type: **IFaxOutgoingMessageIterator****

A [FaxOutgoingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingmessageiterator) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FaxAccountOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountoutgoingarchive)

[FaxOutgoingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingmessageiterator)

[IFaxAccountOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxaccountoutgoingarchive)