# _NET_ADAPTER_DATAPATH_CALLBACKS structure

## Description

The NET_ADAPTER_DATAPATH_CALLBACKS structure describes a net adapter's callback functions for creating its datapath queues.

## Members

### `Size`

The size of this structure, in bytes.

### `EvtAdapterCreateTxQueue`

A pointer to the client driver's implementation of the [*EVT_NET_ADAPTER_CREATE_TXQUEUE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_txqueue) callback function.

### `EvtAdapterCreateRxQueue`

A pointer to the client driver's implementation of the [*EVT_NET_ADAPTER_CREATE_RXQUEUE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_rxqueue) callback function.

## Remarks

Call [**NET_ADAPTER_DATAPATH_CALLBACKS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_datapath_callbacks_init) to initialize this structure. An initialized **NET_ADAPTER_DATAPATH_CALLBACKS** structure is passed as a parameter to the [**NetAdapterInitSetDatapathCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitsetdatapathcallbacks) function.

## See also

[**NET_ADAPTER_DATAPATH_CALLBACKS_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-net_adapter_datapath_callbacks_init)

[**NetAdapterInitSetDatapathCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitsetdatapathcallbacks)