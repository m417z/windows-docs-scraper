# NetAdapterSetLinkLayerMtuSize function

## Description

Sets the link layer maximum transfer unit size of the adapter.

## Parameters

### `Adapter` [_In_]

The network adapter object that the client created in a prior call to [**NetAdapterCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptercreate).

### `MtuSize` [_In_]

The new size of the adapter's MTU, in bytes.

## Remarks

The client driver first sets MTU size by calling **NetAdapterSetLinkLayerMtuSize** when starting a net adapter, before calling [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart).

The client driver can change the MTU size after [**NetAdapterStart**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadapterstart) returns by calling this function again. Doing so causes all of the adapter's transmit (Tx) and receive (Rx) queues to be recreated.

## See also

[NetAdapterSetLinkLayerCapabilities](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadapter/nf-netadapter-netadaptersetlinklayercapabilities)