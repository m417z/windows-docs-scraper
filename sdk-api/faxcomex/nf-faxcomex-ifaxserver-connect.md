# IFaxServer::Connect

## Description

The **IFaxServer::Connect** method connects a fax client application to the specified fax server.

## Parameters

### `bstrServerName`

Type: **BSTR**

A null-terminated string that specifies the name of the target fax server, such as "computername". If this parameter is **NULL** or an empty string, the method connects the application to the fax server on the local computer.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Before accessing most of the objects of the fax extended Component Object Model (COM), the application must call this method to initiate a connection with an active fax server. A fax server connection is not required for you to access a [FaxDocument](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdocument) object. The method fails if the client is not connected to an active fax server.

To connect to the local server, set the *bstrServerName* parameter to **NULL** or an empty string. For usage examples, see [Connecting to the Fax Server](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-connecting-to-the-fax-server).

## See also

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcomex/nn-faxcomex-ifaxserver)

[Visual Basic Example](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-retrieving-server-properties)