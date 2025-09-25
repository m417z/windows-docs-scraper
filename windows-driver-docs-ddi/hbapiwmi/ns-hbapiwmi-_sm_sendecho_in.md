# _SM_SendECHO_IN structure

## Description

The SM_SendECHO_IN structure is used to provide input parameters to the SM_SendECHO method.

## Members

### `HbaPortWWN`

The local HBA port worldwide name (WWN).

### `DestWWN`

The remote HBA port worldwide name (WWN) to which the command will be sent.

### `DestFCID`

The address identifier of the remote port.

### `InRespBufferMaxSize`

The maximum response buffer size.

### `ReqBufferSize`

The request buffer size.

### `ReqBuffer`

The request buffer data.

## Remarks

The WMI tool suite generates a declaration of the SM_SendECHO_IN structure in *Hbapiwmi.h* when it compiles the MS_SM_FabricAndDomainManagementMethod WMI class.