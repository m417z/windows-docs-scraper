# IMiniportPnpNotify::PnpStop

## Description

An optional interface to allow miniport drivers to receive PnP state change notifications.

## Remarks

Available in Windows 10, version 1511 and later versions of Windows.

Miniports have an opportunity to receive a PnP Stop notification for each audio subdevice they have registered. To receive this notification, the subdevice must support IMiniportPnpNotify. Only the IMiniportPnpNotify::PnpStop notification is defined on this interface.

IMiniportPnpNotify interface available is on both WaveRT and Topology.

Note: Because Portcls acquires the device global lock before making this call, thus the miniport must execute this call as fast as possible. The miniport must not wait on other activity while processing this call to prevent deadlock when other threads/work-items are waiting for the device global lock. If needed, miniport can wait in the IAdapterPnpManagement::PnpStop call.
For more information, see [Implement PnP Rebalance for PortCls Audio Drivers](https://learn.microsoft.com/windows-hardware/drivers/audio/implement-pnp-rebalance-for-portcls-audio-drivers).

## See also

[IMiniPortPnpNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportpnpnotify)