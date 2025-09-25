# IFaxOutgoingArchive::GetMessage

## Description

The **IFaxOutgoingArchive::GetMessage** method returns a fax message from the archive of outbound faxes by using the fax message ID.

## Parameters

### `bstrMessageId`

Type: **BSTR**

Specifies a null-terminated string that contains the message ID of the fax to retrieve from the archive of outbound faxes.

### `pFaxOutgoingMessage` [out, retval]

Type: **[IFaxOutgoingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingmessage)****

Address of a pointer that receives a [IFaxOutgoingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingmessage) interface.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) or **farQUERY_OUT_ARCHIVE** access right. With the **farSUBMIT_LOW** access right, the user will be able to use this method only for his own faxes. With the **farQUERY_OUT_ARCHIVE** access right, he will be able to use this method for all of the faxes on the server.

## See also

[FaxOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingarchive)

[IFaxOutgoingArchive](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingarchive)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-the-outgoing-archive)