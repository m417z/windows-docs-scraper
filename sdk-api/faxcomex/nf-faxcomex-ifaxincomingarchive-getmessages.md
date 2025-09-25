# IFaxIncomingArchive::GetMessages

## Description

The **GetMessages** method returns a new iterator (archive cursor) for the archive of inbound fax messages.

## Parameters

### `lPrefetchSize` [in]

Type: **long**

**long** value that indicates the size of the prefetch buffer. This value determines how many fax messages the iterator object retrieves from the fax server when the object needs to refresh its contents. The default value is [lDEFAULT_PREFETCH_SIZE](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ldefault-prefetch-size).

### `pFaxIncomingMessageIterator` [out, retval]

Type: **[IFaxIncomingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessageiterator)****

A [FaxIncomingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessageiterator) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farQUERY_IN_ARCHIVE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[FaxIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingarchive)

[FaxIncomingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessageiterator)

[IFaxIncomingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingarchive)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-opening-a-fax-from-the-incoming-archive)