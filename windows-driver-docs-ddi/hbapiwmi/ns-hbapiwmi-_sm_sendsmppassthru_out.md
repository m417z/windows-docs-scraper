# _SM_SendSMPPassThru_OUT structure

## Description

The SM_SendSMPPassThru_OUT structure is used to receive output parameters from the SM_SendSMPPassThru method.

## Members

### `HBAStatus`

The status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

### `TotalRespBufferSize`

The size, in bytes, of the results common transport (CT) command.

### `OutRespBufferSize`

The size, in bytes, of the data that was actually retrieved.

### `RespBuffer`

The results of the common transport command.

## Remarks

The WMI tool suite generates a declaration of the SM_SendSMPPassThru_OUT structure in *Hbapiwmi.h* when it compiles the MS_SM_FabricAndDomainManagementMethod WMI class.