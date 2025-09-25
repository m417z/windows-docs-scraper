# _GetFC4Statistics_OUT structure

## Description

The GetFC4Statistics_OUT structure is used to report the output parameter data of the [GetFC4Statistics](https://learn.microsoft.com/windows-hardware/drivers/storage/getfc4statistics) WMI method to the WMI client.

## Members

### `HBAStatus`

Contains a value associated with the WMI class qualifier [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status) that indicates the result of an HBA query operation.

### `FC4Statistics`

Contains a structure of type [MSFC_FC4STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_fc4statistics) that holds statistics for the specified FC-4 protocol.

## Remarks

The [GetFC4Statistics](https://learn.microsoft.com/windows-hardware/drivers/storage/getfc4statistics) WMI method reports traffic statistics for a specific FC-4 protocol via a specific local HBA and port of type Nx_Port.

The WMI tool suite generates a declaration of the GetFC4Statistics_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[GetFC4Statistics](https://learn.microsoft.com/windows-hardware/drivers/storage/getfc4statistics)