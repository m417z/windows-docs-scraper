# IFaxIncomingMessageIterator::put_PrefetchSize

## Description

The **PrefetchSize** property indicates the size of the prefetch (read-ahead) buffer.

This property is read/write.

## Parameters

## Remarks

The prefetch buffer contains messages and makes the iteration process more efficient because you iterate through the buffer rather than through a folder.

Changes you make to the size of the prefetch buffer take place immediately because [FaxIncomingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessageiterator) is a local object.

The value of the *lPrefetchSize* property determines how many fax messages the iterator object retrieves from the archive each time the object refreshes its contents. The default value is [lDEFAULT_PREFETCH_SIZE](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ldefault-prefetch-size).

To use this method, a user must have the [farQUERY_IN_ARCHIVE](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right.

## See also

[IFaxIncomingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessageiterator)

[PrefetchSize](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessageiterator-prefetchsize)