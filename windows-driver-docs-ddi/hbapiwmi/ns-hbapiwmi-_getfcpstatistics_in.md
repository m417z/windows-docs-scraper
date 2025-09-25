# _GetFCPStatistics_IN structure

## Description

The GetFCPStatistics_IN structure is used to deliver input parameter data to the [GetFCPStatistics](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcpstatistics) WMI method.

## Members

### `ScsiId`

Contains a structure of type [HBAScsiID](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbascsiid) that uniquely identifies a logical unit and the bus and HBA that the logical unit is connected to.

## Remarks

The WMI tool suite generates a declaration of the GetFCPStatistics_IN structure in *Hbapiwmi.h* when it compiles the [MSFC_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## See also

[GetFCPStatistics](https://learn.microsoft.com/windows-hardware/drivers/storage/getfcpstatistics)

[HBAScsiID](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbascsiid)