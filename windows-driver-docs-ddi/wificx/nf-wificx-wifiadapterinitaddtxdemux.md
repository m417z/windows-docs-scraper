## Description

The **WifiAdapterInitAddTxDemux** function adds DEMUX properties for multiple Tx queue support.

## Parameters

### `Adapter`

[_In_] A pointer to a NETADAPTER_INIT object that describes the initialization information for the NETADAPTER.

### `Demux`

[_In_] A pointer to an initialized [**WIFI_ADAPTER_TX_DEMUX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_tx_demux) structure.

## Remarks

Before using a NETADAPTER_INIT object to create a NETADAPTER, client drivers add Tx DEMUX properties to the adapter.

For code examples see [Setting up multiple Tx queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#setting-up-multiple-tx-queues).

## See also

[Setting up multiple Tx queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#setting-up-multiple-tx-queues)

[**WIFI_ADAPTER_TX_DEMUX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_tx_demux)