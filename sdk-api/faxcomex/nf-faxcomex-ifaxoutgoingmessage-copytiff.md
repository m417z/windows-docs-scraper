# IFaxOutgoingMessage::CopyTiff

## Description

The **IFaxOutgoingMessage::CopyTiff** method copies the Tagged Image File Format Class F (TIFF Class F) file associated with the outbound fax message, to a file on the local computer.

## Parameters

### `bstrTiffPath` [in]

Type: **BSTR**

Null-terminated string that contains a fully qualified path and file name on the local computer. This is the file on the local computer to which the fax service will copy the TIFF Class F file associated with the outbound fax message.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To use this method, a user must have the [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) or **farMANAGE_OUT_ARCHIVE** access right.

With the [farSUBMIT_LOW](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/ne-faxcomex-fax_access_rights_enum) access right, users will be able to use this method only for their own faxes. With the **farMANAGE_OUT_ARCHIVE** access right, users will be able to use this method for all faxes on the server.

## See also

[FaxOutgoingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxoutgoingmessage)

[IFaxOutgoingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxoutgoingmessage)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-opening-a-fax-from-the-outgoing-archive)