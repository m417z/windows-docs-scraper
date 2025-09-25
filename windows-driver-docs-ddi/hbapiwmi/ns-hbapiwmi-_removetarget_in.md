# _RemoveTarget_IN structure

## Description

The RemoveTarget_IN structure is used by a WMI client to deliver input parameter data to the [RemoveTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/removetarget) WMI method.

## Members

### `HbaPortWWN`

Contains a worldwide name that indicates the local port that should be removed from the list of ports whose events are reported to the WMI client..

### `DiscoveredPortWWN`

Contains a worldwide name that indicates the remote discovered port that should be removed from the list of ports whose events are reported to the WMI client..

### `AllTargets`

Indicates the scope of the target events to cease reporting. If this member is zero, the WMI provider client will cease reporting events associated with the port that is indicated by **DiscoveredPortWWN**. If this member is nonzero, the WMI provider will cease reporting all events associated any target.

## Remarks

The WMI tool suite generates a declaration of the RemoveTarget_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_EventControl WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-eventcontrol-wmi-class).

## See also

[RemoveTarget](https://learn.microsoft.com/windows-hardware/drivers/storage/removetarget)