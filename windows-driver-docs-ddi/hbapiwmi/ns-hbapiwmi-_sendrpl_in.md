# _SendRPL_IN structure

## Description

The SendRPL_IN structure is used to deliver input parameter data to the [SendRPL](https://learn.microsoft.com/windows-hardware/drivers/storage/sendrpl) WMI method.

## Members

### `PortWWN`

Contains a worldwide name for the local port through which the read port list (RPL) command is sent.

### `AgentWWN`

Contains a worldwide name for the port that is to be queried for a list of ports of type FC_Port. For a definition of FC_Port, see the T11 committee's specification for *Fibre Channel HBA API*.

### `agent_domain`

Contains the domain number for the domain controller that is to be queried for a list of ports of type FC_Port. For a definition of FC_Port, see the T11 committee's specification for *Fibre Channel HBA API*.

### `portIndex`

Contains the port index of the first port in the list of ports of type FC_Port to be returned.

## Remarks

The WMI tool suite generates a declaration of the SendRPL_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[SendRPL](https://learn.microsoft.com/windows-hardware/drivers/storage/sendrpl)