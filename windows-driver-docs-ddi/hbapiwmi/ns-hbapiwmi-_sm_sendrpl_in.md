# _SM_SendRPL_IN structure

## Description

The SM_SendRPL_IN structure is used to provide input parameters to the SM_SendRPL method.

## Members

### `HbaPortWWN`

A worldwide name (WWN) for the local port through which the read port list (RPL) command is sent.

### `AgentWWN`

A worldwide name (WWN) for the port that is to be queried for a list of ports of type FC_Port. For a definition of FC_Port, see the T11 committee's *Fibre Channel HBA API* specification*.*

### `AgentDomain`

The domain number for the domain controller that is to be queried for a list of ports of type FC_Port. For a definition of FC_Port, see the T11 committee's *Fibre Channel HBA API* specification.

### `PortIndex`

The port index of the first port in the list of ports of type FC_Port to be returned.

### `InRespBufferMaxSize`

The response buffer size.

## Remarks

The WMI tool suite generates a declaration of the SM_SendRPL_IN structure in *Hbapiwmi.h* when it compiles the MS_SM_FabricAndDomainManagementMethod WMI class.