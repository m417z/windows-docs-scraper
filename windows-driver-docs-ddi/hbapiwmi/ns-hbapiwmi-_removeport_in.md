# _RemovePort_IN structure

## Description

The Remove_IN structure is used by a WMI client to deliver input parameter data to the [RemovePort](https://learn.microsoft.com/windows-hardware/drivers/storage/removeport) WMI method.

## Members

### `PortWWN`

Contains a worldwide name that indicates the port that should be removed from the list of ports whose events are reported to the WMI client..

## Remarks

The WMI tool suite generates a declaration of the RemovePort_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_EventControl WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-eventcontrol-wmi-class).

## See also

[RemovePort](https://learn.microsoft.com/windows-hardware/drivers/storage/removeport)