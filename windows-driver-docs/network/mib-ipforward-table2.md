# MIB\_IPFORWARD\_TABLE2 structure

The MIB\_IPFORWARD\_TABLE2 structure contains a table of IP route entries.

## Members

- **NumEntries**
A value that specifies the number of IP route entries in the array.

- **Table**
An array of [**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structures that contain IP route entries.

## Remarks

The [**GetIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipforwardentry2) function enumerates the IP route entries on a local computer and returns this information in a MIB\_IPFORWARD\_TABLE2 structure.

The **GetIpForwardEntry2** function retrieves a single IP route entry and returns this information in a [**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure.

The MIB\_IPFORWARD\_TABLE2 structure might contain padding for alignment between the **NumEntries** member and the first MIB\_IPFORWARD\_ROW2 array entry in the **Table** member. Padding for alignment might also be present between the MIB\_IPFORWARD\_ROW2 array entries in the **Table** member. Any access to a MIB\_IPFORWARD\_ROW2 array entry should assume padding might exist.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**GetIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipforwardentry2)

[**GetIpForwardTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipforwardtable2)

[**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2)