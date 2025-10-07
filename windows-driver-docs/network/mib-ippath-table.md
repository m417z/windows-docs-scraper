# MIB\_IPPATH\_TABLE structure

The MIB\_IPPATH\_TABLE structure contains a table of IP path entries.

## Members

- **NumEntries**
A value that specifies the number of IP path entries in the array.

- **Table**
An array of [**MIB\_IPPATH\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ippath-row) structures that contain IP path entries.

## Remarks

The [**GetIpPathTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getippathtable) function enumerates the IP path entries on a local computer and returns this information in a MIB\_IPPATH\_TABLE structure. The [**FlushIpPathTable**](https://learn.microsoft.com/windows-hardware/drivers/network/flushippathtable) function flushes the IP path table entries on a local computer.

The [**GetIpPathEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getippathentry) function retrieves a single IP path entry and returns this information in a [**MIB\_IPPATH\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ippath-row) structure.

The MIB\_IPPATH\_TABLE structure might contain padding for alignment between the **NumEntries** member and the first MIB\_IPPATH\_ROW array entry in the **Table** member. Padding for alignment might also be present between the MIB\_IPPATH\_ROW array entries in the **Table** member. Any access to a MIB\_IPPATH\_ROW array entry should assume padding might exist.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**FlushIpPathTable**](https://learn.microsoft.com/windows-hardware/drivers/network/flushippathtable)

[**GetIpPathEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getippathentry)

[**GetIpPathTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getippathtable)

[**MIB\_IPPATH\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ippath-row)