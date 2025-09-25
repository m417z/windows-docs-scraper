# _GetFCPStatistics_OUT structure

## Description

The GetFCPStatistics_OUT structure is used by the miniport driver to report the output parameters of the [GetFCPStatistics](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcpstatistics) WMI method.

## Members

### `HBAStatus`

Contains a value associated with the WMI class qualifier [HBA_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status) that indicates the result of an HBA query operation.

### `FC4Statistics`

Contains a structure of type [MSFC_FC4STATISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_fc4statistics) that holds statistics for the specified FC-4 protocol.

## Remarks

The WMI tool suite generates a declaration of the GetFCPStatistics_OUT structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[GetFCPStatistics](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcpstatistics)

[GetFCPStatistics_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfcpstatistics_in)