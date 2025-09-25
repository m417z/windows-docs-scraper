# IFaxServer::Connect

## Description

The **Connect** method connects a fax client application to the specified fax server. Before accessing most interfaces that begin with **IFax**, the application must call this method to initiate a connection with an active fax server. A fax server connection is not required to access an [IFaxTiff](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxtiff) interface.

## Parameters

### `ServerName` [in]

Type: **BSTR**

Specifies a null-terminated string that contains the name of the target fax server. If this parameter is **NULL**, the method connects the application to the fax server on the local computer. See [Connecting to a Fax Server](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-connecting-to-a-fax-server) for limitations on connecting to remote servers.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The fax client application must call the [IFaxServer::Disconnect](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-disconnect-client-vb) method to disconnect from the fax server.

For more information, see [Connecting to a Fax Server](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-connecting-to-a-fax-server) and [Disconnecting from a Fax Server](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-disconnecting-from-a-fax-server).

## See also

[Connecting to a Fax Server](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-connecting-to-a-fax-server)

[Disconnecting from a Fax Server](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-disconnecting-from-a-fax-server)

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxserver)

[IFaxServer::Disconnect](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-disconnect-client-vb)