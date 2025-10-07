# SM\_GetLUNStatistics function

The SMHBA\_GetLUNStatistics method returns traffic statistics for a specific SCSI logical unit that is provided by using the FCP protocol or SSP protocol on a specific local HBA.

## Parameters

*Lunit*
A structure of type [**HBA\_ScsiId**](https://learn.microsoft.com/previous-versions/ff557191(v=vs.85)) that contains information that is used by the operating system to identify a SCSI logical unit.

*HBAStatus*
The status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the HBAStatus member of a SM\_GetLUNStatistics\_OUT structure.

*ProtocolStatistics*
A structure of type [**MS\_SMHBA\_PROTOCOLSTATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_ms_smhba_protocolstatistics) that is used to report protocol traffic statistics on a port.

## Return value

Not applicable to WMI methods.

## Remarks

This WMI method belongs to the MS\_SM\_TargetInformationMethods WMI Class.

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Hbapiwmi.h |

## See also

[HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[**SM\_GetLUNStatistics\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_getlunstatistics_in)

[**SM\_GetLUNStatistics\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_sm_getlunstatistics_out)

