# _SM_SendRNID_IN structure

## Description

The SM_SendRNID_IN structure is used to provide input parameters to the SM_SendRNID method.

## Members

### `HbaPortWWN`

The worldwide name (WWN) of the local port.

### `DestWWN`

The worldwide name (WWN) of the destination port.

### `DestFCID`

The address identifier of the destination port.

### `NodeIdDataFormat`

The node identification data format.

### `InRespBufferMaxSize`

The maximum response buffer size.

## Remarks

The WMI tool suite generates a declaration of the SM_SendRNID_IN structure in *Hbapiwmi.h* when it compiles the MS_SM_FabricAndDomainManagementMethod WMI class.