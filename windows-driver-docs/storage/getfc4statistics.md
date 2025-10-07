# GetFC4Statistics function

The **GetFC4Statistics** WMI method reports traffic statistics on a port of type Nx\_Port for the indicated FC-4 protocol.

## Parameters

*HBAStatus*
On return, contains a WMI qualifier value that indicates the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**GetFC4Statistics\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfc4statistics_out) structure.

*PortWWN*
The worldwide name for the local port of type Nx\_Port whose traffic statistics are to be reported. This information is delivered to the miniport driver in the **PortWWN** member of a [**GetFC4Statistics\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfc4statistics_in) structure.

*FC4Type*
A value that indicates the type FC-4 protocol. For an explanation of FC4 types, see the T11 committee's *Fibre Channel Generic Services - 4* specification. This information is delivered to the miniport driver in the **FC4Type** member of a [**GetFC4Statistics\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfc4statistics_in) structure.

*FC4Statistics*
On return, contains a structure of type [**MSFC\_FC4STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_fc4statistics) that holds statistics for the specified FC-4 protocol. The miniport driver returns this information in the **FC4Statistics** member of a [**GetFC4Statistics\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfc4statistics_out) structure.

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

[**GetFC4Statistics\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfc4statistics_in)

[**GetFC4Statistics\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfc4statistics_out)

[HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[**MSFC\_FC4STATISTICS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_fc4statistics)

