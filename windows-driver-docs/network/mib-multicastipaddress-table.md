# MIB\_MULTICASTIPADDRESS\_TABLE structure

The MIB\_MULTICASTIPADDRESS\_TABLE structure contains a table of multicast IP address entries.

## Members

- **NumEntries**
A value that specifies the number of multicast IP address entries in the array.

- **Table**
An array of [**MIB\_MULTICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-multicastipaddress-row) structures that contain multicast IP address entries.

## Remarks

The [**GetMulticastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getmulticastipaddresstable) function enumerates the multicast IP addresses on a local computer and returns this information in an MIB\_MULTICASTIPADDRESS\_TABLE structure.

The MIB\_MULTICASTIPADDRESS\_TABLE structure might contain padding for alignment between the **NumEntries** member and the first [**MIB\_MULTICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-multicastipaddress-row) array entry in the **Table** member. Padding for alignment might also be present between the MIB\_MULTICASTIPADDRESS\_ROW array entries in the **Table** member. Any access to a MIB\_MULTICASTIPADDRESS\_ROW array entry should assume padding might exist.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**GetMulticastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getmulticastipaddresstable)

[**MIB\_MULTICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-multicastipaddress-row)