# PC_REBALANCE_TYPE enumeration

## Description

The `PC_REBALANCE_TYPE` enum describes the type of support for rebalancing.

## Constants

### `PcRebalanceNotSupported`

Indicates that PcRebalance is not supported.

### `PcRebalanceRemoveSubdevices`

Indicates that PcRebalance is supported via unregistering and re-registering the audio subdevices.

## Remarks

 Rebalancing is used in certain PCI scenarios. For example when additional devices are added to the PCI chain and the use of memory resources needs to be rearranged and consolidated.

For more information, see [Implement PnP Rebalance for PortCls Audio Drivers](https://learn.microsoft.com/windows-hardware/drivers/audio/implement-pnp-rebalance-for-portcls-audio-drivers).

Available in Windows 10, version 1511 and later versions of Windows.