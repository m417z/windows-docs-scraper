# _SendRPS_IN structure

## Description

The SendRPS_IN structure is used to deliver input parameter data to the [SendRPS](https://learn.microsoft.com/windows-hardware/drivers/storage/sendrps) WMI method.

## Members

### `PortWWN`

Contains a worldwide name for the local port through which the RPS command is sent.

### `AgentWWN`

Contains a worldwide name for the port that is to be queried for the status of the port indicated by **ObjectWWN**.

### `ObjectWWN`

Contains the worldwide name of the port for which port status is to be returned.

### `AgentDomain`

Contains the domain number of the domain controller to be queried for the status of the port indicated by **ObjectWWN**.

### `ObjectPortNumber`

Contains the worldwide name of the port for which port status is to be returned.

## Remarks

The WMI tool suite generates a declaration of the SendRPS_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[SendRPS](https://learn.microsoft.com/windows-hardware/drivers/storage/sendrps)