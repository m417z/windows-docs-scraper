## Description

Client drivers call the **WifiAdapterRemovePeer** function to tell the WiFiCx framework that a peer has been disconnected. This causes the framework to stop the associated queue.

## Parameters

### `Adapter`

[_In_] A handle to a NetAdapterCx NETADAPTER object obtained in a previous call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `Address`

The peer address.

## Remarks

For more information see [Setting up multiple Tx queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#setting-up-multiple-tx-queues).

## See also

[**WifiAdapterAddPeer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadapteraddpeer)

[Setting up multiple Tx queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#setting-up-multiple-tx-queues)