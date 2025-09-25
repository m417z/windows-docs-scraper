# _SM_SendCTPassThru_IN structure

## Description

The SM_SendCTPassThru_IN structure is used to provide input parameters to the SM_SendCTPassThru method.

## Members

### `HbaPortWWN`

The HBA port worldwide name (WWN) to which pass-through commands will be sent.

### `InRespBufferMaxSize`

The maximum response buffer size.

### `ReqBufferSize`

The size, in bytes, of the buffer that will hold the results of the common transport command.

### `ReqBuffer`

## Remarks

The WMI tool suite generates a declaration of the SM_SendCTPassThru_IN structure in *Hbapiwmi.h* when it compiles the MS_SM_FabricAndDomainManagementMethod WMI class.