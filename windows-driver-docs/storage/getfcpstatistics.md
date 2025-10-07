# GetFCPStatistics function

The **GetFCPStatistics** WMI method returns FCP traffic statistics for the indicated SCSI logical unit on the indicated local HBA.

## Parameters

*HBAStatus*
On return, contains a WMI qualifier value that indicates the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**GetFCPStatistics\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfcpstatistics_out) structure.

*ScsiId*
On return, contains a structure of type [**HBAScsiID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbascsiid) that holds information that identifies the device. This information is delivered to the miniport driver in the **ScsiId** member of a [**GetFCPStatistics\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfcpstatistics_in) structure.

*FC4Statistics*
On return, contains a structure of type [**MSFC\_FC4STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_fc4statistics) that holds statistics for the indicated SCSI logical unit. The miniport driver returns this information in the **FC4Statistics** member of a [**GetFCPStatistics\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfcpstatistics_out) structure.

## Return value

Not applicable to WMI methods.

## Remarks

This WMI method belongs to the [MSFC\_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Hbapiwmi.h (include Hbapiwmi.h, Hbaapi.h, or Hbaapi.h) |
| Library | Hbaapi.lib |

## See also

[**GetFCPStatistics\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfcpstatistics_in)

[**GetFCPStatistics\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfcpstatistics_out)

[**MSFC\_FC4STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_fc4statistics)

