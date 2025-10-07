# MIB\_IPINTERFACE\_TABLE structure

The MIB\_IPINTERFACE\_TABLE structure contains a table of IP interface entries.

## Members

- **NumEntries**
The number of IP interface entries in the array.

- **Table**
An array of [**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row) structures that contain IP interface entries.

## Remarks

The [**GetIpInterfaceTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getipinterfacetable) function enumerates the IP interface entries on a local computer and returns this information in a MIB\_IPINTERFACE\_TABLE structure.

The MIB\_IPINTERFACE\_TABLE structure might contain padding for alignment between the **NumEntries** member and the first [**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row) array entry in the **Table** member. Padding for alignment might also be present between the MIB\_IPINTERFACE\_ROW array entries in the **Table** member. Any access to a MIB\_IPINTERFACE\_ROW array entry should assume padding might exist.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**GetIpInterfaceTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getipinterfacetable)

[**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row)