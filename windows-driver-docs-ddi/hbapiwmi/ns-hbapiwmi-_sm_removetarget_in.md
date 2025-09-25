# _SM_RemoveTarget_IN structure

## Description

The SM_RemoveTarget_IN structure is used to provide input parameters to the SM_RemoveTarget WMI method.

## Members

### `HbaPortWWN`

A worldwide name (WWN) that indicates the local port that should be removed from the list of ports whose events are reported to the WMI client.

### `DiscoveredPortWWN`

A worldwide name (WWN) that indicates the port that was discovered remotely. Remove this port from the list of ports whose events are reported to the WMI client.

### `DomainPortWWN`

A worldwide name (WWN) that specifies the SAS domain worldwide name of the local port.

### `AllTargets`

The scope of the target events that stop reporting. If this member is zero, the WMI provider client stops reporting events that are associated with the port that is indicated by DiscoveredPortWWN. If this member is nonzero, the WMI provider stops reporting events that are associated with any target.

## Remarks

The WMI tool suite generates a declaration of the SM_RemoveTarget_IN structure in *Hbapiwmi.h* when it compiles the MS_SM_EventControl WMI class.