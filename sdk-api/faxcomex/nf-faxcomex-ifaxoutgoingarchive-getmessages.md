# IFaxOutgoingArchive::GetMessages

## Description

The **IFaxOutgoingArchive::GetMessages** method returns a new iterator (archive cursor) for the archive of outbound fax messages. For more information, see [IFaxOutgoingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingmessageiterator).

## Parameters

### `lPrefetchSize`

Type: **long**

A **long** value that specifies the size of the prefetch buffer. This value determines how many fax messages the iterator object retrieves from the fax server when the object needs to refresh its contents. The default value is [lDEFAULT_PREFETCH_SIZE](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ldefault-prefetch-size).

### `pFaxOutgoingMessageIterator` [out, retval]

Type: **[IFaxOutgoingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingmessageiterator)****

An address of a pointer that receives the [IFaxOutgoingMessageIterator](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingmessageiterator) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) or **farQUERY_OUT_ARCHIVE** access right. With the **farSUBMIT_LOW** access right, the user will be able to use this method only for his own faxes. With the **farQUERY_OUT_ARCHIVE** access right, he will be able to use this method for all of the faxes on the server.

## See also

[IFaxOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingarchive)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-opening-a-fax-from-the-outgoing-archive)