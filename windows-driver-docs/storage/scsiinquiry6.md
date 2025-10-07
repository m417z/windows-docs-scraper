# ScsiInquiry function

The **ScsiInquiry** WMI method sends a SCSI inquiry command to the indicated device.

## Parameters

*HBAStatus*
On return, contains the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**ScsiInquiry\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_scsiinquiry_out) structure.

*Cdb*
The command descriptor block that holds the SCSI inquiry command to be sent to the target device. This information is delivered to the miniport driver in the **Cdb** member of a [**ScsiInquiry\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_scsiinquiry_in) structure.

*HbaPortWWN*
A worldwide name for the HBA through which the target is accessed. This information is delivered to the miniport driver in the **HbaPortWWN** member of a [**ScsiInquiry\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_scsiinquiry_in) structure.

*DiscoveredPortWWN*
A worldwide name for the port through which the target device is accessed. This information is delivered to the miniport driver in the **DiscoveredPortWWN** member of a [**ScsiInquiry\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_scsiinquiry_in) structure.

*FcLun*
The logical unit number of the logical unit that will receive the SCSI inquiry command. This information is delivered to the miniport driver in the **FcLun** member of a [**ScsiInquiry\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_scsiinquiry_in) structure.

*ResponseBufferSize*
The size in bytes of the buffer that will hold the results of the SCSI inquiry command. The miniport driver returns this information in the **ResponseBufferSize** member of a [**ScsiInquiry\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_scsiinquiry_out) structure.

*SenseBufferSize*
The size in bytes of the buffer that will hold the SCSI sense data that results from the SCSI inquiry command. The miniport driver returns this information in the **SenseBufferSize** member of a [**ScsiInquiry\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_scsiinquiry_out) structure.

*ScsiStatus*
The status of the SCSI inquiry command. The miniport driver returns this information in the **ScsiStatus** member of a [**ScsiInquiry\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_scsiinquiry_out) structure.

*ResponseBuffer*
The results of the SCSI inquiry command. The miniport driver returns this information in the **ResponseBuffer** member of a [**ScsiInquiry\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_scsiinquiry_out) structure.

*SenseBuffer*
The SCSI sense data that results from the SCSI inquiry command. The miniport driver returns this information in the **SenseBuffer** member of a [**ScsiInquiry\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_scsiinquiry_out) structure.

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

[HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[**ScsiInquiry\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_scsiinquiry_in)

[**ScsiInquiry\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_scsiinquiry_out)

