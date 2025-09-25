# IAdapterPnpManagement::PnpStop

## Description

The PnpStop method provides a notification after stopping all Ioctl operations and moving active streams from run|pause|acquire state to stop state.

## Remarks

PnpStop is invoked by Portcls after stopping all Ioctl operations and moving active streams from run|pause|acquire state to stop state. This call is not made while holding the device global lock. Thus the miniport driver has an opportunity to wait for its async operations (work-items, dpc, async threads) and unregister its audio subdevices. Before returning from this call the miniport must ensure that all the hardware resources have been released.

The miniport must not wait for the current miniport/stream objects to be deleted since it is unclear when existing audio clients will release the current handles. The PnpStop thread cannot block forever without crashing the system, i.e., this is a PnP/Power thread.

IAdapterPnpManagement::Pnpstop is called after:

- All miniport audio subdevices have been notified.
- All the streams belonging to the audio subdevices have been stopped.
- All the Pnp interfaces have been turned off.
- All pending I/O has been cancelled.

For more information, see [Implement PnP Rebalance for PortCls Audio Drivers](https://learn.microsoft.com/windows-hardware/drivers/audio/implement-pnp-rebalance-for-portcls-audio-drivers).

## See also

[IAdapterPnpManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpnpmanagement)