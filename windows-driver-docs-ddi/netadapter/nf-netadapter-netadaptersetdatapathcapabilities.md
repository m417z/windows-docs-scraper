# NetAdapterSetDataPathCapabilities function

## Description

Sets the data path capabilities of the network adapter.

## Parameters

### `Adapter` [_In_]

The network adapter object that the client created in a prior call to [NetAdapterCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `TxCapabilities` [_In_]

A pointer to an allocated and initialized [NET_ADAPTER_TX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_tx_capabilities) structure.

### `RxCapabilities` [_In_]

A pointer to an allocated and initialized [NET_ADAPTER_RX_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_rx_capabilities) structure.

## Remarks

The client driver must call this function when starting a net adapter, before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

This function, along with a few other set capability functions (see below), is the replacement for the [NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/miniportgeneralattributes/ns-miniportgeneralattributes-ndis_miniport_adapter_general_attributes) union that a (non-WDF) client of Ndis.sys sets by calling [NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes).

## See also

[NetAdapterSetLinkLayerCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetlinklayercapabilities)