# IAdapterPnpManagement::GetSupportedRebalanceType

## Description

The GetSupportedRebalanceType method returns the type of rebalancing supported. Rebalancing is used in certain Thunderbolt USB scenario, where, when additional devices are added to the USB chain, the use of memory resources needs to be rearranged and consolidated.

## Return value

The GetSupportedRebalanceType method returns the type of rebalancing supported (RebalanceNotSupported or RebalanceRemoveSubdevices) as defined in the enum PC_REBALANCE_TYPE.

## Remarks

GetSupportedRebalanceType is called by Portcls while processing the QueryStop. Miniport returns the supported rebalance type.

Note Portcls acquires the device global lock before making this call, thus the miniport must execute this call as fast as possible.
For more information, see [Implement PnP Rebalance for PortCls Audio Drivers](https://learn.microsoft.com/windows-hardware/drivers/audio/implement-pnp-rebalance-for-portcls-audio-drivers).

## See also

[IAdapterPnpManagement](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iadapterpnpmanagement)