## Description

The **WIFI_ADAPTER_TX_DEMUX** structure specifies Tx DEMUX information.

## Members

### `Size`

The size of this structure in bytes.

### `Type`

The demux type formatted as a [**WIFI_ADAPTER_TX_DEMUX_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ne-wificx-wifi_adapter_tx_demux_type) enumeration.

### `Range`

The maximum number of queues for QOS or peers.

## Remarks

If the demux type is WMMINFO call [**WIFI_ADAPTER_TX_WMMINFO_DEMUX_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_adapter_tx_wmminfo_demux_init) to initialize this structure.

If the demux type is PEER_ADDRESS call [**WIFI_ADAPTER_TX_PEER_ADDRESS_DEMUX_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_adapter_tx_wmminfo_demux_init) to initialize this structure.

Call [**WifiAdapterInitAddTxDemux**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadapterinitaddtxdemux) to add the Tx demux information to the NETADAPTER.

For more information, see [Setting up multiple Tx queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#setting-up-multiple-tx-queues).

## See also

[**WIFI_ADAPTER_TX_DEMUX_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/ne-wificx-wifi_adapter_tx_demux_type)

[**WIFI_ADAPTER_TX_WMMINFO_DEMUX_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_adapter_tx_wmminfo_demux_init)

[**WIFI_ADAPTER_TX_PEER_ADDRESS_DEMUX_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifi_adapter_tx_peer_address_demux_init)

[**WifiAdapterInitAddTxDemux**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wificx/nf-wificx-wifiadapterinitaddtxdemux)

[Setting up multiple Tx queues](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-a-wificx-client-driver#setting-up-multiple-tx-queues)