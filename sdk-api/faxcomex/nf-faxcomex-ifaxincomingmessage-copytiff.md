# IFaxIncomingMessage::CopyTiff

## Description

The **CopyTiff** method copies the Tagged Image File Format Class F (TIFF Class F) file associated with the inbound fax message to a file on the local computer.

## Parameters

### `bstrTiffPath` [in]

Type: **BSTR**

Null-terminated **BSTR** that specifies a fully qualified path and file name on the local computer. The fax service will copy the TIFF Class F file associated with the inbound fax message to the specified file.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[FaxIncomingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxincomingmessage)

[IFaxIncomingMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxincomingmessage)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-managing-the-incoming-archive)