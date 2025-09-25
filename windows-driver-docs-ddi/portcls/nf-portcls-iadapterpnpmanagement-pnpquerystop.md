# IAdapterPnpManagement::PnpQueryStop

## Description

PnpQueryStop provides a notification when PnpQueryStop is invoked by portcls just before succeeding the QueryStop IRP.

## Remarks

PnpQueryStop is invoked by portcls just before succeeding the QueryStop IRP. This is just a notification and the call doesn’t return a value.

Note Portcls acquires the device global lock before making this call, thus the miniport must execute this call as fast as possible. While a Stop is pending, Portcls will block (hold) any new create requests.

For more information, see [Implement PnP Rebalance for PortCls Audio Drivers](https://learn.microsoft.com/windows-hardware/drivers/audio/implement-pnp-rebalance-for-portcls-audio-drivers).

## See also

[IAdapterPnpManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpnpmanagement)