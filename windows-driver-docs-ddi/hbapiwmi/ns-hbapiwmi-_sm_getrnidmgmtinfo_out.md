# _SM_GetRNIDMgmtInfo_OUT structure

## Description

The SM_GetRNIDMgmtInfo_OUT structure is used to receive output parameters from the SM_GetRNIDMgmtInfo method.

## Members

### `HBAStatus`

The status of the operation. For a list of allowed values and their descriptions, see [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status).

### `MgmtInfo`

A structure of type HBAFC3MgmtInfo that holds FC3 management information. The FC3 management information is used to configure the fibre channel adapter.

## Remarks

The WMI tool suite generates a declaration of the SM_GetRNIDMgmtInfo_OUTstructure in *Hbapiwmi.h* when it compiles the MS_SM_FabricAndDomainManagementMethod WMI class.