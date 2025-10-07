# SetFC3MgmtInfo function

The **SetFC3MgmtInfo** WMI method sets FC3 management information that is associated with a Fibre Channel adapter.

## Parameters

*HBAStatus*
On return, contains the status of the operation. For a list of allowed values and their descriptions, see [HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status). The miniport driver returns this information in the **HBAStatus** member of a [**SetFC3MgmtInfo\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_setfc3mgmtinfo_out) structure.

*MgmtInfo*
A structure of type [**HBAFC3MgmtInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafc3mgmtinfo) that holds FC3 management information that will be used to configure the fibre channel adapter. This information is delivered to the miniport driver in the **PortWWN** member of a [**SetFC3MgmtInfo\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_setfc3mgmtinfo_in) structure.

## Return value

Not applicable to WMI methods.

## Remarks

This WMI method belongs to the [MSFC\_HBAAdapterMethods WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msfc-hbaadaptermethods-wmi-class).

## Requirements

|  |  |
| --- | --- |
| Target platform | Desktop |
| Header | Hbapiwmi.h (include Hbapiwmi.h, Hbaapi.h, or Hbaapi.h) |

## See also

[HBA\_STATUS](https://learn.microsoft.com/windows-hardware/drivers/storage/hba-status)

[**GetFC3MgmtInfo\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfc3mgmtinfo_out)

[**HBAFC3MgmtInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_hbafc3mgmtinfo)

[**SetFC3MgmtInfo\_IN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_setfc3mgmtinfo_in)

[**SetFC3MgmtInfo\_OUT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_setfc3mgmtinfo_out)

