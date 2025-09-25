# IWdsTransportTftpManager::RetrieveTftpClients

## Description

Returns a pointer to the object of an [IWdsTransportCollection](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcollection) interface containing a collection of objects of the [IWdsTransportTftpClient](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransporttftpclient) interface for the clients currently connected to the TFTP server.

## Parameters

### `ppWdsTransportTftpClients` [out, retval]

A pointer to a pointer to an object of the [IWdsTransportCollection](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcollection) interface.

## See also

[IWdsTransportCollection](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransportcollection)

[IWdsTransportTftpManager](https://learn.microsoft.com/windows/desktop/api/wdstptmgmt/nn-wdstptmgmt-iwdstransporttftpmanager)