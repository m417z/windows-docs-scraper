# GetDiscoveredPortAttributes function

The **GetDiscoveredPortAttributes** WMI method retrieves the attributes for a specified remote Fibre Channel port.

## Parameters

*PortIndex*
The index of the local port of type Nx\_Port through which to query the discovered remote port. This information is delivered to the miniport driver in the **PortIndex** member of a [**GetDiscoveredPortAttributes\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getdiscoveredportattributes_in) structure.

*DiscoveredPortIndex*
The index of the remote port to be queried. This information is delivered to the miniport driver in the **DiscoveredPortIndex** member of a [**GetDiscoveredPortAttributes\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getdiscoveredportattributes_in) structure.

*HBAStatus*
On return, contains a WMI qualifier value that indicates the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**GetDiscoveredPortAttributes\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getdiscoveredportattributes_out) structure.

*PortAttributes*
A structure of type [**MSFC\_HBAPortAttributesResults**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_hbaportattributesresults) in which attributes for the discovered FC\_Port may be returned. The miniport driver returns this information in the **PortAttributes** member of a [**GetDiscoveredPortAttributes\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getdiscoveredportattributes_out) structure.

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

[**GetDiscoveredPortAttributes\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getdiscoveredportattributes_in)

[**GetDiscoveredPortAttributes\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getdiscoveredportattributes_out)

[**MSFC\_HBAPortAttributesResults**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_msfc_hbaportattributesresults)

