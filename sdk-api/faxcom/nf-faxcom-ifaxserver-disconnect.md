# IFaxServer::Disconnect

## Description

The **IFaxServer::Disconnect** method terminates a fax client application's connection to a fax server.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A call to the **IFaxServer::Disconnect** method attempts to terminate a server connection made by a previous call to the [IFaxServer::Connect](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-connect-client-vb) method.

In addition to calling the **IFaxServer::Disconnect** method, an application must also call the [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method to allow each object to deallocate itself.

For more information, see [Connecting to a Fax Server](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-connecting-to-a-fax-server) and [Disconnecting from a Fax Server](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-disconnecting-from-a-fax-server).

## See also

[Connecting to a Fax Server](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-connecting-to-a-fax-server)

[Disconnecting from a Fax Server](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-disconnecting-from-a-fax-server)

[Fax Service Client API Interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-interfaces)

[Fax Service Client API for Windows 2000](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-service-client-api-for-windows-2000)

[FaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxserver-client)

[IFaxServer](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxcom/nn-faxcom-ifaxserver)

[IFaxServer::Connect](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-ifaxserver-connect-client-vb)

[IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release)