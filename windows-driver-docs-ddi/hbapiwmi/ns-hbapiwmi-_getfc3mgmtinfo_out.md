# _GetFC3MgmtInfo_OUT structure

## Description

The GetFC3MgmtInfo_OUT structure is used to report the output parameter data of the [GetFC3MgmtInfo](https://learn.microsoft.com/windows-hardware/drivers/storage/getfc3mgmtinfo) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains a value associated with the WMI class qualifier [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status) that indicates the result of an HBA query operation.

### `MgmtInfo`

Contains a structure of type [HBAFC3MgmtInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafc3mgmtinfo) that reports FC3 management information.

## Remarks

The [GetFC3MgmtInfo](https://learn.microsoft.com/windows-hardware/drivers/storage/getfc3mgmtinfo) method reports fibre channel-3 management information.

The WMI tool suite generates a declaration of the GetEventBuffer_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[GetFC3MgmtInfo](https://learn.microsoft.com/windows-hardware/drivers/storage/getfc3mgmtinfo)

[HBAFC3MgmtInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafc3mgmtinfo)

[HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)