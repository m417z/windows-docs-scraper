# MIB\_IF\_TABLE2 structure

The MIB\_IF\_TABLE2 structure contains a table of logical and physical interface entries.

## Members

- **NumEntries**
The number of interface entries in the array.

- **Table**
An array of [**MIB\_IF\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-row2) structures that contain interface entries.

## Remarks

The [**GetIfTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2) and [**GetIfTable2Ex**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2ex) functions enumerate the logical and physical interfaces on a local computer and return this information in a MIB\_IF\_TABLE2 structure.

The MIB\_IF\_TABLE2 structure might contain padding for alignment between the **NumEntries** member and the first MIB\_IF\_ROW2 array entry in the **Table** member. Padding for alignment might also be present between the MIB\_IF\_ROW2 array entries in the **Table** member. Any access to a MIB\_IF\_ROW2 array entry should assume padding might exist.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**GetIfTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2)

[**GetIfTable2Ex**](https://learn.microsoft.com/windows-hardware/drivers/network/getiftable2ex)

[**MIB\_IF\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-if-row2)