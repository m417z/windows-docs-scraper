# MIB\_UNICASTIPADDRESS\_TABLE structure

The MIB\_UNICASTIPADDRESS\_TABLE structure contains a table of unicast IP address entries.

## Members

- **NumEntries**
A value that specifies the number of unicast IP address entries in the array.

- **Table**
An array of [**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) structures that contains unicast IP address entries.

## Remarks

The [**GetUnicastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getunicastipaddresstable) function enumerates the unicast IP addresses on a local computer and returns this information in an MIB\_UNICASTIPADDRESS\_TABLE structure.

The MIB\_UNICASTIPADDRESS\_TABLE structure might contain padding for alignment between the **NumEntries** member and the first [**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) array entry in the **Table** member. Padding for alignment might also be present between the MIB\_UNICASTIPADDRESS\_ROW array entries in the **Table** member. Any access to a MIB\_UNICASTIPADDRESS\_ROW array entry should assume padding might exist.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**GetUnicastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getunicastipaddresstable)

[**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row)