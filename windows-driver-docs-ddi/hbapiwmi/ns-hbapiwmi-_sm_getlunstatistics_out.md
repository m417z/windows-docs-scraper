# _SM_GetLUNStatistics_OUT structure

## Description

The SM_GetLUNStatistics_OUT structure is used to receive output parameters from the SM_GetLUNStatistics_OUT method.

## Members

### `HBAStatus`

The status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

### `ProtocolStatistics`

A structure of type [MS_SMHBA_PROTOCOLSTATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_ms_smhba_protocolstatistics) that is used to report protocol traffic statistics on a port.

## Remarks

The WMI tool suite generates a declaration of the SM_GetLUNStatistics_OUT structure in *Hbapiwmi.h* when it compiles the MS_SM_TargetInformationMethods WMI class.