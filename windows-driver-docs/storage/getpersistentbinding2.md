# GetPersistentBinding2 function

The **GetPersistentBinding2** method retrieves the bindings that an HBA miniport driver uses to map the information that an operating system uses to identify its logical units to the Fibre Channel protocol (FCP) identifiers for the logical units.

## Parameters

*PortWWN\[8\]*
A worldwide name that indicates the port whose persistent bindings will be retrieved.

*InEntryCount*
Indicates the number of binding entries that the WMI provider can report in the *Entry* parameter.

*HBAStatus*
On return, contains the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**GetFcpPersistentBinding\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfcppersistentbinding_out) structure.

*TotalEntryCount*
Indicates the total number of persistent bindings associated with the HBA.

*OutEntryCount*
Indicates the total number of persistent bindings retrieved by the **GetPersistentBinding2** method.. This value will be less than or equal to *TotalEntryCount*.

*Bindings\[\]*
An array of structures of type [**HBAFCPBindingEntry2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpbindingentry2) that describe an HBA's bindings between operating system and Fibre Channel protocol (FCP) identifiers.

## Return value

Not applicable to WMI methods.

## Remarks

This WMI method belongs to the [MSFC\_HBAFCPInfo WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbafcpinfo-wmi-class).

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Hbapiwmi.h (include Hbapiwmi.h, Hbaapi.h, or Hbaapi.h) |

## See also

[**GetFcpPersistentBinding\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfcppersistentbinding_in)

[**GetFcpPersistentBinding\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfcppersistentbinding_out)

[**HBAFCPBindingEntry2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafcpbindingentry2)

