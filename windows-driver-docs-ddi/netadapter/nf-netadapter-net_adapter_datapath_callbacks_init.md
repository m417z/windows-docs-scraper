# NET_ADAPTER_DATAPATH_CALLBACKS_INIT function

## Description

The **NET_ADAPTER_DATAPATH_CALLBACKS_INIT** function initializes a [**NET_ADAPTER_DATAPATH_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_datapath_callbacks) structure.

## Parameters

### `DatapathCallbacks` [_Out_]

A pointer to a driver-allocated [**NET_ADAPTER_DATAPATH_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_datapath_callbacks) structure.

### `EvtAdapterCreateTxQueue` [_In_]

A pointer to the client driver's implementation of the [*EVT_NET_ADAPTER_CREATE_TXQUEUE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_txqueue) callback function.

### `EvtAdapterCreateRxQueue` [_In_]

A pointer to the client driver's implementation of the [*EVT_NET_ADAPTER_CREATE_RXQUEUE*](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nc-netadapter-evt_net_adapter_create_rxqueue) callback function.

## Remarks

Call this function to initialize the [**NET_ADAPTER_DATAPATH_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_datapath_callbacks) structure before calling [**NetAdapterInitSetDatapathCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitsetdatapathcallbacks).

## See also

[**NET_ADAPTER_DATAPATH_CALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/ns-netadapter-_net_adapter_datapath_callbacks)

[**NetAdapterInitSetDatapathCallbacks**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterinitsetdatapathcallbacks)