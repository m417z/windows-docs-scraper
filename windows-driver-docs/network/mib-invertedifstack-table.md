# MIB\_INVERTEDIFSTACK\_TABLE structure

The MIB\_INVERTEDIFSTACK\_TABLE structure contains a table of inverted network interface stack row entries. This table specifies the relationship of the network interfaces on an interface stack in reverse order.

## Members

- **NumEntries**
The number of inverted interface stack row entries in the array.

- **Table**
An array of **MIB\_INVERTEDIFSTACK\_ROW** structures that contain inverted interface stack row entries.

## Remarks

The relationship between the interfaces in the interface stack is that the interface with the index in the **HigherLayerInterfaceIndex** member of the MIB\_INVERTEDIFSTACK\_ROW structure is immediately above the interface with the index in the **LowerLayerInterfaceIndex** member of the MIB\_INVERTEDIFSTACK\_ROW structure.

The [**GetInvertedIfStackTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getinvertedifstacktable) function enumerates the inverted network interface stack row entries on a local computer and returns this information in a MIB\_INVERTEDIFSTACK\_TABLE structure.

The MIB\_INVERTEDIFSTACK\_TABLE structure might contain padding for alignment between the **NumEntries** member and the first [**MIB\_INVERTEDIFSTACK\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-invertedifstack-row) array entry in the **Table** member. Padding for alignment might also be present between the MIB\_INVERTEDIFSTACK\_ROW array entries in the **Table** member. Any access to a MIB\_INVERTEDIFSTACK\_ROW array entry should assume padding might exist.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**GetIfStackTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getifstacktable)

[**GetInvertedIfStackTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getinvertedifstacktable)

[**MIB\_IFSTACK\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ifstack-row)

[**MIB\_IFSTACK\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ifstack-table)

[**MIB\_INVERTEDIFSTACK\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-invertedifstack-row)