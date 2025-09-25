## Description

Client drivers call the **WifiAdapterAddPeer** function to tell the WiFiCx framework that a peer has connected with the given address. WiFiCx will associate a queue to the peer address.

## Parameters

### `Adapter`

[_In_] A handle to a NetAdapterCx NETADAPTER object obtained in a previous call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `Address`

The peer address.

## Remarks

The maximum number of peers that the driver may add shall not exceed the range value provided when adding Tx demultiplexing info.

For more information see [Setting up multiple Tx queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#setting-up-multiple-tx-queues).

## See also

[**WifiAdapterRemovePeer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadapterremovepeer)

[**WifiAdapterInitAddTxDemux**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadapterinitaddtxdemux)

[Setting up multiple Tx queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#setting-up-multiple-tx-queues)