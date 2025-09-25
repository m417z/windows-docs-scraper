# IAdapterPnpManagement::PnpCancelStop

## Description

The PnpCancelStop method provides a notification while processing the CancelStop IRP.

## Remarks

PnpCancelStop is invoked by portcls while processing the CancelStop IRP. This is just a notification. It is possible for the Miniport to receive PnpCancelStop even without previously receiving a PnpQueryStop notification. The miniport should be written to accommodate this behavior. For example this is the case when the QueryStop logic fails the IRP before Portcls has an opportunity to forward this notification to the Miniport. In this scenario PnP manager still invokes a PnP Cancel Stop.

Note: Portcls acquires the device global lock before making this call, thus the miniport must execute this call as fast as possible. Portcls restarts any pended create requests.
For more information, see [Implement PnP Rebalance for PortCls Audio Drivers](https://learn.microsoft.com/windows-hardware/drivers/audio/implement-pnp-rebalance-for-portcls-audio-drivers).

## See also

[IAdapterPnpManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpnpmanagement)