## Description

The **WIFI_ADAPTER_TX_PEER_ADDRESS_DEMUX_INIT** function initializes a [**WIFI_ADAPTER_TX_DEMUX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_tx_demux) structure when the Tx DEMUX type is PEER_ADDRESS.

## Parameters

### `Demux`

[_Out_] A pointer to the [**WIFI_ADAPTER_TX_DEMUX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_tx_demux) structure.

### `Range`

[_In_] The maximum number of peers.

## Remarks

For more information, see [Setting up multiple Tx queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#setting-up-multiple-tx-queues).

## See also

[**WIFI_ADAPTER_TX_DEMUX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ns-wificx-wifi_adapter_tx_demux)

[Setting up multiple Tx queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#setting-up-multiple-tx-queues)