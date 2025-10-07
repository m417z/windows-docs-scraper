# MIB\_ANYCASTIPADDRESS\_TABLE structure

The MIB\_ANYCASTIPADDRESS\_TABLE structure contains a table of anycast IP address entries.

## Members

- **NumEntries**
A value that specifies the number of anycast IP address entries in the array.

- **Table**
An array of [**MIB\_ANYCASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-anycastipaddress-row) structures that contain anycast IP address entries.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**GetAnycastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getanycastipaddresstable)

[**MIB\_ANYCASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-anycastipaddress-row)