# INetworkConnection::GetAdapterId

## Description

The **GetAdapterID** method returns the ID of the network adapter used by this connection.

## Parameters

### `pgdAdapterId` [out]

Pointer to a GUID that specifies the adapter ID of the TCP/IP interface used by this network connection.

## Return value

Returns S_OK if the method succeeds.

## Remarks

It is possible for multiple connections to have the same AdapterID.

## See also

[INetworkConnection](https://learn.microsoft.com/windows/desktop/api/netlistmgr/nn-netlistmgr-inetworkconnection)