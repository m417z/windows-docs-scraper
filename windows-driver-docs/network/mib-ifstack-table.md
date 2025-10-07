# MIB\_IFSTACK\_TABLE structure

The MIB\_IFSTACK\_TABLE structure contains a table of network interface stack row entries. This table specifies the relationship of the network interfaces on an interface stack.

## Members

- **NumEntries**
The number of interface stack row entries in the array.

- **Table**
An array of [**MIB\_IFSTACK\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ifstack-row) structures that contain interface stack row entries.

## Remarks

The relationship between the interfaces in the interface stack is that the interface with the index in the **HigherLayerInterfaceIndex** member of the MIB\_IFSTACK\_ROW structure is immediately above the interface with the index in the **LowerLayerInterfaceIndex** member of the MIB\_IFSTACK\_ROW structure.

The [**GetIfStackTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getifstacktable) function enumerates the network interface stack row entries on a local computer and returns this information in a MIB\_IFSTACK\_TABLE structure.

The MIB\_IFSTACK\_TABLE structure might contain padding for alignment between the **NumEntries** member and the first MIB\_IFSTACK\_ROW array entry in the **Table** member. Padding for alignment might also be present between the MIB\_IFSTACK\_ROW array entries in the **Table** member. Any access to a MIB\_IFSTACK\_ROW array entry should assume padding might exist.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**GetIfStackTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getifstacktable)

[**GetInvertedIfStackTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getinvertedifstacktable)

[**MIB\_IFSTACK\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ifstack-row)

[**MIB\_INVERTEDIFSTACK\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-invertedifstack-row)

[**MIB\_INVERTEDIFSTACK\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-invertedifstack-table)