# SM\_ScsiReadCapacity function

The SM\_ScsiReadCapacity WMI method sends a SCSI Read Capacity command to the indicated device.

## Parameters

*HbaPortWWN*
A worldwide name (WWN) for the HBA through which the target is accessed. This information is delivered to the miniport driver in the HbaPortWWN member of a [**ScsiInquiry\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_scsiinquiry_in) structure.

*DiscoveredPortWWN*
A worldwide name (WWN) for the port through which the target device is accessed. This information is delivered to the miniport driver in the DiscoveredPortWWN member of a [**ScsiInquiry\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_scsiinquiry_in) structure.

*DomainPortWWN*
The worldwide name (WWN) for the callback. It is the Port\_Identifier that has the smallest value of any Port\_Identifier of an SMP port that is discovered by using the physical port. It has a value of zero if no SMP port has been discovered by using the physical port.

*SmhbaLUN*
The logical unit number of the logical unit that will receive the SCSI inquiry command. This information is delivered to the miniport driver in the SmhbaLUN member of a [**ScsiInquiry\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_scsiinquiry_in) structure.

*Cdb*
The command descriptor block that holds the SCSI inquiry command to be sent to the target device. This information is delivered to the miniport driver in the Cdb member of a [**ScsiInquiry\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_scsiinquiry_in) structure.

*InRespBufferMaxSize*
The maximum size, in bytes, of the response buffer.

*InSenseBufferMaxSize*
The maximum size, in bytes, for the sense buffer in the response.

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a [**ScsiInquiry\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_scsiinquiry_out) structure.

*ScsiStatus*
The status of the SCSI inquiry command. The miniport driver returns this information in the ScsiStatus member of a [**ScsiInquiry\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_scsiinquiry_out) structure.

*OutRespBufferSize*
The size, in bytes, of the buffer that will hold the results of the SCSI inquiry command. The miniport driver returns this information in the ResponseBufferSize member of a [**ScsiInquiry\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_scsiinquiry_out) structure.

*OutSenseBufferSize*
The size, in bytes, of the buffer that will hold the SCSI sense data that results from the SCSI inquiry command. The miniport driver returns this information in the SenseBufferSize member of a [**ScsiInquiry\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_scsiinquiry_out) structure.

*RespBuffer*
The results of the SCSI inquiry command. The miniport driver returns this information in the ResponseBuffer member of a [**ScsiInquiry\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_scsiinquiry_out) structure.

*SenseBuffer*
The SCSI sense data that results from the SCSI inquiry command. The miniport driver returns this information in the SenseBuffer member of a [**ScsiInquiry\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_scsiinquiry_out) structure.

## Return value

Not applicable to WMI methods.

## Remarks

This WMI method belongs to the MS\_SM\_ScsiInformationMethods WMI Class.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Hbapiwmi.h |

## See also

[HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

